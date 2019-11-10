#include <stdio.h>
#include "output.h"
#include "imageprocessors.h"
#include "entrada.h"
#include <string.h>

void main(){
    int i,x0,y0,xf,yf,centrox,centroy,raio;//Variaveis utilizadas para os argumentos das funções 
    Pixel cor;
    Image img;//Nossa imagem
    char nome[50];//Bariavel para o .txt
    FILE *fp;//.ppm
    FILE *entrada;//.txt
    entrada = fopen("entrada.txt","r");//Abre em função de leitura
    if (entrada == NULL){
        printf("Erro na abertura!\n");
    }
    else{
        while ((fscanf(entrada,"%s", nome) != EOF)){//Lerá todos os nomes das funções do .txt
            if(strcmp(nome,"image") == 0){//Espeficamente para a função startimage
                fscanf(entrada,"%i %i", &img.line, &img.col);
                startimage(&img);
            }
            if(strcmp(nome,"save") == 0){//Função save, que interromperá o while
                save(fp,img);
                break;
            }
            if(strcmp(nome,"clear") == 0){//Função clear
                fscanf(entrada,"%hhu %hhu %hhu", &cor.r,&cor.g,&cor.b);
                limpar(&img,cor);
            }
            if(strcmp(nome,"line") == 0){
                fscanf(entrada,"%i %i %i %i", &x0,&y0,&xf,&yf);
                line(&img, x0, y0, xf, yf, cor);            
            }
            if(strcmp(nome,"polygon")== 0){
                polygono(&img,cor,entrada);
            }
            if(strcmp(nome,"color")== 0){
                fscanf(entrada,"%hhu %hhu %hhu", &cor.r,&cor.g,&cor.b);
            }
            if(strcmp(nome,"fill")== 0){
                fscanf(entrada,"%i %i",&x0,&y0);
                fill(&img,x0,y0,cor);
            }
            if(strcmp(nome, "circle")== 0){
                fscanf(entrada,"%i %i %i", &centrox,&centroy,&raio);
                circulo(&img,cor,centrox,centroy,raio);
            }
            
        }
    }   
    fclose(entrada);//Fecha a leitura
}