#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "imageprocessors.h"
void filtrocinza(Image *img){
    int l,c; 
    for(l = 0; l < img->col; l++){
        for(c = 0; c < img->line ; c++){
            unsigned char cinza = (img->img[c][l].r + img->img[c][l].g + img->img[c][l].b)/3;
            img->img[c][l].r = cinza;
            img->img[c][l].g = cinza;
            img->img[c][l].b = cinza;
        }
    }
}
void filtrothreshold(Image *img){
    int i,j; 
    filtrocinza(img);
    unsigned char limite = 255/2;
    for(i = 0; i < img->line; i++){
        for(j = 0; j < img->col; j++){
            if(img->img[i][j].r > limite || img->img[i][j].g > limite || img->img[i][j].b > limite){
                img->img[i][j].r = 255;
                img->img[i][j].g = 255;
                img->img[i][j].b = 255;   
            }
            else{
                img->img[i][j].r = 0;
                img->img[i][j].g = 0;
                img->img[i][j].b = 0;
            }

        }
    }
}
void filtronegativo(Image *img){
    int i,j;
    for(i = 0; i < img->line; i++){
        for(j = 0; j < img->col; j++){
            img->img[i][j].r = 255 - img->img[i][j].r;
            img->img[i][j].g = 255 - img->img[i][j].g;        
            img->img[i][j].b = 255 - img->img[i][j].b;
            } 
        }
}
void borrar(Image *img){
    int l,c,i,j;

    float borrar[3][3] ={{0.11111111,0.11111111,0.11111111},
                        {0.11111111,0.11111111,0.11111111},
                        {0.11111111,0.11111111,0.11111111}};
    for(l = 1; l < img->line -1 ;l++){
        for(c = 1; c < img->col - 1;c++){
            int vermelho = 0, verde = 0, azul = 0;
            for(i = 0; i < 3; i++){
                for(j = 0; j < 3; j++){
                    vermelho += (img->img[l - 1 + i][c - 1 + j].r) * borrar[i][j]; 
                    verde += (img->img[l - 1 + i][c - 1 + j].g) * borrar[i][j];
                    azul += (img->img[l - 1 + i][c - 1 + j].b) * borrar[i][j];
                    //printf("red = %i green = %i blue = %i \n", vermelho,verde,azul);
                    //printf("%i %i %i %i \n",l,c ,i, j);
                }
            }
            if(vermelho > 255){
                vermelho = 255;
            }
            if(vermelho < 0){
                vermelho = 0;
            }
            if(verde > 255){
                verde = 255;
            }
            if(verde < 0){
                verde = 0;
            }
            if(azul > 255){
                azul = 255;
            }
            if(azul < 0){
                azul = 0;
            }
            img->img[l][c].r = vermelho;
            img->img[l][c].g = verde;
            img->img[l][c].b = azul;
            //printf("%i %i \n", l,c);
        }
    }
}
void aumentarborrado(Image *img, int n){
    if(n == 0){
        return;
    }
    if(n > 0){
        borrar(img);
        aumentarborrado(img,n-1);
    }
}