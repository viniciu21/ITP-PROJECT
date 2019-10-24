#include <stdio.h>
#include "output.h"
#include "imageprocessors.h"
#include "entrada.h"
#include <string.h>

void main(){
    int r,g,b,i,x0,y0;
    Image img;
    char nome[50];
    FILE *fp;
    FILE *entrada;
    entrada = fopen("entrada.txt","r");
    if (entrada == NULL){
        printf("Erro na abertura!\n");
    }
    else{
        while ((fscanf(entrada,"%s", nome) != EOF)){
            if(strcmp(nome,"image") == 0){
                fscanf(entrada,"%i", &img.col);
                fscanf(entrada,"%i", &img.line);
                startimage(&img);
            }
            if(strcmp(nome,"save") == 0){
                save(fp,img);
                break;
            }
            if(strcmp(nome,"clear") == 0){
                fscanf(entrada,"%i %i %i", &r,&g,&b);
                limpar(&img,r,g,b);
            }
            
        }
    }   
    fclose(entrada);
}