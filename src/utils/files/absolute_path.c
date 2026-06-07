#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include "../files.h"

#ifndef _WIN32
  char* absolute_path(char* path) {
    char *c1 = strdup(path);
    char *c2 = strdup(path);

    char *folder_path = dirname(c1);
    char *file_name = basename(c2);
    char *real_folder_path = realpath(folder_path, NULL);

    if (real_folder_path == NULL) {
      return NULL;
    }

    if (file_name[0] == '.') {
      free(c1);
      free(c2);
      return real_folder_path;
    }

    char *result = combine_paths(real_folder_path, file_name);

    free(c1);
    free(c2);
    free(real_folder_path);

    return result;
  }
#endif
