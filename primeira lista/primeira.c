#include<stdio.h>
#include<stdlib.h>

void Adicionar(int *vetor, int *index, int valor)
{
    if(valor < 256)
    {
        vetor[*index] = valor;
        *index += 1;
    }
}

void Imprimir(int *vetor, int tamanho)
{
    int i = 0;
    
    printf("\n");
    
    for(i = 0; i < tamanho; i++)
        printf("%d ", vetor[i]);
    
    printf("\n");
}

void Ordenar(int *vetor, int tamanho)
{
    int i = 0, j = 0, aux = 0;
    
    for(i = 0; i < tamanho-1; i++)
    {
        for(j = (i + 1); j < tamanho; j++)
        {
            if(vetor[i] < vetor[j])
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

void ContarParesImpares(int *vetor, int tamanho, int *par, int *impar)
{
    int i = 0;
    
    for(i = 0; i < tamanho; i++)
    {
        if(vetor[i] % 2 == 0)
            *par = *par + 1;
    }
    
    *impar = tamanho - *par;
}

int MediaImpares50(int *vetor, int tamanho)
{
    int i = 0, media = 0, j = 0;
    for(i = 0; i < tamanho; i++)
    {
        if(vetor[i] > 50 && vetor[i] % 2 == 0)
        {
            media += vetor[i];
            j++;
        }
    }
    if(j != 0)
        media /= j;
    
    return media;
}

int main()
{
    int tamanho = 10, vetor[tamanho], i = 0, j = 0, par = 0, impar = 0;
    
    while(i < tamanho)
    {
        scanf("%d", &j);
        Adicionar(vetor, &i, j);
    }
    
    Imprimir(vetor, tamanho);
    
    Ordenar(vetor, tamanho);
    
    Imprimir(vetor, tamanho);
    
    ContarParesImpares(vetor, tamanho, &par, &impar);
    
    printf("\nPares: %d\n", par);
    printf("Ímpares: %d\n", impar);
    
    
    printf("Média: %d\n", MediaImpares50(vetor, tamanho));
}
