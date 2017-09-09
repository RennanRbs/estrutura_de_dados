#include<stdio.h>
#include<stdlib.h>


int ehPrimo(int num){
    //ve se eh primo, retorna 0 se nao, retorna 1 se sim
    int cont;
    if(num==1 || num==0)
        return 0;
    for(cont = 2; cont < num/2+1; cont++)
        if(num%cont==0)
            return 0;
    return 1;}


int encontrarPrimoAnterior(int num, int *primos, int nPrimos){
    //encontrar um primo a partir de um numero dado, sendo primo ou nao, anteriror
    int cont, primosEncontrados = 0;

    for(cont = num-1; cont>1 && primosEncontrados<nPrimos; cont--)
        if(ehPrimo(cont))
            primos[primosEncontrados++] = cont;
    if(primosEncontrados<nPrimos)
        return primosEncontrados;
    return -1;
}

int encontrarPrimosucessor(int num, int *primos, int nPrimos){
    //encontrar um primo a partir de um numero dado, sendo primo ou nao, sucessor
    int cont, primosEncontrados = 0;
    for(cont = num+1; primosEncontrados<nPrimos; cont++)
        if(ehPrimo(cont))
            primos[primosEncontrados++] = cont;
            return primosEncontrados;
}


void printVetor(int *vetor, int size){
    int cont;
    for(cont=0; cont<size; cont++)
        printf("[ %d ]", vetor[cont]);
}
int main(){
  //variáveis
  int num,primos[2],retorno;


    while(1){

      printf("Qual Numero voce quer testar?????");
      scanf("%d", &num);

              if(ehPrimo(num)==1){
                          printf("O Numero Informado eh Primo\n");
                          retorno = encontrarPrimoAnterior(num, primos, 2);


              if(retorno!=-1){
                          printf("Sos Foi Possivel encontrar %d antecessor%s", retorno, retorno>1?"es:":retorno==0?"":":");
                          printVetor(primos, retorno);}


              else{
                          printf("Os Dois Numeros Primos Antecessores Sao: ");
                          printVetor(primos, 2);}


              //encontrar os dois pirmos sucessores
              printf("\nOs Dois Numeros Primos Sucessores Sao: ");
              encontrarPrimosucessor(num, primos, 2);
              printVetor(primos, 2);
              printf("\n");
              break;
            }
            else{
                printf("O Numero Informado nao eh Primo\n");
            }

}}
