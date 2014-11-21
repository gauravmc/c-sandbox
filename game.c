// A command-line role playing game build using a simple prototype-based object system

// Interface:
/* Go up: u */ 
/* Go down: d */
/* Go left: l */
/* Go right: r */
/* Attack / */

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

Object RoomProto;

int Game_init(void *self)
{
  Game *game = self;
  Room *reception = NEW(Room, "You're at the reception");
  Room *hats_room = NEW(Room, "You're in a room full of crazy, and some scary hats");

  reception->north = hats_room;
  game->current_room = reception;

  return 1;
}

void Game_move_player(void *self, Direction direction)
{
  Game *game = self;

  if(direction == N) {
    if (game->current_room->north) {
      game->current_room = game->current_room->north;
      game->current_room->proto.describe(game->current_room);
    } else {
      printf("Can't go that way\n");
    }
  }
}

Object GameProto = {
  .init = Game_init
};

Game *Game_new()
{
  Game *game = NEW(Game, "Welcome to the dungeon!");
  game->move_player = Game_move_player;
  return game;
}

int process_input(Game *game) {
  char ch = getchar();
  if (ch == '\n') return 1;

  switch(ch) {
    case -1:
      printf("Bye.\n");
      return 0;
      break;
    case 'n':
      game->move_player(game, N);
      break;
    case 's':
      printf("South\n");
      break;
    case 'w':
      printf("West\n");
      break;
    case 'e':
      printf("East\n");
      break;
    default:
      printf("Unrecognized input.\n");
  }

  return 1;
}

int main()
{
  Game *game = Game_new();
  game->proto.describe(game);

  while(process_input(game)) {
  }

  return 0;
}
