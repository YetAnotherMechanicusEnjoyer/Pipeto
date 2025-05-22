/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** set_reactor_power
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

static int fail_reactor_power(long long input_power, int new_power)
{
    if (input_power > INT_MAX - 1000) {
        printf("\nReactor power adjustment may be incorrect.\n");
        printf("Reactor systems are behaving erratically!\n");
        printf("Reactor core temperature rising uncontrollably...\n");
        printf("{12EXPLOSION34}\n");
        printf("Emergency shutdown initiated!\n\n");
        exit(1);
    }
    new_power = input_power + 1000;
    if (new_power < 0) {
        printf("Reactor power set to an invalid value: %d\n", new_power);
        printf("Reactor core meltdown imminent!\n");
    } else {
        printf("Reactor power set to: %d\n", new_power);
        printf("Reactor operating within safe parameters.\n");
    }
    return 0;
}

void set_reactor_power()
{
    char power[11];
    long long input_power;
    int new_power;

    printf("Enter reactor power level: ");
    fgets(power, sizeof(power), stdin);
    input_power = atoi(power);
    power[strcspn(power, "\n")] = 0;
    if (input_power > INT_MAX - 1000 || input_power < 0) {
        printf("Attention, la valeur max du int approche !\n");
        return;
    }
    fail_reactor_power(input_power, new_power);
}

int main(int argc, char *argv[])
{
  set_reactor_power();
  return EXIT_SUCCESS;
}
