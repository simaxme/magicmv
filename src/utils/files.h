char* absolute_path(char* path);
int is_file(char* path);
int is_folder(char* path);
struct StringArrayList read_folder(char* folder_path);
struct StringArrayList read_folder_recursive(char* folder_path);
char* combine_paths(char* path1, char* path2);
