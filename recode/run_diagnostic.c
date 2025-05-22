/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** run_diagnostic
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void print_diagnostic_result(int *data, char *sensitive_info)
{
    if (data == NULL)
        printf("Error: Diagnostic data is unavailable (NULL pointer).\n");
    else if (data == (int *)sensitive_info)
        printf("Diagnostic result: %s\n", (char *)data);
    else
        printf("Diagnostic result: Code %d\n", *data);
}

static int *prepare_diagnostic_data(char *input, char *sensitive_info, int *diagnostic_code)
{
    int *data = NULL;

    if (strcmp(input, "debug") == 0)
        data = (int *)sensitive_info;
    else if (strcmp(input, "advanced") == 0) {
        *diagnostic_code = rand() % 1000;
        data = diagnostic_code;
    }
    return data;
}

void run_diagnostic()
{
    int *data = NULL;
    char input[32];
    char sensitive_info[64] = "{SECRET DIAGNOSTIC KEY}";
    int diagnostic_code = 0;

    printf("Enter diagnostic mode (normal/debug/advanced): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    data = prepare_diagnostic_data(input, sensitive_info, &diagnostic_code);
    printf("Running diagnostic...\n");
    sleep(1);
    print_diagnostic_result(data, sensitive_info);
    printf("Performing system health check...\n");
    sleep(1);
    printf("System health: OK\n");
    printf("Diagnostic complete.\n");
}
