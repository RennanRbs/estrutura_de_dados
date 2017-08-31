#include<stdio.h>
#include<stdlib.h>

void PreencherMatriz(int linhas, int colunas, int matriz[linhas][colunas])
{
    int i = 0, j = 0;
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void ImprimirMatriz(int linhas, int colunas, int matriz[linhas][colunas])
{
    int i = 0, j = 0;
    printf("\n");
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            printf("%d      ", matriz[i][j]);
        }
        printf("\n");
    }
}

void MultiplicarMatriz(int linhasa, int colunasa, int linhasb, int colunasb, int A[linhasa][colunasa], int B[linhasb][colunasb], int C[linhasa][colunasb])
{
    int i = 0, j = 0, k = 0;
    if(colunasa != linhasb)
        return;
    else
    {
        for(i = 0; i < linhasa; i++)
        {
            for(j = 0; j < colunasb; j++)
            {
                C[i][j] = 0;
            }
        }

        for(i = 0; i < linhasa; i++)
        {
            for(j = 0; j < colunasb; j++)
            {
                for(k = 0; k < colunasa; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
}

int main()
{
    int tamanho1 = 5, tamanho2 = 4, tamanho3 = 3, A[tamanho1][tamanho2], B[tamanho2][tamanho3], C[tamanho1][tamanho3];
    
    printf("Preencher Matriz A\n");
    PreencherMatriz(tamanho1, tamanho2, A);
    printf("Matriz A");
    ImprimirMatriz(tamanho1, tamanho2, A);
    
    printf("Preencher Matriz B\n");
    PreencherMatriz(tamanho2, tamanho3, B);
    printf("Matriz B");
    ImprimirMatriz(tamanho2, tamanho3, B);

    MultiplicarMatriz(tamanho1, tamanho2, tamanho2, tamanho3, A, B, C);
    printf("Matriz C");
    ImprimirMatriz(tamanho1, tamanho3, C);
}
