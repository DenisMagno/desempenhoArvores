//Estrutura dos dados do sistema

typedef struct funcionario{
    int codigo;
    char nome[30];
    int idade;
    char empresa[30];
    char departamento[30];
    float salario;
}FUNC;

int alocaEstrutura(int tamanho);
void liberaEstrutura(FUNC *funcionarios);
