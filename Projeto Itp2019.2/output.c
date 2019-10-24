#include <stdio.h>
#include "imageprocessors.h" 
void save(FILE *fp, Image img){//Salva a imagem dentro do .ppm
    int l, c;
    fp = fopen("file.ppm", "w");
    if(fp == NULL){
        printf("erro de sintaxe \n");
    }
    else{
        fprintf(fp,"P3 \n");
        fprintf(fp,"%i %i\n", img.line,img.col);
        fprintf(fp,"255 \n");
        for(l = 0; l < img.line; l++){
            for(c = 0; c < img.col; c++){
                fprintf(fp,"%u %u %u \t", img.img[l][c].r,img.img[l][c].g,img.img[l][c].b);
            }
            fprintf(fp,"\n");
        }
    }
    fclose(fp);
}
