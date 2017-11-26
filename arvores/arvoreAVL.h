#import "../estrutura.h"

typedef struct NO *arvAVL;

arvAVL *cria_arvAVL();

void liberar_arvAVL(arvAVL *raiz);

int vazia_arvAVL(arvAVL *raiz);

int altura_arvAVL(arvAVL *raiz);

int totalNO_arvAVL(arvAVL *raiz);

void preOrdem_arvAVL(arvAVL *raiz);

void emOrdem_arvAVL(arvAVL *raiz);

void posOrdem_arvAVL(arvAVL *raiz);

int insere_arvAVL(arvAVL *raiz, FUNC funcionario);

int remove_arvAVL(arvAVL *raiz, FUNC funcionario);

int consulta_arvAVL(arvAVL *raiz, int valor);
