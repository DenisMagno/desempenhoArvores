#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estrutura.h"

int alocaEstrutura(int tamanho){
    FUNC *funcionarios = (FUNC*) calloc(tamanho, sizeof(FUNC));

    if(funcionarios == NULL){
        printf("Erro ao alocar estrutura!");
        exit(1);
    }else{
        return funcionarios;
    }
}

void liberaEstrutura(FUNC *funcionarios){
    free(funcionarios);
}
