#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "primitivas.h"
/*
** Estã função tranforma a imagem em cinza
*/
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
/*
** Estã função tranforma a imagem que tiver o RGB acima de 125 em preto e o que estiver abaixo em branco
*/
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
/*
** Estã função tranforma as cores da imagem nas cores inversas 
*/
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
/*
** Estã função tranforma borra a imagem
** https://stackoverflow.com/questions/42363726/bluring-an-image-in-c-c
** https://www.geeksforgeeks.org/what-is-image-blurring/
*/
void borrar(Image *img){
    int l,c,i,j;
    float borrar[3][3] ={{0.111,0.111,0.111},
                        {0.111,0.111,0.111},
                        {0.111,0.111,0.111}};
    for(l = 1; l < img->line -1 ;l++){
        for(c = 1; c < img->col - 1;c++){
            int vermelho = 0, verde = 0, azul = 0;
            for(i = 0; i < 3; i++){
                for(j = 0; j < 3; j++){
                    vermelho += (img->img[l-1+i][c-1+j].r)*borrar[i][j]; 
                    verde += (img->img[l-1+i][c-1+j].g)*borrar[i][j];
                    azul += (img->img[l-1+i][c-1+j].b)*borrar[i][j];
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
        }
    }
}
/*
** Estã função aumenta o borrado da imagem
*/
void aumentarborrado(Image *img, int n){
    if(n == 0){
        return;
    }
    if(n > 0){
        borrar(img);
        aumentarborrado(img,n-1);
    }
}