#include <stdio.h>
#include "primitivas.h"
#include <stdlib.h>
#include "entrada.h"
#include <math.h>

void limpar(Image *img, Pixel cor){//Limpa a imagem e bota uma cor especifica
    int l,c; 
    for(l = 0; l < img->line; l++){
        for(c = 0; c < img->col; c++){
            img->img[l][c] = cor;    
        }
    }
}
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
    int sx,sy;
    if(x0<xf){
        sx = 1;
    }
    else{
        sx = -1;
    }
    int deltay = abs(y0-yf);
    if(y0<yf){
        sy = 1;
    }
    else{
        sy = -1;
    }
    int erro1; //(deltax>deltay ? deltax : -deltay)/2, erro2;
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
            x0 += sx; 
        }
        if (erro2 < deltay){
            erro1 += deltax; 
            y0 += sy; 
        }
    }
}    
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
void circulo(Image *img, Pixel cor, int centrox, int centroy, int raio){//
    int x = 0;
    int y = raio; 
    int d = 3 - 2 * raio;
    img->img[centrox+x][centroy+y] = cor;
    img->img[centrox+x][centroy+y].state = 1;
    img->img[centrox-x][centroy+y] = cor;
    img->img[centrox-x][centroy+y].state = 1;
    img->img[centrox+x][centroy-y] = cor;
    img->img[centrox+x][centroy-y].state = 1;
    img->img[centrox-x][centroy-y] = cor;
    img->img[centrox-x][centroy-y].state = 1;
    img->img[centrox+y][centroy+x] = cor;
    img->img[centrox+y][centroy+x].state = 1;
    img->img[centrox-y][centroy+x] = cor;
    img->img[centrox-y][centroy+x].state = 1;
    img->img[centrox+y][centroy-x] = cor;
    img->img[centrox+y][centroy-x].state = 1; 
    img->img[centrox-y][centroy-x] = cor;
    img->img[centrox-y][centroy-x].state = 1;
    while (y > x){
        x++; 
        if (d > 0){ 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else{
            d = d + 4 * x + 6;
        }
        img->img[centrox+x][centroy+y] = cor;
        img->img[centrox+x][centroy+y].state = 1;
        img->img[centrox-x][centroy+y] = cor;
        img->img[centrox-x][centroy+y].state = 1;
        img->img[centrox+x][centroy-y] = cor;
        img->img[centrox+x][centroy-y].state = 1;
        img->img[centrox-x][centroy-y] = cor;
        img->img[centrox-x][centroy-y].state = 1;
        img->img[centrox+y][centroy+x] = cor;
        img->img[centrox+y][centroy+x].state = 1;
        img->img[centrox-y][centroy+x] = cor;
        img->img[centrox-y][centroy+x].state = 1;
        img->img[centrox+y][centroy-x] = cor;
        img->img[centrox+y][centroy-x].state = 1; 
        img->img[centrox-y][centroy-x] = cor;
        img->img[centrox-y][centroy-x].state = 1;
    }
}
// void graficocorpo(Image *img, Pixel cor){
//     line(img,0,img->line/2,img->col-1,img->line/2,cor);
//     line(img,img->col/2,0,img->col/2,img->line-1,cor);
// }
// void graficopolinomio(Image *img, Pixel cor, int grau){
//     int centrox0 = img->col/2;
//     int centroy0 = img->line/2;
//     Ponto salvo;
//     int a,b,c,d,x,y;
//     x = 0;
//     if(grau == 1){
//         printf("me diga o a(aquele que multiplica o X) e o d(valor independente)\n");
//         scanf("%i %i",&a,&d);
//         y = a*x+d;
//         salvo.x0 = x;
//         salvo.y0 = y;
//         x = 10;
//         y = a*x+d;
//         line(img,salvo.y0,salvo.x0,y,x,cor);
//         line(img,25,25,30,10,cor);
//         // while(centrox0 != img->col-1){
//         //     y = a*x+d;
//         //     salvo.x0 = x;
//         //     salvo.y0 = y;
//         //     x++;
//         //     y = a*x+d;
//         //     centrox0++;
//         //     line(img,salvo.y0,salvo.x0,y,x,cor);
//         // }
//     }
// }