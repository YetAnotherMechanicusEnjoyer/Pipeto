#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

void activate_emergency_protocols(void)
{
    char init[100];

    printf("Enter emergency password: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;
    if (strlen(input) == 0) {
        printf("No password entered, emergency protocols not activated.\n");
        return;
    }
    if (strcmp(input, ADMIN_MDP) == 0) {
        printf("{Emergency protocols activated, you are now admin !}\n");
        IS_ADMIN = true;
    }
    return;
}
