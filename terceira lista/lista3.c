#include<stdio.h>
#include<stdlib.h>

struct box
{
    char conteudo;
    struct box *proximo;
} *inicio, *novo, *temp1, *temp2;

void Imprimir(struct box *inicio)
{
    while(inicio != NULL)
    {
        printf("%c ", inicio->conteudo);
        inicio = inicio->proximo;
    }

    printf("\n");
}

int main()
{
    //item 1 Insira um elemento contendo a letra A no final da lista.
    inicio = (struct box*) malloc(sizeof(struct box));
    inicio->conteudo = 'A';
    inicio->proximo  = NULL;
    //item1

    getchar();
    Imprimir(inicio);

    //item2 Insira um elemento contendo a letra B no inicio da lista.
    novo = (struct box*) malloc(sizeof(struct box));
    novo->conteudo = 'B';
    novo->proximo = inicio;
    inicio = novo;
    novo = NULL;
    //item2

    getchar();
    Imprimir(inicio);

    //item3 Insira um elemento contendo a letra C no final da lista.
    temp1 = inicio;
    while(temp1->proximo != NULL)
        temp1 = temp1->proximo;

    temp1->proximo = (struct box*) malloc(sizeof(struct box));
    temp1->proximo->conteudo = 'C';
    temp1->proximo->proximo = NULL;
    temp1 = NULL;
    //item3

    getchar();
    Imprimir(inicio);

    //item4 Insira um elemento contendo a letra D no final da lista.
    temp1 = inicio;
    while(temp1->proximo != NULL)
        temp1 = temp1->proximo;

    temp1->proximo = (struct box*) malloc(sizeof(struct box));
    temp1->proximo->conteudo = 'D';
    temp1->proximo->proximo = NULL;
    temp1 = NULL;
    //item4

    getchar();
    Imprimir(inicio);

    //item5 Insira um elemento contendo a letra E entre os elementos de conteúdo A e C.
    temp1 = inicio;
    while(temp1->conteudo != 'A')
        temp1 = temp1->proximo;

    novo = (struct box*) malloc(sizeof(struct box));
    novo->conteudo = 'E';
    novo->proximo = temp1->proximo;
    temp1->proximo = novo;
    novo = NULL;
    temp1 = NULL;
    //item5

    getchar();
    Imprimir(inicio);

    //item6 Insira um elemento contendo a letra F no final da lista.
    temp1 = inicio;
    while(temp1->proximo != NULL)
        temp1 = temp1->proximo;

    temp1->proximo = (struct box*) malloc(sizeof(struct box));
    temp1->proximo->conteudo = 'F';
    temp1->proximo->proximo = NULL;
    temp1 = NULL;
    //item6

    getchar();
    Imprimir(inicio);

    //item7 Insira um elemento contendo a letra G no inicio da lista.
    novo = (struct box*) malloc(sizeof(struct box));
    novo->conteudo = 'G';
    novo->proximo = inicio;
    inicio = novo;
    novo = NULL;
    //item7

    getchar();
    Imprimir(inicio);

    //item8 Exclua o último elemento.
    temp1 = inicio;
    while(temp1->proximo->proximo != NULL)
        temp1 = temp1->proximo;

    free(temp1->proximo);
    temp1->proximo = NULL;
    temp1 = NULL;
    //item8

    getchar();
    Imprimir(inicio);

    //item9 Exclua o primeiro elemento.
    temp1 = inicio;
    inicio = inicio->proximo;
    free(temp1);
    temp1 = NULL;
    //item9

    getchar();
    Imprimir(inicio);

    //item10 Insira um elemento contendo a letra H entre os elementos de conteúdo A e E.
    temp1 = inicio;
    while(temp1->conteudo != 'A')
        temp1 = temp1->proximo;

    novo = (struct box*) malloc(sizeof(struct box));
    novo->conteudo = 'H';
    novo->proximo = temp1->proximo;
    temp1->proximo = novo;
    novo = NULL;
    temp1 = NULL;
    //item10

    getchar();
    Imprimir(inicio);

    //item11 Exclua o elemento de conteúdo A.
    temp1 = inicio;
    while(temp1->proximo->conteudo != 'A')
        temp1 = temp1->proximo;

    temp2 = temp1->proximo;
    temp1->proximo = temp2->proximo;
    free(temp2);
    temp1 = NULL;
    temp2 = NULL;
    //item11

    getchar();
    Imprimir(inicio);

    //item12 Insira um elemento contendo a letra I entre os elementos de conteúdo E e D.
    temp1 = inicio;
    while(temp1->conteudo != 'E')
        temp1 = temp1->proximo;

    novo = (struct box*) malloc(sizeof(struct box));
    novo->conteudo = 'I';
    novo->proximo = temp1->proximo;
    temp1->proximo = novo;
    novo = NULL;
    temp1 = NULL;
    //item12

    getchar();
    Imprimir(inicio);

    //item13 Insira um elemento contendo a letra J no final da lista.
    temp1 = inicio;
    while(temp1->proximo != NULL)
        temp1 = temp1->proximo;

    temp1->proximo = (struct box*) malloc(sizeof(struct box));
    temp1->proximo->conteudo = 'J';
    temp1->proximo->proximo = NULL;
    temp1 = NULL;
    //item13

    getchar();
    Imprimir(inicio);

    //item14 Insira um elemento contendo a letra K entre os elementos de conteúdo B e H.
    temp1 = inicio;
    while(temp1->conteudo != 'B')
        temp1 = temp1->proximo;

    novo = (struct box*) malloc(sizeof(struct box));
    novo->conteudo = 'K';
    novo->proximo = temp1->proximo;
    temp1->proximo = novo;
    novo = NULL;
    temp1 = NULL;
    //item14

    getchar();
    Imprimir(inicio);

    //item15 Exclua o elemento de conteúdo D, K e I.
    temp1 = inicio;
    while(temp1->proximo->conteudo != 'D')
        temp1 = temp1->proximo;

    temp2 = temp1->proximo;
    temp1->proximo = temp2->proximo;
    free(temp2);
    temp1 = NULL;
    temp2 = NULL;

    temp1 = inicio;
    while(temp1->proximo->conteudo != 'K')
        temp1 = temp1->proximo;

    temp2 = temp1->proximo;
    temp1->proximo = temp2->proximo;
    free(temp2);
    temp1 = NULL;
    temp2 = NULL;

    temp1 = inicio;
    while(temp1->proximo->conteudo != 'I')
        temp1 = temp1->proximo;

    temp2 = temp1->proximo;
    temp1->proximo = temp2->proximo;
    free(temp2);
    temp1 = NULL;
    temp2 = NULL;
    //item15

    getchar();
    Imprimir(inicio);

    //item16 Exclua o elemento de conteúdo B.
    temp1 = inicio;
    inicio = inicio->proximo;
    free(temp1);
    //item16

    getchar();
    Imprimir(inicio);

    //item17 Insira um elemento contendo a letra L no final da lista.
    temp1 = inicio;
    while(temp1->proximo != NULL)
        temp1 = temp1->proximo;

    temp1->proximo = (struct box*) malloc(sizeof(struct box));
    temp1->proximo->conteudo = 'L';
    temp1->proximo->proximo = NULL;
    temp1 = NULL;
    //item17

    getchar();
    Imprimir(inicio);
}
