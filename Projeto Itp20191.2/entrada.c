#include <stdio.h>
#include "imageprocessors.h"
#include <stdlib.h>
#include <string.h>


void  startimage(Image *img){ //Faz a alocação dinamica da imagem que será salva .ppm
    int l,c;
    img->img = malloc(img->line * sizeof(Image*));
    for(l = 0; l < img->line; l++){
        img->img[l] = malloc(img->col * sizeof(Image));
        for(c = 0; c < img->col;c++){
            img->img[l][c].r = 255;
            img->img[l][c].g = 255;
            img->img[l][c].b = 255;
        }
    }
    
}
Bool escolherfuncao(char nomedafuncao, FILE fp){//Metodo possivelmente mais eficiente do que o main.c
    return true;
}
void color(Pixel *cor, FILE *entrada){
    fscanf(entrada,"%hhu %hhu %hhu", &cor->r,&cor->b,&cor->b);
}