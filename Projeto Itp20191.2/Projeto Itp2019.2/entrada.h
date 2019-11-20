#ifndef ENTRADA_H
#define ENTRADA_H
#include <stdio.h>
#include "primitivas.h"
void inicializarimage(Image *img); //Função de inicializar imagem
void color(Pixel *cor, FILE *entrada);
void menu();
#endif 