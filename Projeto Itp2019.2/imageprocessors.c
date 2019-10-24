#include <stdio.h>
#include "imageprocessors.h"
#include <stdlib.h>

void limpar(Image *img, int r, int g, int b){
    int l,c; 
    for(l = 0; l < img->line; l++){
        for(c = 0; c < img->col; c++){
            img->img[l][c].r = r;
            img->img[l][c].g = g;
            img->img[l][c].b = b;    
        }
    }
}