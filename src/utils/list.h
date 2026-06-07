struct StringArrayList {
  int capacity;
  int length;
  char** ptr;
};

void list_push(struct StringArrayList *list, char* data);
void list_concat(struct StringArrayList *list, struct StringArrayList *list_to_append);
char* list_get(struct StringArrayList *list, int index);
void list_free(struct StringArrayList *list);
struct StringArrayList list_create();
