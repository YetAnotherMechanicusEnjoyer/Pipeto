/*
** EPITECH PROJECT, 2024
** pipeto
** File description:
** run_turbine_remote_access.c
*/

void turbine_remote_access(void)
{
  size_t __n;
  undefined8 local_48;
  undefined8 local_40;
  undefined local_38;
  undefined8 local_28;
  undefined8 local_20;
  undefined8 local_18;
  undefined local_10;
  int local_c;
  
  local_28 = 0x6d65722f61746144;
  local_20 = 0x656363615f65746f;
  local_18 = 0x5858585858587373;
  local_10 = 0;
  local_c = mkstemp((char *)&local_28);
  if (local_c == -1) {
    puts("Error: Unable to create temporary file.");
  }
  else {
    printf("Temporary file created: %s\n",&local_28);
    local_48 = 0x5f5353454343417b;
    local_40 = 0x7d4445544e415247;
    local_38 = 0;
    __n = strlen((char *)&local_48);
    write(local_c,&local_48,__n);
    close(local_c);
    puts("Enabling remote access...");
    sleep(5);
    local_c = open((char *)&local_28,0);
    if (local_c == -1) {
      puts("Error: Temporary file was tampered with or deleted.");
    }
    else {
      unlink((char *)&local_28);
    }
  }
  return;
}