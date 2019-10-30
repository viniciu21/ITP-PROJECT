#include <stdio.h>
#include "imageprocessors.h"
#include <stdlib.h>

void limpar(Image *img, int r, int g, int b){//Limpa a imagem e bota uma cor especifica
    int l,c; 
    for(l = 0; l < img->line; l++){
        for(c = 0; c < img->col; c++){
            img->img[l][c].r = r;
            img->img[l][c].g = g;
            img->img[l][c].b = b;    
        }
    }
}
void line(Image *img, int x0, int y0,int xf,int yf,int r,int g,int b){
    int deltax,deltay,quadrantex,quadrantey,erro,erro2;
    deltax =  abs(xf - x0);
    deltay =  abs(yf - x0);
    if(x0 < xf){
        quadrantex = 1;
    }
    else{
        quadrantex = -1;
    }
    if(y0 < yf){
        quadrantey = 1;
    }
    else{
        quadrantey = -1;
    }
    if(quadrantex > quadrantey){
        erro = quadrantex/2;
    }
    else{
        erro = -quadrantey/2;
    }
    while (x0 != xf && y0 != yf){
        img->img[x0][y0].r = r ;
        img->img[x0][y0].g = g ;
        img->img[x0][y0].b = b ;
        
        erro2 = erro;
        if(erro2 > -deltax){
            erro -= deltay;
            x0 += quadrantex;
        }
        if(erro2 < deltay){
            erro += deltax;
            y0 += deltay;  
        }
    }
}
void fill(Image *img, int r,int g, int b){
    if (r == 0 && g == 0 && b == 0){      
    }
}
void polygono(Image *img, int r, int g, int b,FILE *entrada){
    int pontos,j,i;
    fscanf(entrada, "%i", &pontos);
    Ponto arpo[pontos];
    for (i = 0; i < pontos; i++){
        fscanf(entrada, "%i %i", &arpo[i].x0, &arpo[i].y0);
    }
    for(j = 0; j < pontos; j++){    
        return;
    }
}