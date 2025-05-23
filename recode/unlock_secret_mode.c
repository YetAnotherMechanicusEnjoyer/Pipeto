/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** unlock_secret_mode - SECURED VERSION
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pipeto.h"

void unlock_secret_mode(void)
{
    if (!IS_ADMIN) {
        printf("Access denied. You do not have the required privileges.\n");
        return;
    }
    printf("Secret mode unlocked! Welcome, admin.\n");
    printf("{ADMIN4242}\n");
}
