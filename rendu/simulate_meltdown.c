/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** simulate_meltdown
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static void print_reactor_status(int random_number,
    const char *reactor_status)
{
    printf("Reactor core temperature: %d\n", random_number);
    printf("Reactor core status: %s\n", reactor_status);
}

static void update_reactor_status(int random_number, char *reactor_status)
{
    if (random_number < 10) {
        printf("Meltdown simulated! Reactor core is overheating.\n");
        strcpy(reactor_status, "Reactor Overheating");
        return;
    }
    if (random_number < 20) {
        printf("Warning: Reactor core temperature rising.\n");
        strcpy(reactor_status, "Reactor Warning");
        return;
    }
    if (random_number < 50) {
        printf("Alert: Reactor core temperature stable.\n");
        strcpy(reactor_status, "Reactor Stable");
        return;
    }
    printf("Reactor core temperature normal.\n");
    strcpy(reactor_status, "Reactor Normal");
}

void simulate_meltdown(void)
{
    char reactor_status[32] = "Reactor Stable";
    int random_number = rand() % 100;

    printf("Generated random number: %d\n", random_number);
    update_reactor_status(random_number, reactor_status);
    print_reactor_status(random_number, reactor_status);
}
