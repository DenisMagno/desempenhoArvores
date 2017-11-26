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
            // Chama o método
            aguarda_enter();
        break;

        case 2:
            // Chama o método
            aguarda_enter();
        break;

        case 0:
            printf("\nAté mais!");
            aguarda_enter();
            exit(1);
        break;
    }
}
