#ifndef _game_h
#define _game_h

#include "object.h"

typedef enum {N, E, W, S} Direction;

typedef struct {
  Object proto;
  void (*move_player)();
} Game;

void Game_move_player(Direction direction);
Game *Game_new();

#endif
