#include "hashmap.h"

#ifndef EE200_FILE_MANAGER_H
#define EE200_FILE_MANAGER_H

HashMap *loaded_files;
char* *loaded_data_paths;
int files_loaded = 0;

//will load all files, built for windows specifically (windows api)
HashMap* init_files();
void free_files();
void load_file(char* path);
void read_file(char* path);
void write_to_file(char* path, int mode);
void create_file(char* path);
void delete_file(char* path);

#endif //EE200_FILE_MANAGER_H
