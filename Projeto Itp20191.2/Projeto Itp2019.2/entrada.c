#include <stdio.h>
#include "output.h"
#include "primitivas.h"
#include "entrada.h"
#include <string.h>
#include <stdlib.h>
#include "filtros.h"


void  inicializarimage(Image *img){ //Faz a alocação dinamica da imagem que será salva .ppm
    int l,c;
    img->img = malloc(img->line * sizeof(Pixel*));
    for(l = 0; l < img->line; l++){
        img->img[l] = malloc(img->col * sizeof(Pixel));
        for(c = 0; c < img->col;c++){
            img->img[l][c].r = 255;
            img->img[l][c].g = 255;
            img->img[l][c].b = 255;
            img->img[l][c].state = 0;
        }
    }
    
}
void color(Pixel *cor, FILE *entrada){
    fscanf(entrada,"%hhu %hhu %hhu", &cor->r,&cor->b,&cor->b);
    printf("%hhu %hhu %hhu \n",cor->r,cor->g,cor->b);
}
void menu(){
    int i,x0,y0,xf,yf,centrox,centroy,raio,n;//Variaveis utilizadas para os argumentos das funções 
    Pixel cor;
    Image img;//Nossa imagem
    char nome[50];//Variavel para o .txt
    char arquivo[50];
    FILE *fp;//.ppm
    FILE *entrada;//.txt
    strcpy(arquivo, "file.ppm");
    entrada = fopen("entrada.txt","r");//Abre em função de leitura
    if (entrada == NULL){
        printf("Erro na abertura!\n");
    }
    else{
        while ((fscanf(entrada,"%s", nome) != EOF)){//Lerá todos os nomes das funções do .txt
            if(strcmp(nome,"image") == 0){//Espeficamente para a função startimage
                fscanf(entrada,"%i %i", &img.col, &img.line);
                inicializarimage(&img);
            }
            if(strcmp(nome,"save") == 0){//Função save, que interromperá o while
                fscanf(entrada,"%s", arquivo);
                salvar(fp,img,arquivo);
                break;
            }
            if(strcmp(nome,"clear") == 0){//Função clear
                fscanf(entrada,"%hhu %hhu %hhu", &cor.r,&cor.g,&cor.b);
                limpar(&img,cor);
            }
            if(strcmp(nome,"line") == 0){
                fscanf(entrada,"%i %i %i %i", &y0,&x0,&yf,&xf);
                line(&img, x0, y0, xf, yf, cor);            
            }
            if(strcmp(nome,"polygon")== 0){
                polygono(&img,cor,entrada);
            }
            if(strcmp(nome,"color")== 0){
                fscanf(entrada,"%hhu %hhu %hhu", &cor.r,&cor.g,&cor.b);
            }
            if(strcmp(nome,"fill")== 0){
                fscanf(entrada,"%i %i",&y0,&x0);
                fill(&img,x0,y0,cor);
            }
            if(strcmp(nome, "circle")== 0){
                fscanf(entrada,"%i %i %i", &centroy,&centrox,&raio);
                circulo(&img,cor,centrox,centroy,raio);
            }
            if(strcmp(nome, "filtrocinza")== 0){
                filtrocinza(&img);
            }
            if(strcmp(nome, "threshold")== 0){
                filtrothreshold(&img);
            }
            if(strcmp(nome, "negative")== 0){
                filtronegativo(&img);
            }
            if(strcmp(nome, "borrar")== 0){
                borrar(&img);
            }
            if(strcmp(nome, "aumentarborrado")== 0){
                fscanf(entrada,"%i",&n);
                aumentarborrado(&img, n);
            }
        }
    }  
    fclose(entrada);//Fecha a leitura
    char command[200];
    strcpy(command, "xdg-open ");
    strcat(command, arquivo);
    system(command);
}