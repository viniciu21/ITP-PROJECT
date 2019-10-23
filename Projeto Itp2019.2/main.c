#include <stdio.h>
#include "output.h"
#include "imageprocessors.h"
#include "entrada.h"

void main(){
    Image img;
    FILE *fp;
    FILE *entrada;
    entrada = fopen("entrada.txt","r");
    if (entrada == NULL){
        printf("Erro na abertura!\n");
    }
    else{
        fscanf(entrada,"%i %i", &img.line,&img.col);
    }
    fclose(entrada);
    printf("%i %i \n", img.col,img.line);
    startimage(&img);
    save(fp, img);
}