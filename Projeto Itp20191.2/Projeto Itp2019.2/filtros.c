#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "imageprocessors.h"
void filtrocinza(Image *img){
    int l,c; 
    for(l = 0; l < img->col; l++){
        for(c = 0; c < img->line ; c++){
            int cinza = (img->img[c][l].r + img->img[c][l].g + img->img[c][l].b)/3;
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