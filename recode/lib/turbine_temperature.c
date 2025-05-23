/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** turbine_temperature - SECURED VERSION
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

static long parse_temperature(const char *input)
{
    char *endptr;
    long value;

    errno = 0;
    value = strtol(input, &endptr, 10);
    if (errno == ERANGE)
        return LONG_MAX;
    if (endptr == input || *endptr != '\0')
        return LONG_MAX;
    return value;
}

static int check_safe_range(long change, int base)
{
    if (change > (MAX_SAFE_TEMP - base))
        return 0;
    if (change < (MIN_SAFE_TEMP - base))
        return 0;
    return 1;
}

static void display_temperature(long change, int base)
{
    long new_temp = base + change;

    printf("Current turbine temperature: %d°C\n", base);
    if (change < 0)
        printf("Temperature decreasing to: %ld°C\n", new_temp);
    else if (change > 0)
        printf("Temperature increasing to: %ld°C\n", new_temp);
    else
        printf("Temperature remains stable.\n");
}

void turbine_temperature(void)
{
    char buffer[BUFFER_SIZE];
    long temp_change;

    printf("Enter temperature change in degrees: ");
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        puts("Error reading input.");
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
    temp_change = parse_temperature(buffer);
    if (temp_change == LONG_MAX) {
        puts("Invalid temperature value.");
        return;
    }
    if (!check_safe_range(temp_change, BASE_TEMP)) {
        puts("Temperature change out of safe range!");
        puts("Emergency shutdown initiated.");
        return;
    }
    display_temperature(temp_change, BASE_TEMP);
}
