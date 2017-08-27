#include<stdio.h>
#include<stdlib.h>

void Imprimir(int *vetor, int tamanho)
{
    int i = 0;
    
    printf("\n");
    
    for(i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    
    printf("\n");
}

void VerificarRepetidos(int *vetor, int *tamanho)
{
    int i = 0, j = 0;
    for(i = 0; i < *tamanho - 1; i++)
    {
        for(j = i + 1; j < *tamanho; j++)
        {
            if(vetor[i] == vetor[j])
            {
                vetor[j] = vetor[*tamanho - 1];
                *tamanho -= 1;
            }
        }
    }
}

void Ordenar(int *vetor, int tamanho)
{
    int i = 0, j = 0, aux = 0;
    
    for(i = 0; i < tamanho-1; i++)
    {
        for(j = (i + 1); j < tamanho; j++)
        {
            if(vetor[i] > vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int PesquisaBinaria(int *vetor, int tamanho, int valor)
{
    int i = 0, maior = tamanho-1, menor = 0, meio = tamanho/2;
    
    while(maior >= menor)
    {
        if(vetor[meio] == valor)
            return 1;
        else if(vetor[meio] < valor)
            menor = meio + 1;
        else
            maior = meio - 1;
        meio = (menor + maior) / 2;
    }
    
    return 0;
}

int main()
{
    int tamanho = 10, vetor[tamanho], tamanho2 = tamanho, numero = 0, achou = 0, i = 0;
    
    for(i = 0; i < 10; i++)
        scanf("%d", &vetor[i]);
    
    Imprimir(vetor, tamanho);
    
    VerificarRepetidos(vetor, &tamanho);
    
    if(tamanho == tamanho2)
        printf("OK\n");
    else
        printf("Número de elementos removidos: %d\n", tamanho2 - tamanho);
    
    Imprimir(vetor, tamanho);
    
    Ordenar(vetor, tamanho);
    
    Imprimir(vetor, tamanho);
    
    scanf("%d", &numero);
    
    achou = PesquisaBinaria(vetor, tamanho, numero);
    
    if(achou)
        printf("achou\n");
    else
        printf("não achou\n");
}
