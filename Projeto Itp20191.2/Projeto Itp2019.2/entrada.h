#ifndef ENTRADA_H
#define ENTRADA_H
#include <stdio.h>
#include "primitivas.h"
void startimage(Image *img); //Função de inicializar imagem
Bool escolherfuncao(char nomedafuncao, FILE *fp);//Em processo de criação
void color(Pixel *cor, FILE *entrada);
#endif 