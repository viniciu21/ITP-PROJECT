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
    int dx = abs(x0-xf), sx = x0<xf ? 1 : -1;
    int dy = abs(y0-yf), sy = y0<yf ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2, e2;
    while(1){
        img->img[x0][y0].r = r;
        img->img[x0][y0].g = g;
        img->img[x0][y0].b = b;
        if (x0==xf && y0==yf){ 
            break;
        }
        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}
 
// void fill(Image *img, int r,int g, int b){
//     if (r == 0 && g == 0 && b == 0){      
//     }
// }
void polygono(Image *img, int r, int g, int b,FILE *entrada){
    int pontos,j,i,x0,y0,xf,yf;
    int x1,y1;
    fscanf(entrada, "%i", &pontos);
    fscanf(entrada, "%i %i %i %i", &x0,&y0,&xf,&yf);
    line(img,x0,y0,xf,yf,r,g,b);
}