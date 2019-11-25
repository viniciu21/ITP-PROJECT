#ifndef OUTPUT_H
#define OUTPUT_H
#include <stdio.h>
#include "primitivas.h"
/*
** Está biblioteca contém a função para salvar o arquivo .ppm
*/
void salvar(FILE *fp, Image img, char *arquivo);

#endif