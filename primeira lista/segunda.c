#include<stdio.h>
#include<stdlib.h>

void Checar1040(int *x, int *y, int tamanhox, int *finaly)
{
    int i = 0;
    for(i = 0; i < tamanhox; i++)
    {
        if((10 <= x[i]) && (x[i] <= 40))
        {
            y[*finaly] = x[i];
            *finaly += 1;
        }
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

void PosicaoPares(int *x, int *w, int tamanho)
{
    int i = 0;
    
    for(i = 0; i < tamanho; i++)
        w[i] = x[2*i+1];
}

int BuscaSequencial(int *vetor, int tamanho, int valor)
{
    int i = 0;
    for(i = 0; i < tamanho; i++)
    {
        if(vetor[i] == valor)
        {
            return 1;
        }
        else if(i == tamanho-1)
            return 0;
    }
}

int Maior(int *x, int tamanho)
{
    int i = 0, maior = x[i];
    for(i = 0; i < tamanho; i++)
    {
        if(x[i] > maior)
            maior = x[i];
    }
    return maior;
}

int Menor(int *x, int tamanho)
{
    int i = 0, menor = x[i];
    for(i = 0; i < tamanho; i++)
    {
        if(x[i] < menor)
            menor = x[i];
    }
    return menor;
}

int main()
{
    int tamanho = 10, x[tamanho], y[tamanho], w[tamanho/2], i = 0, finaly = 0, tem = 0;
    
    for(i = 0; i < tamanho; i++)
        scanf("%d", &x[i]);
    
    Imprimir(x, tamanho);
    
    Checar1040(x, y, tamanho, &finaly);
    
    Imprimir(y, finaly);
    
    PosicaoPares(x, w, tamanho);
    
    Imprimir(w, tamanho/2);
    
    scanf("%d", &tem);
    
    tem = BuscaSequencial(x, tamanho, tem);
    
    if(tem)
        printf("tem\n");
    else
        printf("não tem\n");
    
    printf("Maior: %d\nMenor: %d\n", Maior(x, tamanho), Menor(x, tamanho));
}
