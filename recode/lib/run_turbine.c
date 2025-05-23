/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** run_turbine - SECURED VERSION
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

static int get_valid_input(void)
{
    char buffer[INPUT_SIZE];
    char *endptr;
    long value;

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        return -1;
    buffer[strcspn(buffer, "\n")] = '\0';
    errno = 0;
    value = strtol(buffer, &endptr, 10);
    if (errno != 0 || endptr == buffer || *endptr != '\0')
        return -1;
    if (value < 0 || value > MAX_ROTATIONS)
        return -1;
    return (int)value;
}

static void run_rotation_loop(int rotations)
{
    for (int i = 0; i < rotations; i++) {
        printf("Turbine is running... %d/%d\n", i + 1, rotations);
        sleep((rand() % 3) + 1);
    }
    puts("Turbine has stopped.");
}

void run_turbine(void)
{
    int rotations;

    printf("Enter the number of rotations (0-%d): ", MAX_ROTATIONS);
    rotations = get_valid_input();
    if (rotations == -1) {
        puts("Invalid input. Please enter a number between 0 and 15.");
        return;
    }
    if (rotations == 0) {
        puts("No rotations requested.");
        return;
    }
    run_rotation_loop(rotations);
}
