/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** __do_global_dtors_aux.c
*/

void __do_global_dtors_aux(void)
{
  undefined8 extraout_RDX;
  
  if (completed.0 != '\0') {
    return;
  }
  __cxa_finalize(__dso_handle);
  deregister_tm_clones(extraout_RDX,0x101228);
  completed.0 = 1;
  return;
}