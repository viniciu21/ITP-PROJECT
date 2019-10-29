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
    int dx,dy,sx,sy,erro,e2;
    dx =  abs(xf - x0);
    dy =  abs(yf - x0);
    if(x0 < xf){
        sx = 1;
    }
    else{
        sx = -1;
    }
    if(y0 < yf){
        sy = 1;
    }
    else{
        sy = -1;
    }
    if(dx > dy){
        erro = dx/2;
    }
    else{
        erro = -dy/2;
    }
    while (x0 != xf || y0 != yf){
        img->img[x0][y0].r = r ;
        img->img[x0][y0].g = g ;
        img->img[x0][y0].b = b ;
        
        e2 = erro;
        if(e2 > -dx){
            erro -= dy;
            x0 += sx;
        }
        if(e2 < dy){
            erro += dx;
            y0 += sy;  
        }
    }
}
Image fill(Image *img, int r,int g, int b){
    if (r == 0 && g == 0 && b == 0){      
    }
}