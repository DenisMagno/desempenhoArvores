#include "estrutura.h"
#include "manipulacaoArquivo.h"
#include "algoritomoOrdenacao.h"
#include "arvores/arvoreAVL.h"
#include "arvores/ArvoreRubroNegra.h"
#include "tempo.h"

void aguarda_enter();
void imprime_menu();
int solicita_opcao();
void redireciona_para_opcao(int opt);

double analisaAVL_Desordenado();
double analisaLLRB_Desordenado();
double analisaAVL_Ordenado();
double analisaLLRB_Ordenado();
