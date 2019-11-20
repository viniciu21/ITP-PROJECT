#include <stdio.h>
#include "primitivas.h" 
#include <stdlib.h>
void save(FILE *fp, Image img, char *arquivo){//Salva a imagem dentro do .ppm
    int l, c;
    fp = fopen(arquivo, "w");
    if(fp == NULL){
        printf("erro de sintaxe \n");
    }
    else{
        fprintf(fp,"P3 \n");
        fprintf(fp,"%i %i\n", img.col,img.line);
        fprintf(fp,"255 \n");
        for(l = 0; l < img.line; l++){
            for(c = 0; c < img.col; c++){
                fprintf(fp,"%hhu %hhu %hhu \t", img.img[l][c].r,img.img[l][c].g,img.img[l][c].b);
            }
            fprintf(fp,"\n");
        }
    }
    fclose(fp);
    free(img.img);
}
