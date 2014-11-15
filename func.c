#include <stdio.h>
#include <ctype.h>

void print_letters(int argc, char *argv[])
{
  int i = 1;
  for(i = 1; i < argc; i++) {
    printf("word is %s\n", argv[i]);
  }
}

int main(int argc, char *argv[])
{
  print_letters(argc, argv);

  return 0;
}
