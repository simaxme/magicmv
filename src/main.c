#include <stdio.h>
#include <stdlib.h>
#include "utils/files.h"
#include "./utils/list.h"

int main(int argc, char *argv[]) {
  if (argc <= 2) {
    printf("This command requires at least 2 arguments!\n");
    return 1;
  }

  // A list of all files that we will move
  struct StringArrayList src_paths = list_create();

  for (int i = 0; i < argc-2; i++) {
    char* absolute_src_path = absolute_path(argv[i+1]);

    if (absolute_src_path == NULL) {
      printf("Source file %s could not be determined.\n", argv[i]);
      return 1;
    }

    int src_path_is_file = is_file(absolute_src_path);

    if (src_path_is_file == -1) {
      return 1;
    }

    if (!src_path_is_file) {
      struct StringArrayList result = read_folder_recursive(absolute_src_path);
      char** ptr = result.ptr;

      while (*ptr != NULL) {
        ptr++;
      }

      list_concat(&src_paths, &result);

      continue;
    }

    printf("Will move %s\n", absolute_src_path);

    list_push(&src_paths, absolute_src_path);
  }

  char** ptr = src_paths.ptr;

  while (*ptr != NULL) {
    printf("GOT FILE: %s\n", *ptr);
    ptr++;
  }


  char* dist_file_rel = argv[argc - 1];
  // Our dist file/folder where the result will be placed
  char* dist_file = absolute_path(dist_file_rel);

  if (dist_file == NULL) {
    printf("Dist file could not be determined.");
    return 1;
  }

  printf("Will move to %s\n", dist_file);

  free(dist_file);
}
