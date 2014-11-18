#include <stdio.h>

typedef int (*math_cb)(int a, int b);

int add(int a, int b)
{
  printf("foo");
  return a + b;
}

int sub(int a, int b)
{
  return a - b;
}

void print_func(math_cb math)
{
  int a = 5;
  int b = 4;

  math(a, b);

  unsigned char *data = (unsigned char *) math;

  printf("raw assembler byte code:\n");
  int i;
  for(i=0;i<10;i++) {
    printf("%02x:", data[i]);
  }
  printf("\n");
}

int main()
{
  print_func(add);
  print_func(sub);

  return 0;
}
