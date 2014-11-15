// Variables

#include <stdio.h>

int main()
{
  int foo = 100;
  float bar = 3.45f;
  double baz = 12345.1234;
  char qux = 'G';
  char first_name[] = "Gaurav";
  char last_name[] = "Chande";

  printf("Integer %d\n", foo);
  printf("Float %f\n", bar);
  printf("Double %f\n", baz);
  printf("Char %c\n", qux);
  printf("String %s\n", first_name);
  printf("String %s\n", last_name);
  printf("Fullname %s %s\n", first_name, last_name);

  return 0;
}
