#ifndef IMAGEPROCESSORS_H
#define IMAGEPROCESSORS_H
#include <stdio.h>
typedef enum{//Boleano 
    false, true
}Bool;
typedef struct {//Pixel, contem valores de RGB (Red, Blue, Green)
    unsigned char r;
    unsigned char g;
    unsigned char b;
}Pixel;
typedef struct{//Image, contem linhas e colunas, boleano possivelmente servira para o comando FIll
    int line;
    int col;
    Bool status;
    Pixel **img;
}Image;
void limpar(Image *img, int r, int g, int b);//Função para "limpar" a imagem
#endif