#include <stdio.h>
#include "primitivas.h"
#include <stdlib.h>
#include "entrada.h"
#include <math.h>
/* 
** A função limpar usa a cor (R,G,B) que o usuario escolher e "limpa" a imagem.
*/
void limpar(Image *img, Pixel cor){//Limpa a imagem e bota uma cor especifica
    int l,c; 
    for(l = 0; l < img->line; l++){
        for(c = 0; c < img->col; c++){
            img->img[l][c] = cor;
            img->img[l][c].state = 0;    
        }
    }
}
/*
** A função line recebe um ponto inicial e um final trançando uma linha entre os pontos.
** https://www.cs.helsinki.fi/group/goa/mallinnus/lines/bresenh.html
**
*/
void line(Image *img, int x0, int y0,int xf,int yf,Pixel cor){//aqui falta trocar o state
    if(yf > img->col || xf > img->line){
        if(yf > img->col){
            printf("me de um x menor \n");
        }
        if(xf > img->line){
            printf("me de um y menor \n");
        }
        return;
    }
    int deltax = abs(x0-xf);
    int ocatantex,ocatantey;
    if(x0<xf){
        ocatantex = 1;
    }
    else{
        ocatantex = -1;
    }
    int deltay = abs(y0-yf);
    if(y0<yf){
        ocatantey = 1;
    }
    else{
        ocatantey = -1;
    }
    if(x0 == xf){
        ocatantex = 1;
    }
    if(y0 == yf){
        ocatantey = 1;
    }
    int erro1;
    if(deltax > deltay){
        erro1 = deltax/2;
    }
    else{
        erro1 = -deltay/2;
    }
    int erro2;
    while(1){
        img->img[x0][y0] = cor;
        img->img[x0][y0].state = 1;
        if(x0 == xf && y0 == yf){ 
            break;
        }
        erro2 = erro1;
        if (erro2 >-deltax){
            erro1 -= deltay; 
            x0 += ocatantex; 
        }
        if (erro2 < deltay){
            erro1 += deltax; 
            y0 += ocatantey; 
        }
    }
}    
/*
** A função preencher recebe um ponto(x.y) como parâmetro e preenche com a cor que esta em vigor.
*/
void fill(Image *img,int x0,int y0,Pixel cor){
    if(img->line-1 < x0 || img->col-1 < y0 || x0 < 0 || y0 < 0 || img->img[x0][y0].state == 1){
        return;
    }
    //printf("(%i,%i) \n",x0,y0);
    img->img[x0][y0].r = cor.r;
    img->img[x0][y0].g = cor.g;
    img->img[x0][y0].b = cor.b;
    img->img[x0][y0].state = 1;
    fill(img,x0 + 1, y0,cor);    
    fill(img,x0 - 1, y0,cor);
    fill(img,x0, y0 + 1,cor);
    fill(img,x0, y0 - 1,cor);  
}
/*
** A função polygono recebe como parâmetro um número de pontos e em seguida a quantidade de ponto(x,y)
** de acordo com o número de pontos que foi escrito e o programa conectará os pontos dados com linhas.
*/
void polygono(Image *img, Pixel cor,FILE *entrada){
    int pontos,j,i,primeirox,primeiroy;
    fscanf(entrada, "%i", &pontos);
    Ponto arpo[pontos];
    for (i = 0; i < pontos; i++){
        fscanf(entrada, "%i %i", &arpo[i].x0, &arpo[i].y0);
    }
    primeirox = arpo[0].x0;
    primeiroy = arpo[0].y0;
    for(j = 0; j < pontos -1 ; j++){    
        line(img,arpo[j].y0,arpo[j].x0,arpo[j+1].y0,arpo[j+1].x0,cor);
    }
    line(img,arpo[j].y0,arpo[j].x0,primeiroy,primeirox,cor);
}
/*
** A função circulo basicamente desenha um circulo dado um (x,y) que será o centro do circulo e o raio
** do mesmo.
** https://www.javatpoint.com/computer-graphics-bresenhams-circle-algorithm
*/
void circulo(Image *img, Pixel cor, int centrox, int centroy, int raio){
    if(centroy + raio > img->col-1 || centrox + raio > img->line-1){
        printf("Por favor um raio menor ou um ponto mais longe das bordas");
        return;
    }
    int a = 0;
    int b = raio; 
    int d = 3 - 2 * raio;
    img->img[centrox+a][centroy+b] = cor;
    img->img[centrox+a][centroy+b].state = 1;
    img->img[centrox-a][centroy+b] = cor;
    img->img[centrox-a][centroy+b].state = 1;
    img->img[centrox+a][centroy-b] = cor;
    img->img[centrox+a][centroy-b].state = 1;
    img->img[centrox-a][centroy-b] = cor;
    img->img[centrox-a][centroy-b].state = 1;
    img->img[centrox+b][centroy+a] = cor;
    img->img[centrox+b][centroy+a].state = 1;
    img->img[centrox-b][centroy+a] = cor;
    img->img[centrox-b][centroy+a].state = 1;
    img->img[centrox+b][centroy-a] = cor;
    img->img[centrox+b][centroy-a].state = 1; 
    img->img[centrox-b][centroy-a] = cor;
    img->img[centrox-b][centroy-a].state = 1;
    while (b > a){
        a++; 
        if (d > 0){ 
            b--;  
            d = d+4*(a-b)+10; 
        } 
        else{
            d = d+4*a+6;
        }
        img->img[centrox+a][centroy+b] = cor;
        img->img[centrox+a][centroy+b].state = 1;
        img->img[centrox-a][centroy+b] = cor;
        img->img[centrox-a][centroy+b].state = 1;
        img->img[centrox+a][centroy-b] = cor;
        img->img[centrox+a][centroy-b].state = 1;
        img->img[centrox-a][centroy-b] = cor;
        img->img[centrox-a][centroy-b].state = 1;
        img->img[centrox+b][centroy+a] = cor;
        img->img[centrox+b][centroy+a].state = 1;
        img->img[centrox-b][centroy+a] = cor;
        img->img[centrox-b][centroy+a].state = 1;
        img->img[centrox+b][centroy-a] = cor;
        img->img[centrox+b][centroy-a].state = 1; 
        img->img[centrox-b][centroy-a] = cor;
        img->img[centrox-b][centroy-a].state = 1;
    }
}