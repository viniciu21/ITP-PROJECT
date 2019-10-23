#include <stdio.h>
#include "imageprocessors.h"
#include <stdlib.h>
#include <string.h>


void  startimage(Image *img){
    int l,c;
    img->img = malloc(img->line * sizeof(Image*));
    for(l = 0; l < img->line; l++){
        img->img[l] = malloc(img->col * sizeof(Image));
        for(c = 0; c < img->col;c++){
            img->img[l][c].r = 255;
            img->img[l][c].g = 255;
            img->img[l][c].b = 255;
        }
    }
    
}