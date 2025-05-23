/*
** EPITECH PROJECT, 2025
** ref-G-SEC-210-project
** File description:
** load_config - SECURED VERSION
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

static int parse_config_key_value(const char *line, char *key, char *value)
{
    if (sscanf(line, "%63[^=]=%127s", key, value) != 2)
        return 0;
    return 1;
}

static int check_config_file(const char *filename, struct stat *file_stat)
{
    if (stat(filename, file_stat) != 0) {
        printf("Error: Configuration file not found: %s\n", strerror(errno));
        return -1;
    }
    if (file_stat->st_size > MAX_CONFIG_SIZE) {
        printf("Error: Configuration file too large (max %d bytes)\n",
            MAX_CONFIG_SIZE);
        return -1;
    }
    if (file_stat->st_size == 0) {
        printf("Error: Configuration file is empty\n");
        return -1;
    }
    if ((file_stat->st_mode & S_IRWXO) || (file_stat->st_mode & S_IRWXG))
        printf("Warning: Configuration file has unsafe permissions\n");
    return 0;
}

static int open_config_file(const char *filename, struct stat *file_stat)
{
    int fd;

    if (check_config_file(filename, file_stat) != 0)
        return -1;
    fd = open(filename, O_RDONLY | O_NOFOLLOW);
    if (fd < 0) {
        printf("Error: Unable to open configuration file: %s\n",
            strerror(errno));
        return -1;
    }
    return fd;
}

static int allocate_config_buffer(char **buffer, off_t size)
{
    *buffer = (char *)calloc(size + 1, sizeof(char));
    if (!*buffer) {
        printf("Error: Memory allocation failed\n");
        return -1;
    }
    return 0;
}

static int read_config_file_content(int fd, char **buffer,
    struct stat *file_stat)
{
    ssize_t bytes_read;

    if (allocate_config_buffer(buffer, file_stat->st_size) != 0) {
        close(fd);
        return -1;
    }
    bytes_read = read(fd, *buffer, file_stat->st_size);
    if (bytes_read < 0) {
        printf("Error: Failed to read configuration file: %s\n",
            strerror(errno));
        free(*buffer);
        close(fd);
        return -1;
    }
    (*buffer)[bytes_read] = '\0';
    close(fd);
    return 0;
}

static int read_config_file(char **buffer, struct stat *file_stat)
{
    int fd;

    fd = open_config_file(CONFIG_FILE, file_stat);
    if (fd < 0)
        return -1;
    return read_config_file_content(fd, buffer, file_stat);
}

static int parse_config_line_from_buffer(const char *line,
    reactor_config_t *config, int line_count)
{
    if (strlen(line) > 0 && line[0] != '#' && line[0] != ';') {
        if (!parse_config_line(line, config))
            printf("Warning: Invalid configuration at line %d\n", line_count);
    }
    return 0;
}

static int parse_config_buffer(const char *buffer, reactor_config_t *config)
{
    char *buf_copy = strdup(buffer);
    char *line = strtok(buf_copy, "\n");
    int line_count = 0;
    int valid = 0;

    if (!buf_copy)
        return -1;
    while (line != NULL && line_count < 100) {
        line_count++;
        parse_config_line_from_buffer(line, config, line_count);
        line = strtok(NULL, "\n");
    }
    if (strlen(config->reactor_id) > 0)
        valid = 1;
    free(buf_copy);
    return valid;
}

static int load_config_from_file(reactor_config_t *config)
{
    struct stat file_stat;
    char *buffer = NULL;
    int valid = 0;

    printf("Loading configuration file from %s\n", CONFIG_FILE);
    if (read_config_file(&buffer, &file_stat) != 0)
        return 0;
    valid = parse_config_buffer(buffer, config);
    memset(buffer, 0, file_stat.st_size + 1);
    free(buffer);
    return valid;
}

void load_config(void)
{
    reactor_config_t config = {0};

    if (load_config_from_file(&config)) {
        config.is_valid = 1;
        printf("Configuration loaded successfully:\n");
        printf("  Reactor ID: %s\n", config.reactor_id);
        printf("  Power Level: %d MW\n", config.power_level);
        printf("  Temperature: %d°C\n", config.temperature);
    } else
        printf("Error: Invalid or incomplete configuration\n");
}
