#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define FALSE 0
#define TRUE !FALSE


/*Cada elemento pode ser um
Numero ou um operador.
Caso o caractere seja '_'
    o valor significa
    um Numero
Sen�o
    O valor significa um Operador
    no char operador.
*/

	typedef struct no{ //criando a struct
	int numero;
	char operador;
	struct no *proximo;}No;


	No* inserirInicio(No* lista, char conteudo){ //inserindo na pilha de operador
					No* novo = (No*)malloc(sizeof(No)); //realocando o espaco da pilha
					novo->operador = conteudo; //novo-> operador recebe conteudo
					novo->proximo = lista; //empilha o operador
					return novo;}


	No* inserirNumero(No* lista, int conteudo){ //Inserindo na pilha de numeros
				No* novo = (No*)malloc(sizeof(No)); //realocando espaco
				novo->operador = '_'; //para receber o numero da pilha de numeros
				novo->numero = conteudo; //novo recebe o centeudo
				novo->proximo = lista; //empilha o numero
				return novo;}

void noPrint(No*no){ //pritando
				if(no->operador == '_'){ //se o operador for '_' ira executar a pilha de numeros
					printf("%d", no->numero);}
				else{ //caso contrario executa a pilha de operadores
					printf("%c", no->operador);}


}
void boxListar(No* lista){ //printando a lista de opera��es feitas de uma por uma
				No *p;
				printf("\n\n>>>>>>>>>>RESULTADO<<<<<<<<<<\n\n");
				for(p = lista; p != NULL; p = p->proximo){
					noPrint(p);}
				printf("\n\n>>>>>>>>>>>>>>><<<<<<<<<<<<<<\n\n");}

No* strEmpilhar(char *palavra){ //criando struct
				int i, flag;
				char subPalavra[100];
				No*lista = NULL;

				flag = 0; //definindo uma flag
				for(i = 0; TRUE; i++){ //de 0 ate onde for verdadeiro
					if(isdigit(palavra[i])){ //verificando se e decimal
						subPalavra[flag] = palavra[i]; //subpalavra[flag] recebe a palvra[i]
						subPalavra[flag+1] = '\0'; //define a subpalavra seguinte com '\0'
						flag++;}

					else{ //caso n seja decimal
						if(flag){
							subPalavra[i] = '\0'; //define a iesima subpalavra com '\0'
							lista =  inserirNumero(lista, atoi(subPalavra)); //lista recebe o inserir numero(lista, com a conversao da subpalvra para int
							subPalavra[0] = '\0'; //o primeiro elemento recebe '\0'
							flag = 0;} //flag volta a ser 0}
						if(palavra[i] != '\0'){ //se a iesima palavra for diferente de '\0'
							lista = inserirInicio(lista, palavra[i]);} //lista recebe o inserir inicio
						else{
							break;}
					}
				}
				return lista;}


No* excluirPrimeiro(No*lista){ //desempilhando o ultimo elemento a ser empilhado
		    No*excluido;
		    excluido = lista;
		    lista = lista->proximo;
		    free(excluido);
		    return lista;
}

int opera(int a, int b, char operador){ //definindo as operacoes
			switch(operador){
				case '+':
					printf("\n%d+%d=%d\n", b, a, a+b);
					return  a+b;
				break;
				case '-':
					printf("\n%d-%d=%d\n", b, a, b-a);
					return b-a;
				break;
				case '/':
					printf("\n%d/%d=%d\n", b, a, b/a);
					return b/a;
				break;
				case '*':
					printf("\n%d*%d=%d\n",b, a, b*a);
					return a*b;
				break;
				default:
					return  a+b;
				break;}

}



No* resolvePilha(No* lista){ //resolvendo/desempilhando os valores
				No *p;

				for(p = lista;p->proximo != NULL ; p = p->proximo){
					if(p->proximo->proximo != NULL){
						p->proximo->proximo->numero = opera(p->numero, p->proximo->proximo->numero, p->proximo->operador);
						p = excluirPrimeiro(p); //desempilhando o numero
						p = excluirPrimeiro(p);} //desempilhando o operador}

					 p = resolvePilha(p);
					 break;}

				return p;}

int main()
{
	No*lista = NULL;
	char palavra[100] = "4*1-10+4*4";

	printf("Equacao: %s\n", palavra);
	lista = strEmpilhar(palavra);
	lista = resolvePilha(lista);
	boxListar(lista);

	return 0;
}
