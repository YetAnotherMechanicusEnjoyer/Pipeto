/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** turbine_remote_access - SECURED VERSION
*/

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>

static int create_secure_temp(char *path, size_t size)
{
    int fd;

    snprintf(path, size, "Data/remote_access_XXXXXX");
    fd = mkstemp(path);
    if (fd == -1) {
        puts("Error: Unable to create temporary file.");
        return -1;
    }
    if (fchmod(fd, 0600) != 0) {
        close(fd);
        unlink(path);
        return -1;
    }
    return fd;
}

static int write_and_lock(int fd)
{
    const char *data = "{ACCESS_GRANTED}";

    if (flock(fd, LOCK_EX) != 0)
        return -1;
    if (write(fd, data, strlen(data)) != (ssize_t)strlen(data))
        return -1;
    if (fsync(fd) != 0)
        return -1;
    return 0;
}

static void process_access(const char *path)
{
    int fd = open(path, O_RDONLY);
    char buffer[32];
    ssize_t bytes = read(fd, buffer, sizeof(buffer) - 1);

    puts("Enabling remote access...");
    sleep(5);
    if (fd == -1) {
        puts("Error: File was tampered with or deleted.");
        return;
    }
    if (bytes > 0) {
        buffer[bytes] = '\0';
        printf("Remote access status: %s\n", buffer);
    }
    close(fd);
}

void turbine_remote_access(void)
{
    char temp_path[64];
    int fd = create_secure_temp(temp_path, sizeof(temp_path));

    if (fd == -1)
        return;
    printf("Temporary file created: %s\n", temp_path);
    if (write_and_lock(fd) != 0) {
        close(fd);
        unlink(temp_path);
        return;
    }
    close(fd);
    process_access(temp_path);
    unlink(temp_path);
}
