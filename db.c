// A simple file-based database

// API
/* db create */
/* db set 1 Gaurav gmail@gauravchande.com */
/* db get 1 */
/* db del 1 */
/* db destroy */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_LENGTH 512

void die(char *message)
{
  printf("Error: %s\n", message);
  exit(1);
}

struct Record {
  int id;
  int set;
  char name[MAX_LENGTH];
  char email[MAX_LENGTH];
};

struct Database {
  struct Record rows[MAX_ROWS];
};

void Database_create()
{
  struct Database *db = malloc(sizeof(struct Database));
  int i;
  for(i = 0; i < MAX_ROWS; i++) {
    struct Record record = {.id = i+1, .set = 0};
    db->rows[i] = record;
  }

  FILE *file;
  file = fopen("db.dat", "w");
  if(!file) die("Failed to open the file");

  int rc = fwrite(db, sizeof(struct Database), 1, file);
  if(rc != 1) die("Failed to write database.");

  rc = fflush(file);
  if(rc == -1) die("Cannot flush database.");

  printf("Fresh database has been created\n");
}

void Database_destroy()
{
  remove("db.dat");
  printf("Database has been destroyed. To re-create, 'db create'\n");
}

int main(int argc, char *argv[])
{
  if(argc < 2) die("Incorrect API call. API USAGE: db <action> [action params]");
  char *action = argv[1];

  if(!strcmp(action, "create")) {
    Database_create();
  } else if(!strcmp(action, "destroy")) {
    Database_destroy();
  } else {
    printf("Action %s is invalid. Actions allowed: create, get, set, del and destroy\n", action);
  }

  return 0;
}
