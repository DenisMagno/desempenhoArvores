#include <stdio.h>
#include <stdlib.h>
#include "algoritomoOrdenacao.h"

void shellSort(FUNC funcionarios[], int tamanho) {
    int i , j;
    FUNC value;
    int gap = 1;
    while(gap < tamanho) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap = gap / 3;
        for(i = gap; i < tamanho; i++){
            value = funcionarios[i];
            j = i - gap;
            while (j >= 0 && value.codigo < funcionarios[j].codigo) {
                funcionarios [j + gap] = funcionarios[j];
                j =j - gap;
            }
                funcionarios [j + gap] = value;
        }
    }
}
