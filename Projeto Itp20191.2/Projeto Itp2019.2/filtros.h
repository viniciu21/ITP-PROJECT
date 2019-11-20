#ifndef FILTROS_H
#define FILTROS_H
#include <stdio.h>
#include "filtros.h"
#include "primitivas.h"
void filtrocinza(Image *img);
void filtrothreshold(Image *img);
void filtronegativo(Image *img);
void borrar(Image *img);
void aumentarborrado(Image *img, int n);
#endif