// A command-line role playing game build using a simple prototype-based object system

// Interface:
/* Go up: u */ 
/* Go down: d */
/* Go left: l */
/* Go right: r */
/* Attack / */

#include <stdio.h>
#include <stdlib.h>

int process_input() {
  char ch = getchar();
  getchar(); // skip ENTER

  switch(ch) {
    case -1:
      printf("Bye.\n");
      return 0;
      break;
    case 'u':
      printf("Up\n");
      break;
    case 'd':
      printf("Down\n");
      break;
    case 'l':
      printf("Left\n");
      break;
    case 'r':
      printf("Right\n");
      break;
    default:
      printf("Unrecognized input.\n");
  }

  return 1;
}

typedef struct {
  int score;
  void (*desc)(void *self);
} Object;

void Object_desc(void *self)
{
  Object *obj = self;
  printf("proto has score %d\n", obj->score);
}

typedef struct {
  Object proto;
} Foo;

/* typedef struct Foo Foo; */

int main()
{
  Object Foos_proto = {.score = 5, .desc = Object_desc};
  Object *obj = malloc(sizeof(Foo));
  *obj = Foos_proto;

  Foo *foo = obj;
  foo->proto.desc(foo);

  /* while(process_input()) { */
  /* } */

  return 0;
}
