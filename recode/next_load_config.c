/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** next_load_config.c
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>

static int set_config_value(const char *key, const char *value,
    reactor_config_t *config)
{
    if (strcmp(key, "reactor_id") == 0) {
        strncpy(config->reactor_id, value, sizeof(config->reactor_id) - 1);
        config->reactor_id[sizeof(config->reactor_id) - 1] = '\0';
        return 1;
    }
    if (strcmp(key, "power_level") == 0) {
        config->power_level = atoi(value);
        if (config->power_level < 0 || config->power_level > 1000)
            return 0;
        return 1;
    }
    if (strcmp(key, "temperature") == 0) {
        config->temperature = atoi(value);
        if (config->temperature < -273 || config->temperature > 5000)
            return 0;
        return 1;
    }
    return 1;
}

int parse_config_line(const char *line, reactor_config_t *config)
{
    char key[64];
    char value[128];
    char *key_trimmed = key;

    if (!parse_config_key_value(line, key, value))
        return 0;
    while (*key_trimmed == ' ' || *key_trimmed == '\t')
        key_trimmed++;
    return set_config_value(key_trimmed, value, config);
}
