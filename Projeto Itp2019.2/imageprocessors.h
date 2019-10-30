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
    Bool state;
}Pixel;
typedef struct{//Image, contem linhas e colunas, boleano possivelmente servira para o comando FIll
    int line;
    int col;
    Pixel **img;
}Image;
typedef struct{
    int x0;
    int y0;
}Ponto;
void limpar(Image *img, int r, int g, int b);//Função para "limpar" a imagem
void line(Image *img, int x0, int y0,int xf,int yf,int r,int g,int b);
void polygono(Image *img, int r, int g, int b,FILE *entrada);
#endif