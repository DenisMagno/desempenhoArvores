#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "libPrincipal.h"

int main(){
    setlocale(LC_ALL, "portuguese");

     /* Sistema ininterrupto */
    int opt;
    do{
        imprime_menu();

        opt = solicita_opcao();

        redireciona_para_opcao(opt);
    }while(opt);
}
