#include <stdio.h>

void save(FILE *file){
    file = fopen("file.ppm", "w");
    if(file == NULL){
        printf("erro de sintaxe \n");
    }
    fclose(file);
}