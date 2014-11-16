#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// API
/* db create */
/* db set 1 Gaurav gmail@gauravchande.com */
/* db get 1 */
/* db del 1 */
/* db destroy */

void die(char *message)
{
  printf("Error: %s\n", message);
  exit(1);
}

int main(int argc, char *argv[])
{
  if(argc < 2) die("Incorrect API call. API USAGE: db <action> [action params]");
  char *action = argv[1];

  if(!strcmp(action, "create")) {
    die("'create' action not implemented yet");
  } else {
    printf("Action %s is invalid. Actions allowed: create, get, set, del and destroy\n", action);
  }

  return 0;
}
