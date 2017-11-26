#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libPrincipal.h"

void aguarda_enter(){
    printf("\n\nPressione <enter> para continuar...");
    getchar();
    getchar();
}

void imprime_menu(){
    system("cls");

    printf("/____An�lise de Desempenho de �rvores____\\\n");
    printf("|                                        |\n");
    printf("|* Defina qual tipo de Inser��o deseja  *|\n");
    printf("|                                        |\n");
    printf("| 1 - Ordenadamente                      |\n");
    printf("| 2 - Desordenadamente                   |\n");
    printf("|                                        |\n");
    printf("| 0 - Sair                               |\n");
    printf("|                                        |\n");
    printf("\\----------------------------------------/\n");
}

int solicita_opcao(){
    int opt, cont = 0;

    do{ //Roda do while at� digitar uma op��o v�lida.
        if(cont > 0){
            printf("\nOp��o inv�lida! Digite a op��o desejada: ");
            scanf("%d", &opt);
        }else{
            printf("\nDigite a op��o desejada: ");
            scanf("%d", &opt);
        }

        cont++;
    }while(opt < 0 || opt > 2);

    return opt;
}

void redireciona_para_opcao(int opt){
    switch(opt){ //Verifica qual op��o foi selecionada e redireciona para m�dulos respons�veis pela execu��o.
        case 1:
            printf("Inser��o na �rvore AVL: \n");
            analisaAVL_Ordenado();

            printf("Inser��o na �rvore Rubro-Negra: \n");
            analisaLLRB_Ordenado();
            aguarda_enter();
        break;

        case 2:
            printf("Inser��o na �rvore AVL: \n");
            analisaAVL_Desordenado();

            printf("Inser��o na �rvore Rubro-Negra: \n");
            analisaLLRB_Desordenado();
            aguarda_enter();
        break;

        case 0:
            printf("\nAt� mais!");
            aguarda_enter();
            exit(1);
        break;
    }
}

void analisaOrdenado(){

}

void analisaAVL_Desordenado(){
    FUNC *funcionarios = alocaEstrutura(14999);
    int i;

    leArquivo(funcionarios, "arquivos/massaDadosDesordenados.csv");

    //Insere na arvore AVL
    arvAVL *raizAVL;
    raizAVL = cria_arvAVL();

    for(i = 0; i < 14999; i++){
        insere_arvAVL(raizAVL, funcionarios[i]);
    }

    liberar_arvAVL(raizAVL);

    liberaEstrutura(funcionarios);
}

void analisaLLRB_Desordenado(){
    FUNC *funcionarios = alocaEstrutura(14999);
    int i;

    leArquivo(funcionarios, "arquivos/massaDadosDesordenados.csv");

    //Insere na arvore Rubro-Negra
    arvoreLLRB *raizLLRB;
    raizLLRB = cria_arvoreLLRB();

    for(i = 0; i < 14999; i++){
        insere_arvoreLLRB(raizLLRB, funcionarios[i]);
    }

    liberar_arvoreLLRB(raizLLRB);

    liberaEstrutura(funcionarios);
}

void analisaAVL_Ordenado(){
    /*Come�a m�dulo de ordena��o*/
   FUNC *funcionariosD = alocaEstrutura(14999);

   leArquivo(funcionariosD, "arquivos/massaDadosDesordenados.csv");

   shellSort(funcionariosD, 14999);

   escreveArquivo(funcionariosD, "arquivos/massaDadosOrdenados.csv");

   liberaEstrutura(funcionariosD);

   /*Come�a m�dulo de leitura*/
   FUNC *funcionarios = alocaEstrutura(14999);

   leArquivo(funcionarios, "arquivos/massaDadosOrdenados.csv");

   //Insere na arvore AVL
    arvAVL *raizAVL;
    raizAVL = cria_arvAVL();

    int i;
    for(i = 0; i < 14999; i++){
        insere_arvAVL(raizAVL, funcionarios[i]);
    }

    liberar_arvAVL(raizAVL);

   liberaEstrutura(funcionarios);
}

void analisaLLRB_Ordenado(){
 /*Come�a m�dulo de ordena��o*/
   FUNC *funcionariosD = alocaEstrutura(14999);

   leArquivo(funcionariosD, "arquivos/massaDadosDesordenados.csv");

   shellSort(funcionariosD, 14999);

   escreveArquivo(funcionariosD, "arquivos/massaDadosOrdenados.csv");

   liberaEstrutura(funcionariosD);

   /*Come�a m�dulo de leitura*/
   FUNC *funcionarios = alocaEstrutura(14999);

   leArquivo(funcionarios, "arquivos/massaDadosOrdenados.csv");

    //Insere na arvore Rubro-Negra
    arvoreLLRB *raizLLRB;
    raizLLRB = cria_arvoreLLRB();

    int i;
    for(i = 0; i < 14999; i++){
        insere_arvoreLLRB(raizLLRB, funcionarios[i]);
    }

    liberar_arvoreLLRB(raizLLRB);

    liberaEstrutura(funcionarios);
}
