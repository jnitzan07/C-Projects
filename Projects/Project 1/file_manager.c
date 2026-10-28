//
// Created by jnitz on 10/27/2026.
//

#include "file_manager.h"
#include "hashmap.h"

void load_file(char* path) {
    //add file to loaded file list
    //if image, call load_texture(file_path)
    //if txt or whatev we naming the data (.dat maybe?), then add to loaded_data
}

void read_file(char* path) {
    //grab file from our hashmap

    //this gives us a pointer to the file
    void* pointer = get_value(loaded_files, path);

    //then we do whatever checks we want on the path for filetype
    //1. make sure file isn't an image (only txt or dat or whatev)
    //2. each line of file will tell us what we do with the data
    //iterate through file
        //line = line
        //switch (line)
        //next_line()
        //case char* create_object
           //do instruct
           //break
        //etc....
        //default other
            //return
}

void write_to_file(char* path, int mode) {
    //if mode = 0; clear file then write
    //if mode = 1; append to file
}

void delete_file(char* path) {
    //delete the file at path if exists
}

void create_file(char* path) {
    //literally just a path to create a file
    //if folder !exists, create the folder
    //then create the file
}


HashMap* init_files() {
    loaded_files = create_table();
    //malloc loaded_data (array of strings for files loaded)


    //loop through assets folder
    //for each file in assets folder, check extension type
        //load file(path)
}

void free_files() {
    //since our hashmap is of pointers, we need to manually clear all the instances of structs stored (tho OOP isn't quite the correct way to think about this for C)
    for (int i = 0; i < files_loaded; i++) {
        Node *current = loaded_files -> buckets[i];
        while (current != NULL) {
            Node *temp = current;
            current = current -> next;
            free(temp -> value);
            free(temp -> key);
            free(temp);
        }
    }
    free(loaded_files);
}