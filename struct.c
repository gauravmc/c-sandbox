#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  char *profession;
};

struct Foo {
  int bar;
};

struct Person* Person_create(char *name, int age, char *profession)
{
  struct Person *person = malloc(sizeof(struct Person));
  person->name = strdup(name);
  person->age = age;
  person->profession = strdup(profession);

  return person;
}

void Person_print(struct Person *person)
{
  printf("Name is %s\n", person->name);
  printf("Age is %d\n", person->age);
  printf("Profession is %s\n", person->profession);
}

void Person_destroy(struct Person *person)
{
  assert(person != NULL);

  char *name = strdup(person->name);
  free(person->name);
  free(person->profession);
  free(person);

  printf("%s was freed from memory\n", name);
}

int main()
{
  struct Person *gaurav = Person_create("Gaurav", 25, "programmer");
  struct Person *vinit = Person_create("Vinit", 25, "engineer");

  printf("gaurav is located at %p\n", gaurav);
  printf("vinit is located at %p\n", vinit);

  Person_print(gaurav);
  Person_print(vinit);

  Person_destroy(gaurav);
  Person_destroy(vinit);

  struct Foo foob;

  foob.bar = 42;
  printf("variable bar of Foo is %d\n", foob.bar);

  return 0;
}
