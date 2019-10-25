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
void line(Image *img, int x0, int y0,int xf,int yf){
    float angulo = (yf - y0)/(xf - x0);
}
Image fill(Image *img, int r,int g, int b){
    if (r == 0 && g == 0 && b == 0){      
    }
}