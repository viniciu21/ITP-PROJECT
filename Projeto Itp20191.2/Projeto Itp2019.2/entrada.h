#ifndef ENTRADA_H
#define ENTRADA_H

#include <stdio.h>
#include "primitivas.h"
/*
** Estã trata da inicialização das imagens como da leitura dos dados do arquivo.txt
*/
void inicializarimage(Image *img); //Função de inicializar imagem
void color(Pixel *cor, FILE *entrada);
void menu();

#endif 