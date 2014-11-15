#include <stdio.h>

int main(int argc, char *argv[])
{
  char str[] = "abc";

  printf("str is %s\n", str);
  printf("size of str is %ld\n", sizeof(str));
  int foo = 5;
  str[0] = foo;
  printf("str is %d\n", str[1]);
  printf("size of foo is %ld\n", sizeof(foo));
  printf("size of str is %ld\n", sizeof(str));

  // print argv
  printf("first argument %s\n", argv[0]);

  // array of strings
  char *names[] = {"Gaurav", "Vinit", "Tarun", NULL};
  printf("size of names array is %ld\n", sizeof(names));

  int i=0;
  for(i=0; i<4; i++) {
    printf("name at %d is %s\n", i, names[i]);
  }

  printf("value of i after the loop %d\n", i);

  return 0;
}
