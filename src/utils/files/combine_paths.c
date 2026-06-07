#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include "../files.h"

#ifndef _WIN32
  char* combine_paths(char* path1, char* path2) {
    char *result = malloc((strlen(path1) + strlen(path2) + 2) * sizeof(char));

    memcpy(result, path1, strlen(path1));
    result[strlen(path1)] = '/';
    memcpy(result + strlen(path1) + 1, path2, strlen(path2));
    result[strlen(path1) + strlen(path2) + 1] = '\0';

    return result;
  }
#endif
