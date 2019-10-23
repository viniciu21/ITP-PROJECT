#ifndef IMAGEPROCESSORS_H
#define IMAGEPROCESSORS_H
#include <stdio.h>
typedef enum{
    false, true
}Bool;
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
}Pixel;
typedef struct{
    int line;
    int col;
    Bool state;
    Pixel **img;
}Image;
#endif