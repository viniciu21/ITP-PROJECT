#ifndef IMAGEPROCESSORS_H
#define IMAGEPROCESSORS_H
#include <stdio.h>
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
}Pixel;
typedef struct{
    int line;
    int col;
    Pixel **img;
}Image;
#endif