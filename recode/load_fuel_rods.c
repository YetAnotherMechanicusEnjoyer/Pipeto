/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** load_fuel_rods - SECURED VERSION
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <errno.h>

static int is_valid_number(const char *input, long *parsed_value)
{
    char *endptr;

    if (strlen(input) == 0) {
        printf("Error: No input provided.\n");
        return 0;
    }
    errno = 0;
    *parsed_value = strtol(input, &endptr, 10);
    if (errno == ERANGE || *parsed_value > INT_MAX ||
        *parsed_value < INT_MIN) {
        printf("Error: Number out of range.\n");
        return 0;
    }
    if (endptr == input || *endptr != '\0') {
        printf("Error: Invalid number format.\n");
        return 0;
    }
    return 1;
}

static int parse_num_fuel_rods(const char *input)
{
    long parsed_value;

    if (!is_valid_number(input, &parsed_value))
        return -1;
    if ((int)parsed_value < 0) {
        printf("Error: Number of fuel rods cannot be negative.\n");
        return -1;
    }
    if ((int)parsed_value > MAX_FUEL_RODS) {
        printf("Error: Too many fuel rods! Maximum allowed is %d.\n",
            MAX_FUEL_RODS);
        return -1;
    }
    return (int)parsed_value;
}

static int get_num_fuel_rods(void)
{
    char input[INPUT_BUFFER_SIZE];

    printf("Enter the number of fuel rods to load (max %d): ", MAX_FUEL_RODS);
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Error: Failed to read input.\n");
        return -1;
    }
    input[strcspn(input, "\n")] = '\0';
    return parse_num_fuel_rods(input);
}

static void load_rods(int num_rods, int *fuel_rods)
{
    printf("Loading %d fuel rod%s...\n", num_rods, num_rods > 1 ? "s" : "");
    for (int i = 0; i < num_rods; i++) {
        fuel_rods[i] = i + 1;
        printf("Fuel rod %d loaded.\n", fuel_rods[i]);
        sleep(1);
    }
    printf("All fuel rods loaded successfully.\n");
}

void load_fuel_rods(void)
{
    int fuel_rods[MAX_FUEL_RODS];
    int num_rods;

    printf("Loading fuel rods...\n");
    num_rods = get_num_fuel_rods();
    if (num_rods < 0)
        return;
    if (num_rods == 0) {
        printf("No fuel rods to load.\n");
        return;
    }
    load_rods(num_rods, fuel_rods);
    memset(fuel_rods, 0, sizeof(fuel_rods));
}
