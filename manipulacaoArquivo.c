#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "manipulacaoArquivo.h"

//Função que lê arquivo e insere os dados "DE UMA LINHA" em "UMA STRUCT" (Ainda é necessário finalizar)
//param FUNC (Recebe um vetor de funcionarios previamente criado)
//param char (recebe o diretório do arquivo a ser lido);
void leArquivo(FUNC funcionarios[], char url[]){
    setlocale(LC_ALL, "portuguese");

    FILE *arq;

	//ABRE O ARQUIVO
	arq = fopen(url, "r");

	//VERIFICA SE O ARQUIVO ABRIU NORMALMENTE
	if(arq == NULL){
	    printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{

        //Variavel que guarda caracter por caracter recebido do arquivo.
        char ch;

        //i = representa cada linha do arquivo(estrutura); j = representa cada coluna(elemento da estrutura);
        //indice = representa cada caracter de cada campo da estrutura
        int i = 0, j = 1, indice = 0;

        //variáveis auxiliares para conversão de char para int ou float
        char codigo[255], idade[255], salario[255];

        //Laço de repetição que roda até encontrar o final do arquivo
        do{
            //pega primeiro caracter ou próximo caracter(se ja rodou uma vez);
            ch = fgetc(arq);

            //Define o campo em que o ponteiro do char está.
            if(ch == ';'){
                ch = fgetc(arq);
                indice = 0;
                j++;
            }

            //Define a linha em que o ponteiro do char está.
            if(ch == '\n'){
                //Finaliza todas as strings auxiliares e passa os valores para a estrutura
                codigo[indice] = '\0';
                sscanf(codigo, "%d", &funcionarios[i].codigo);
                idade[indice] = '\0';
                sscanf(idade, "%d", &funcionarios[i].idade);
                salario[indice] = '\0';
                sscanf(salario, "%f", &funcionarios[i].salario);

                ch = fgetc(arq);
                indice = 0;
                i++;
                j = 1;
            }

            //Seção de verificação de campo para inserção dos caracteres no mesmo
            if(j == 1){
                codigo[indice] = ch;
            }

            if(j == 2){
                funcionarios[i].nome[indice] = ch;
            }

            if(j == 3){
                 idade[indice] = ch;
            }

            if(j == 4){
                funcionarios[i].empresa[indice] = ch;
            }

            if(j == 5){
                funcionarios[i].departamento[indice] = ch;
            }

            if(j == 6){
                salario[indice] = ch;
            }

            indice++;
        }while(ch != EOF);
    }

    //FECHA O ARQUIVO
	fclose(arq);
}

//Função que lê estrutura e insere os dados "DE UMA STRUCT" em "UM ARQUIVO"
//param FUNC (Recebe um vetor de funcionarios previamente criado e populado com dados)
//param char (recebe o diretório do arquivo a ser preenchido);
void escreveArquivo(FUNC funcionarios[], char url[]){
    setlocale(LC_ALL, "portuguese");

    FILE *arq;

	//ABRE O ARQUIVO
	arq = fopen(url, "w");

	//VERIFICA SE O ARQUIVO ABRIU NORMALMENTE
	if(arq == NULL){
	    printf("Erro, nao foi possivel abrir o arquivo\n");
    }else{

        int i;
        for(i = 0; i < 14999; i++){
            fprintf(arq, "%d;", funcionarios[i].codigo);
            fprintf(arq, "%s;", funcionarios[i].nome);
            fprintf(arq, "%d;", funcionarios[i].idade);
            fprintf(arq, "%s;", funcionarios[i].empresa);
            fprintf(arq, "%s;", funcionarios[i].departamento);
            fprintf(arq, "%.2f;\n", funcionarios[i].salario);
        }
    }

    //FECHA O ARQUIVO
	fclose(arq);
}
