#include <stdio.h>

int main()
{
  int nums[] = {0, 1, 2, 3, 4};
  char first_name[] = "Gaurav";
  char full_name[] = {'G', 'a', 'u', 'r', 'a', 'v', ' ', 'C', 'h', 'a', 'n', 'd', 'e'};

  printf("Size of an int: %ld\n", sizeof(int));
  printf("Size of nums: %ld\n", sizeof(nums));
  printf("Number of ints in nums array: %ld\n", sizeof(nums)/sizeof(int));
  nums[4] = 50;
  printf("Last number in nums is %d\n", nums[4]);
  printf("Size of an char: %ld\n", sizeof(char));
  printf("Size of first_name: %ld\n", sizeof(first_name));
  printf("Number of chars in first_name: %ld\n", sizeof(first_name)/sizeof(char));
  printf("Size of full_name: %ld\n", sizeof(full_name));
  printf("Number of chars in full_name array: %ld\n", sizeof(full_name)/sizeof(char));

  first_name[0] = 'F';
  printf("First name is %s\n", first_name);
  printf("The last extra byte in first_name is %c\n", first_name[6]);

  return 0;
}
