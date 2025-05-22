/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** read_turbine_config.c
*/

#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static bool is_valid_filename(const char *filename)
{
    if (strstr(filename, "..") != NULL) {
        puts("Error: Invalid file name.");
        return false;
    }
    return true;
}

static void process_file(const char *filepath)
{
    char buffer[256];
    FILE *file = fopen(filepath, "r");

    if (file == NULL) {
        printf("Error: Unable to open file: %s\n", filepath);
        return;
    }
    printf("Reading configuration file: %s\n", filepath);
    while (fgets(buffer, sizeof(buffer), file) != NULL)
        printf("%s", buffer);
    fclose(file);
}

void read_turbine_config(void)
{
    char filename[136];
    char filepath[256];
    size_t len;

    printf("Enter the configuration file name: ");
    fgets(filename, sizeof(filename), stdin);
    len = strcspn(filename, "\n");
    filename[len] = '\0';
    if (!is_valid_filename(filename))
        return;
    snprintf(filepath, sizeof(filepath), "Data/%s", filename);
    process_file(filepath);
}
