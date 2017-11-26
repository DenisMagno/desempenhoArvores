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
            // Chama o m�todo
            aguarda_enter();
        break;

        case 2:
            // Chama o m�todo
            aguarda_enter();
        break;

        case 0:
            printf("\nAt� mais!");
            aguarda_enter();
            exit(1);
        break;
    }
}
