#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Notas
{
    float N1;
    float N2;
    float FINAL;
}Notas;

typedef struct Aluno
{
    char Nome[35];
    Notas Nota;
}Aluno;

void InserirAluno(Aluno *alunos, char *nome, float n1, float n2, float final, int *totalinserido)
{
    strcpy(alunos[*totalinserido].Nome, nome);
    alunos[*totalinserido].Nota.N1 = n1;
    alunos[*totalinserido].Nota.N2 = n2;
    alunos[*totalinserido].Nota.FINAL = final;
    *totalinserido += 1;
}

void ImprimirAlunos(Aluno *alunos, int *totalinserido)
{
    int i = 0;
    printf("\n\n");
    for(i = 0; i < *totalinserido; i++)
    {
        printf("Nome: %s\n", alunos[i].Nome);
        printf("N1: %.1f\n", alunos[i].Nota.N1);
        printf("N2: %.1f\n", alunos[i].Nota.N2);
        printf("FINAL: %.1f\n", alunos[i].Nota.FINAL);
    }
}

int main()
{
    int total = 35, totalinserido = 0;
    float n1 = -1, n2 = -1, final = -1;
    char nome[35], opcao;
    Aluno alunos[total];
    
    while(1)
    {
        printf("\n\n");
        printf("1 - Inserir Aluno\n");
        printf("2 - Mostrar Alunos Salvos\n");
        printf("Qualquer outra tecla - Sair\n");
        printf("Opção: ");
        scanf("%c", &opcao);
        
        if(opcao == '1')
        {
            if(totalinserido < 35)
            {
                printf("Nome: ");
                scanf("%s", nome);
                while(n1 < 0 || n1 > 10)
                {
                    printf("\nN1: ");
                    scanf("%f", &n1);
                }
                while(n2 < 0 || n2 > 10)
                {
                    printf("\nN2: ");
                    scanf("%f", &n2);
                }
                while(final < 0 || final > 10)
                {
                    printf("\nFINAL: ");
                    scanf("%f", &final);
                }
                
                InserirAluno(alunos, nome, n1, n2, final, &totalinserido);
                n1 = n2 = final = -1;
            }
            else
                printf("Turma lotada\n");
            
            getchar();
        }
        else if(opcao == '2')
        {
            if(totalinserido == 0)
                printf("Turma vazia\n");
            else
            {
                ImprimirAlunos(alunos, &totalinserido);
            }
            getchar();
        }
        else
            break;
    }
}
