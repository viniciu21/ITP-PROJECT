#include <stdio.h>
#include "output.h"
#include "imageprocessors.h"
#include "entrada.h"
#include <string.h>

void main(){
    int r,g,b,i,x0,y0;//Variaveis utilizadas para os argumentos das funções
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
                fscanf(entrada,"%i", &img.col);
                fscanf(entrada,"%i", &img.line);
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
            
        }
    }   
    fclose(entrada);//Fecha a leitura
}