#ifndef _object_h
#define _object_h

typedef struct {
  char *description;
  int (*init)(void *self);
  void (*describe)(void *self);
  void (*destroy)(void *self);
} Object;

int Object_init(void *self);
void Object_describe(void *self);
void Object_destroy(void *self);
void *Object_new(size_t size, Object proto, char *desc);

#define NEW(O, D) Object_new(sizeof(O), O##Proto, D)

#endif
