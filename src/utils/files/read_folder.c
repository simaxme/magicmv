#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include "../files.h"
#include "../list.h"

#ifndef _WIN32
  struct StringArrayList read_folder(char* folder_path) {
    struct StringArrayList result = list_create();

    DIR *dir = opendir(folder_path);

    if (dir == NULL) {
      fprintf(stderr, "Unable to open folder with path %s\n", folder_path);
      exit(EXIT_FAILURE);
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
        continue;
      }

      char* node_path = combine_paths(folder_path, entry->d_name);

      char* p = absolute_path(node_path);
      free(node_path);

      if (strcmp(p, folder_path) == 0) {
        continue;
      }

      list_push(&result, p);
    }

    closedir(dir);

    return result;
  }
#endif
