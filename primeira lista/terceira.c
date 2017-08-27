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

int BuscaSequencial(int *vetor, int tamanho, int valor)
{
    int i = 0;
    for(i = 0; i < tamanho; i++)
    {
        if(vetor[i] == valor)
            return 1;
        else if(i == tamanho-1)
            return 0;
    }
}

int main()
{
    int tamanho = 10, A[tamanho], B[tamanho], C[tamanho*2], i, x;
    
    for(i = 0; i < tamanho; i++)
        scanf("%d", &A[i]);
    
    Imprimir(A, tamanho);
    
    for(i = 0; i < tamanho; i++)
        scanf("%d", &B[i]);
    
    Imprimir(B, tamanho);
    
    for(i = 0; i < tamanho; i++)
    {
        C[2*i] = A[i];
        C[2*i+1] = B[i];
    }
    
    Imprimir(C, tamanho*2);
    
    scanf("%d", &x);
    
    x = BuscaSequencial(C, tamanho*2, x);
    
    if(x)
        printf("tem\n");
    else
        printf("não tem\n");
}
