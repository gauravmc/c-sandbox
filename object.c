#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"

int Object_init(void *self)
{
  return 1;
}

void Object_describe(void *self)
{
  Object *obj = self;
  printf("%s \n", obj->description);
}

void Object_destroy(void *self)
{
  Object *obj = self;
  free(obj->description);
  free(obj);
}

void *Object_new(size_t size, Object proto, char *desc)
{
  if(!proto.init) proto.init = Object_init;
  if(!proto.describe) proto.describe = Object_describe;
  if(!proto.destroy) proto.destroy = Object_destroy;
  proto.description = strdup(desc);

  Object *obj = malloc(size);
  *obj = proto;

  if(obj->init(obj)) {
    return obj;
  } else {
    obj->destroy(obj);
    return NULL;
  }
}
