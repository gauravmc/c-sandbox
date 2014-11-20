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


int main()
{
  while(process_input()) {
  }

  return 0;
}
