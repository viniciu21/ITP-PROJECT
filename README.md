# ITP-PROJECT 
    Projeto itp{
        Este projeto foi feito com participação de Vinicius Oliveira da Silva.
        Neste projeto, foram implementado as seguintes funcionalidades, a seguir
        o nome da funcionalidade e o autor da mesma:
            
            Image == Vinicius; 
            save == Vinicius; 
            Polygon == Vinicius;
            Fill == Vinicius;
            Circle == Vinicius;
            Line == Vinicius;
            Clear == Vinicius; 
            Color == Vinicius;
        
        E para o extra teremos as seguintes implementações:
        
            Filtrocinza == Vinicius;
            filtrothreshold == Vinicius; 
            Borrar == Vinicius; 
            Negative == Vinicius;
            Aumentarborrado == Vinicius;
    }
    Aprendizado{
        Depois de mais de um mès fazendo esse projeto, sinto que estou muito melhor 
        no que se refere a logica e a pesquisa de conteúdo auxiliar (videos e artigos) e 
        que este conhecimento vai me ajudar para o resto de minha carreira.
        
        Refletindo sobre o inicio do projeto, o que faria de diferente seria me organizar
        melhor para o inicio do projeto, pois eu demorei um pouco para começar a me focar
        mesmo no projeto, e por isso, tive algumas dificuldades em algumas entregas, mas 
        com o andar do projeto, tive um amadurecimento consideravel.
    }
    Compilando{
        Para compilar o projeto Bastar ter o gcc e o xdg instalado e 
        executar o seguinte comando:
            $gcc entrada.c filtros.c main.c output.c primitivas.c -o projeto
        Aqui temos um exemplo : 
            image 800 500
            polygon 4 10 10 790 10 790 490 10 490
            circle 400 250 180 
            polygon 4 9 250 399 9 790 249 400 489
            color 35 142 35 
            fill 11 11
            fill 500 11 
            fill 11 300  
            fill 700 400
            color 255 255 0 
            fill 400 11 
            color 0 0 255
            fill 400 250
            save nomedoarquivo.ppm
        Com esta entrada teriamos uma bandeira do Brasil como resultado
    }
