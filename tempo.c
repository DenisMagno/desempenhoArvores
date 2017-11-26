#include <stdio.h>
#include <stdlib.h>
#include "tempo.h"

//retorna o clock atual (Tempo)
clock_t retornaTempoAtual(){
    return clock();
}

//retorna o calculo dos tempos passados
double retornaTempoCalculado(clock_t tInicio, clock_t tFim){
    double tDecorrido;

    //calcula aproximadamente o tempo em milisegundos gasto entre as duas chamadas de clock()
    tDecorrido = ( (double) (tFim - tInicio) ) / CLOCKS_PER_SEC;

    return tDecorrido;
}
