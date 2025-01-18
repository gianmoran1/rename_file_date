#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>

#include "rename_file_date.h"

int main(int argc, char** argv){
    if (argc != 2){
        printf("Uso: ejecutable directorio\n");
        exit(-1);
    }
    struct stat entry_file_data;
    char* entry_file_name;
    struct dirent *entry_directory;
    DIR *directory;
    if((directory = opendir(argv[1])) == NULL){
        printf("Error al intentar abrir el directorio.\n");
        exit(-1);
    }

    while((entry_directory = readdir(directory)) != NULL){
        entry_file_name = malloc(strlen(argv[1]) + strlen(entry_directory->d_name) +2);
        sprintf(entry_file_name,"%s/%s",argv[1],entry_directory->d_name);
        stat(entry_file_name,&entry_file_data);
        printf("Entrada: %lu\n", entry_file_data.st_ino);
    }

    return 0;
}