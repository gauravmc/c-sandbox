#include <stdio.h>

int main()
{
  char str[] = "abc";

  printf("str is %s\n", str);
  printf("size of str is %ld\n", sizeof(str));
  int foo = 5;
  str[0] = foo;
  printf("str is %d\n", str[1]);
  printf("size of foo is %ld\n", sizeof(foo));
  printf("size of str is %ld\n", sizeof(str));

  return 0;
}
