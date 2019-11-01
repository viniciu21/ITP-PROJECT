#include <stdio.h>
#include "imageprocessors.h"
#include <stdlib.h>

void limpar(Image *img, Pixel cor){//Limpa a imagem e bota uma cor especifica
    int l,c; 
    for(l = 0; l < img->line; l++){
        for(c = 0; c < img->col; c++){
            img->img[l][c] = cor;    
        }
    }
}
void line(Image *img, int x0, int y0,int xf,int yf,Pixel cor){
    int deltax = abs(x0-xf);
    int sx,sy;
    if(x0<xf){
        sx = 1;
    }
    else{
        sx = -1;
    }
    int deltay = abs(y0-yf);
    if(y0<yf){
        sy = 1;
    }
    else{
        sy = -1;
    }
    int erro1 = (deltax>deltay ? deltax : -deltay)/2, erro2;
    while(1){
        img->img[x0][y0] = cor;
        if(x0 == xf || y0 == yf){ 
            break;
        }
        erro2 = erro1;
        if (erro2 >-deltax){
            erro1 -= deltay; 
            x0 += sx; 
        }
        if (erro2 < deltay){
            erro1 += deltax; 
            y0 += sy; 
        }
    }
}
 
void fill(Image *img,Pixel cor){
}
void polygono(Image *img, Pixel cor,FILE *entrada){
    int pontos,j,i,primeirox,primeiroy;
    fscanf(entrada, "%i", &pontos);
    Ponto arpo[pontos];
    for (i = 0; i < pontos; i++){
        fscanf(entrada, "%i %i", &arpo[i].x0, &arpo[i].y0);
        printf("%i %i %i \n", arpo[i].x0,arpo[i].y0,i);
        
    }
    primeirox = arpo[0].x0;
    primeiroy = arpo[0].y0;
    printf("%i %i %i %i \n",arpo[0].x0,arpo[0].y0,primeirox,primeiroy);
    for(j = 0; j < pontos -1 ; j++){    
        line(img,arpo[j].x0,arpo[j].y0,arpo[j+1].x0,arpo[j+1].y0,cor);
        printf("%i %i %i \n",arpo[j].x0, arpo[j].y0, j);
    }
    printf("%i \n", i);
    printf("%i \n",j);
    line(img,arpo[j].x0,arpo[j].y0,primeirox,primeiroy,cor);
}