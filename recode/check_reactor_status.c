#include <stdio.h>
#include <unistd.h>

static void encrypt_message(const char *message, char *encrypted_message)
{
    int res = 0;

    for (int ky = 0; message[ky]; ky++){
        if (ky % 2 == 1)
            res += message[ky] * 61043;
        if (ky % 2 == 0)
            res += message[ky];
    }
    if (res < 0)
        res *= -1;
    snprintf(encrypted_message, 50, "%d", res);
}

void check_reactor_status(void)
{
    printf("Starting reactor status check...\n");
    sleep(1);
    printf("Checking core temperature...\n");
    sleep(1);
    printf("Core temperature: Normal\n");
    sleep(1);
    printf("Checking coolant flow rate...\n");
    sleep(1);
    printf("Coolant flow rate: Stable\n");
    sleep(1);
    printf("Checking radiation levels...\n");
    sleep(2);
    printf("Radiation levels: Safe\n\n");

    printf("Encrypting critical reactor data...\n");
    const char *message = "ReactorStatusOK";
    char encrypted_message[50] = {0};
    encrypt_message(message, encrypted_message);
    sleep(1);
    printf("Encrypted message: %s\n\n", encrypted_message);

    printf("Reactor status: OK\n");
    printf("Reactor status check complete.\n\n");
}
