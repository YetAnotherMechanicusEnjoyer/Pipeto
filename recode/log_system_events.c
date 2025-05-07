/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** log_system_events
*/

#include <stdio.h>
#include <string.h>

void log_system_event()
{
    char command[100];
    char input[100];

    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%99s", command);
    FILE *log = fopen("Data/system.log", "a");
    if (!log) {
        printf("Error: Unable to open log file 'Data/system.log'.\n");
        return;
    }
    printf("Logging event: %s\n", input);
    fprintf(log, "EVENT: %s\n", input);
    fclose(log);
}