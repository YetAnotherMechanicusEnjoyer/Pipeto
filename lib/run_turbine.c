/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** run_turbine.c
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void get_turbine_input(unsigned int *local_10)
{
    char local_98[136];
    size_t sVar2;

    printf("Enter the number of rotation that the turbine will do (between 0 and 15): ");
    fgets(local_98, 0x80, stdin);
    sVar2 = strcspn(local_98, "\n");
    local_98[sVar2] = '\0';
    *local_10 = atoi(local_98);
}


void run_turbine_loop(unsigned int local_10, unsigned int local_c)
{
    int iVar1;

    for (; local_c != local_10; local_c = local_c + 1) {
        if (0xf < local_c)
            puts("{ERR0R TURB1NE CAN\'T ST0P}");
        printf("Turbine is running... %lu/%lu\n", (unsigned long)(local_c + 1), (unsigned long)local_10);
        iVar1 = rand();
        sleep(iVar1 % 3 + 1);
    }
    puts("Turbine has stopped.");
}

void run_turbine(void)
{
    unsigned int local_10;
    unsigned int local_c = 0;

    get_turbine_input(&local_10);
    if ((local_10 == 0) || ((int)local_10 < 0x10)) {
        run_turbine_loop(local_10, local_c);
    } else {
        puts("Invalid number of rotations.");
    }
    return;
}