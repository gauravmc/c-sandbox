#ifndef _game_h
#define _game_h

#include "object.h"

typedef enum {N, E, W, S} Direction;

struct Room {
  Object proto;

  struct Room *north;
  struct Room *south;
  struct Room *east;
  struct Room *west;
};
typedef struct Room Room;

typedef struct {
  Object proto;
  Room *current_room;
  void (*move_player)(void *self, Direction direction);
} Game;

int Game_init(void *self);
void Game_move_player(void *self, Direction direction);
Game *Game_new();

#endif
