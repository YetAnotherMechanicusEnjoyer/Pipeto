/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** run_turbine_remote_access.c
*/

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void create_temp_file(char *temp_file_path, int *file_descriptor)
{
    strncpy(temp_file_path, "Data/remote_accessXXXXXX", 0x19);
    *file_descriptor = mkstemp(temp_file_path);
    if (*file_descriptor == -1) {
        puts("Error: Unable to create temporary file.");
    } else {
        printf("Temporary file created: %s\n", temp_file_path);
    }
}

void turbine_remote_access(void)
{
    size_t __n;
    char local_48[32];
    char local_28[28];
    int local_c;

    create_temp_file(local_28, &local_c);
    if (local_c == -1)
        return;
    strncpy(local_48, "{ACCESS_GRANTED}", 0x11);
    __n = strlen(local_48);
    write(local_c, local_48, __n);
    close(local_c);
    puts("Enabling remote access...");
    sleep(5);
    local_c = open(local_28, 0);
    if (local_c == -1) {
        puts("Error: Temporary file was tampered with or deleted.");
        return;
    }
    unlink(local_28);
}