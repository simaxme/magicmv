#include<sys/stat.h>

#include "../files.h"

#ifndef _WIN32
  int is_folder(char* path) {
    struct stat path_stat;

    int res = stat(path, &path_stat);

    if (res != 0) {
      return -1;
    }

    return S_ISDIR(path_stat.st_mode);
  }
#endif
