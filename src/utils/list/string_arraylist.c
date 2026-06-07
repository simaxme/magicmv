#include <stdio.h>
#include <stdlib.h>
#include "../list.h"

struct StringArrayList list_create() {
  struct StringArrayList list;

  list.capacity = 8;
  list.length = 0;
  list.ptr = malloc((list.capacity+1) * sizeof(char*));

  if (list.ptr == NULL) {
    fprintf(stderr, "Error allocating memory to create a new string array list\n");
    exit(EXIT_FAILURE);
  }

  return list;
}

void list_push(struct StringArrayList *list, char *data) {
  if (list->length >= list->capacity) {
    list->capacity *= 2;
    // We always allocate at least one more to have a list end marker
    list->ptr = realloc(list->ptr, (list->capacity+1) * sizeof(char*));

    if (list->ptr == NULL) {
      fprintf(stderr, "Unable to allocate more memory to push into list\n");
      exit(EXIT_FAILURE);
      return;
    }
  }

  list->ptr[list->length] = data;
  list->ptr[list->length+1] = NULL;
  list->length++;
}

inline char* list_get(struct StringArrayList *list, int index) {
  if (index >= list->length) {
    return NULL;
  }
  return list->ptr[index];
}

void list_concat(struct StringArrayList *list, struct StringArrayList *list_to_append) {
  char** ptr = list_to_append->ptr;

  while (*ptr != NULL) {
    list_push(list, *ptr);
    ptr++;
  }

  free(list_to_append->ptr);
}

void list_free(struct StringArrayList *list) {
  char** ptr = list->ptr;

  while (*ptr != NULL) {
    free(*ptr);
    ptr++;
  }

  free(list->ptr);
}
