#include <unistd.h>

int main()
{
  int i = 0;

  while(i < 1) {
    usleep(3000);
  }

  return 0;
}
