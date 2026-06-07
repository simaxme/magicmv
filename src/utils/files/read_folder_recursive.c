
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "../files.h"
#include "../list.h"

#ifndef _WIN32
  struct StringArrayList read_folder_recursive(char* folder_path) {
    struct StringArrayList result = list_create();

    struct StringArrayList contents = read_folder(folder_path);
    char** contents_ptr = contents.ptr;

    while (*contents_ptr != NULL) {

      if (!is_file(*contents_ptr)) {
        struct StringArrayList sub_folder_result = read_folder_recursive(*contents_ptr);
        list_concat(&result, &sub_folder_result);

        contents_ptr++;
        continue;
      }

      list_push(&result, *contents_ptr);

      contents_ptr++;
    }

    free(contents.ptr);

    return result;
  }
#endif
