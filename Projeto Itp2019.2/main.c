#include <stdio.h>
#include "output.h"
#include "imageprocessors.h"
#include "entrada.h"
#include <string.h>

void main(){
    int r,g,b,i,x0,y0,xf,yf;//Variaveis utilizadas para os argumentos das funções
    r = 0;
    g = 0;
    b = 0; 
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
                fscanf(entrada,"%i %i", &img.col, &img.line);
                startimage(&img);
            }
            if(strcmp(nome,"save") == 0){//Função save, que interromperá o while
                save(fp,img);
                break;
            }
            if(strcmp(nome,"clear") == 0){//Função clear
                fscanf(entrada,"%i %i %i", &r,&g,&b);
                limpar(&img,r,g,b);
            }
            if(strcmp(nome,"line") == 0){
                fscanf(entrada,"%i %i %i %i", &x0,&y0,&xf,&yf);
                line(&img, x0, y0, xf, yf, r, g, b);

            }
            
        }
    }   
    fclose(entrada);//Fecha a leitura
}