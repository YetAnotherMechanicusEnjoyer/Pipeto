/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** turbine_temperature.c
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_temperature_input(char *buffer, size_t size)
{
    printf("Enter the number of degrees you want to increase or decrease the turbine temperature : ");
    fgets(buffer, size, stdin);
    size_t sVar1 = strcspn(buffer, "\n");
    buffer[sVar1] = '\0';
}

void process_temperature_change(int local_c)
{
    printf("Turbine temperature is %d degrees.\n", 0x14);
    if (local_c < 0)
        printf("Turbine temperature is decreasing : %lu\n", (unsigned long)(local_c + 0x14));
    else if (0 < local_c)
        printf("Turbine temperature is increasing : %lu\n", (unsigned long)(local_c + 0x14));
}

void turbine_temperature(void)
{
    char local_98[140];
    int local_c;

    get_temperature_input(local_98, sizeof(local_98));
    long long lVar2 = strtoll(local_98, NULL, 10);
    local_c = (int)lVar2;
    if ((local_c != 0x7ffffffe) && (local_c != -0x7fffffff)) {
        process_temperature_change(local_c);
        return;
    }
    puts("Turbine temperature is too unstable.");
    puts("{ERR0R TURBINE WILL EXPLODE}");
    exit(1);
}
