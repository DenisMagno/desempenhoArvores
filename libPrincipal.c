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

    printf("/____Análise de Desempenho de Árvores____\\\n");
    printf("|                                        |\n");
    printf("|* Defina qual tipo de Inserção deseja  *|\n");
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

    do{ //Roda do while até digitar uma opção válida.
        if(cont > 0){
            printf("\nOpção inválida! Digite a opção desejada: ");
            scanf("%d", &opt);
        }else{
            printf("\nDigite a opção desejada: ");
            scanf("%d", &opt);
        }

        cont++;
    }while(opt < 0 || opt > 2);

    return opt;
}

void redireciona_para_opcao(int opt){
    switch(opt){ //Verifica qual opção foi selecionada e redireciona para módulos responsáveis pela execução.
        case 1:
            printf("Inserção na Árvore AVL: \n");
            analisaAVL_Ordenado();

            printf("Inserção na Árvore Rubro-Negra: \n");
            analisaLLRB_Ordenado();
            aguarda_enter();
        break;

        case 2:
            printf("Inserção na Árvore AVL: \n");
            analisaAVL_Desordenado();

            printf("Inserção na Árvore Rubro-Negra: \n");
            analisaLLRB_Desordenado();
            aguarda_enter();
        break;

        case 0:
            printf("\nAté mais!");
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
    /*Começa módulo de ordenação*/
   FUNC *funcionariosD = alocaEstrutura(14999);

   leArquivo(funcionariosD, "arquivos/massaDadosDesordenados.csv");

   shellSort(funcionariosD, 14999);

   escreveArquivo(funcionariosD, "arquivos/massaDadosOrdenados.csv");

   liberaEstrutura(funcionariosD);

   /*Começa módulo de leitura*/
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
 /*Começa módulo de ordenação*/
   FUNC *funcionariosD = alocaEstrutura(14999);

   leArquivo(funcionariosD, "arquivos/massaDadosDesordenados.csv");

   shellSort(funcionariosD, 14999);

   escreveArquivo(funcionariosD, "arquivos/massaDadosOrdenados.csv");

   liberaEstrutura(funcionariosD);

   /*Começa módulo de leitura*/
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
