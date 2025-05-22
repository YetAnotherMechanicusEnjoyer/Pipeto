/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** send_status_report
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int hash(char *key, int len)
{
    int res = 0;

    for (int ky = 0; ky < len; ky++){
        if (ky % 2 == 1)
            res += key[ky] * 61043;
        if (ky % 2 == 0)
            res += key[ky];
    }
    if (res < 0)
        res *= -1;
    return res;
}

void send_status_report(void)
{
    FILE *file = fopen("Data/status_report.txt", "w");
    if (!file) {
        printf("Error: Unable to create a file in Data/, you must create a Data folder.\n");
        return;
    }
    const char *hostname = "localhost";
    const char *ip_address = "127.0.0.1";
    const char *process_info = "Process: pipeto (PID: 1234)";
    char report[256];
    snprintf(report, sizeof(report), "Hostname: %s\nIP Address: %s\n%s\n", hostname, ip_address, process_info);
    char encoded_report[512];
    snprintf(encoded_report, sizeof(encoded_report), "%i", hash(report, sizeof(report)));
    fprintf(file, "Encoded Status Report:\n%s\n", encoded_report);
    fclose(file);
    printf("Status report sent and saved to 'Data/status_report.txt'.\n");
}
