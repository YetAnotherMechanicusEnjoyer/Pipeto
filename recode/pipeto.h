/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** header for pipeto - UPDATED VERSION
*/

#ifndef PIPETO_H_
    #define PIPETO_H_

    #include <stdbool.h>

extern bool IS_ADMIN;
    #define UNUSED __attribute__((unused))
    #define MAX_FUEL_RODS 10
    #define INPUT_BUFFER_SIZE 32
    #define CONFIG_FILE "./config.ini"
    #define MAX_CONFIG_SIZE 4096
    #define MAX_LINE_LENGTH 256
    #define MAX_ROTATIONS 15
    #define INPUT_SIZE 32
    #define BUFFER_SIZE 32
    #define BASE_TEMP 20
    #define MIN_SAFE_TEMP -50
    #define MAX_SAFE_TEMP 100

int my_console(void);

// Commandes principales
void init_reactor(void);
void check_reactor_status(void);
void activate_emergency_protocols(void);
void simulate_meltdown(void);
void check_cooling_pressure(void);
void send_status_report(void);
void monitor_radiation_levels(void);
void set_reactor_power(void);
void run_diagnostic(void);
void enable_remote_access(void);
void quit(void);
void help(void);
void load_fuel_rods(void);
void log_system_event(void);
void unlock_secret_mode(void);
void load_config(void);
void show_history(char *input);
void configure_cooling_system(void);
void trigger_emergency_shutdown(void);

// Nouvelles fonctions pour la sécurité
void set_admin_authenticated(bool authenticated);

// Fonction pour vérifier les commandes de la librairie
void check_pepito_lib(char *input);

int parse_config_line(const char *line, reactor_config_t *config);

enum commands {
    INIT_REACTOR,
    CHECK_REACTOR_STATUS,
    ACTIVATE_EMERGENCY_PROTOCOLS,
    SIMULATE_MELTDOWN,
    CHECK_COOLING_PRESSURE,
    SEND_STATUS_REPORT,
    MONITOR_RADIATION_LEVELS,
    SET_REACTOR_POWER,
    RUN_DIAGNOSTIC,
    ENABLE_REMOTE_ACCESS,
    QUIT,
    HELP,
    LOAD_FUEL_RODS,
    LOG_SYSTEM_EVENT,
    UNLOCK_SECRET_MODE,
    LOAD_CONFIG,
    HISTORY,
    CONFIGURE_COOLING_SYSTEM,
    TRIGGER_EMERGENCY_SHUTDOWN,
    COMMAND_COUNT,
};

extern const char *command_strings[];

enum commands_lib {
    INIT_STEAM_TURBINE,
    READ_TURBINE_CONFIG,
    TURINE_REMOTE_ACCESS,
    RUN_TURBINE,
    TURBINE_TEMPERATURE,
    COMMAND_COUNT_LIB
};

typedef struct {
    char reactor_id[64];
    int power_level;
    int temperature;
    int is_valid;
} reactor_config_t;

#endif /* !PIPETO_H_ */
