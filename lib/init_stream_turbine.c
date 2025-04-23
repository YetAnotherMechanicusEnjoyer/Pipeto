/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** init_stream_turbine.c
*/

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void init_steam_turbine(void)
{
  time_t tVar1;

  tVar1 = time((time_t *)0x0);
  srand((uint)tVar1);
  puts("Start of the steam turbine initialized");
  sleep(1);
  puts("Steam turbine status: OK");
  sleep(2);
  puts("Steam valves status: OPEN");
  sleep(1);
  puts("Pressurized water tank: OK");
  sleep(1);
  puts("Pressurized water valves: READY");
  sleep(1);
  puts("Steam turbine rotor status: OK");
  sleep(2);
  puts("Starting steam turbine rotor...");
  sleep(1);
  puts("Steam turbine rotor status: OK");
  sleep(1);
  puts("Steam turbine rotor current speed: 1000 r/min");
  sleep(1);
  puts("Reactor initialization complete.");
  sleep(1);
  return;
}
