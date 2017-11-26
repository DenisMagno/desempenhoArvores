#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "estrutura.h"
#include "manipulacaoArquivo.h"
#include "algoritomoOrdenacao.h"
#include "libPrincipal.h"

int main(){
    setlocale(LC_ALL, "portuguese");

    int opt;

    imprime_menu();

    opt = solicita_opcao();

    redireciona_para_opcao(opt);

    FUNC *funcionarios = alocaEstrutura(14999);

    leArquivo(funcionarios, "arquivos/massaDadosDesordenados.csv");

    shellSort(funcionarios, 14999);

    escreveArquivo(funcionarios, "arquivos/massaDadosOrdenados.csv");

    /*int i;
    for(i = 0; i < 14999; i++){
        printf("%d ", i);
        printf("%d ", funcionarios[i].codigo);
        printf("%s ", funcionarios[i].nome);
        printf("%d ", funcionarios[i].idade);
        printf("%s ", funcionarios[i].empresa);
        printf("%s ", funcionarios[i].departamento);
        printf("%.2f\n", funcionarios[i].salario);
    }*/

    liberaEstrutura(funcionarios);
}
