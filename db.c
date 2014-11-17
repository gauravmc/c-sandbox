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
#define MAX_LENGTH 50

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

struct Connection {
  FILE *file;
  struct Database *db;
};

struct Connection *Connection_open()
{
  struct Connection *conn = malloc(sizeof(struct Connection));
  if(!conn) die("Memory error");

  conn->db = malloc(sizeof(struct Database));
  conn->file = fopen("db.dat", "w");
  if(!conn->file) die("Failed to open the file");

  return conn;
}

void Database_write(struct Connection *conn)
{
  int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  if(rc != 1) die("Failed to write to database.");

  rc = fflush(conn->file);
  if(rc == -1) die("Cannot flush database.");
}

void Database_create(struct Connection *conn)
{
  int i;
  for(i = 0; i < MAX_ROWS; i++) {
    struct Record record = {.id = i+1, .set = 0};
    conn->db->rows[i] = record;
  }

  Database_write(conn);
  printf("Fresh database has been created\n");
}

void Database_set(struct Connection *conn, int id, const char* name, const char* email)
{
  struct Record *record = &conn->db->rows[id];
  strncpy(record->name, name, MAX_LENGTH);
  strncpy(record->email, email, MAX_LENGTH);
  record->set = 1;

  Database_write(conn);
}

void Database_destroy()
{
  remove("db.dat");
  printf("Database has been destroyed. To re-create, 'db create'\n");
}

void Connection_close(struct Connection *conn)
{
  if(conn) {
    if(conn->file) fclose(conn->file);
    if(conn->db) free(conn->db);
    free(conn);
  }
}

int main(int argc, char *argv[])
{
  if(argc < 2) die("Incorrect API call. API USAGE: db <action> [action params]");

  struct Connection *conn = Connection_open();

  int id = 0;
  if(argc > 2) {
    id = atoi(argv[2]);
    if(id >= MAX_ROWS) printf("Given id=%d is greater than total records.\n", id);
  }

  char *action = argv[1];

  if(!strcmp(action, "create")) {
    Database_create(conn);
  } else if(!strcmp(action, "set")) {
    if(argc != 5) die("Need id, name, email to set");
    Database_set(conn, id, argv[3], argv[4]);
  } else if(!strcmp(action, "destroy")) {
    Database_destroy();
  } else {
    printf("Action %s is invalid. Actions allowed: create, get, set, del and destroy\n", action);
  }

  Connection_close(conn);

  return 0;
}
