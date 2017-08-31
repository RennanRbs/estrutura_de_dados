#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Pessoa
{
    char Nome[35];
    char Endereco[100];
    int Telefone;
    char Situacao;
}Pessoa;

void AdicionarPessoa(Pessoa *agenda, char *nome, char *endereco, int telefone, int *numerodecontatos)
{
    strcpy(agenda[*numerodecontatos].Nome, nome);
    strcpy(agenda[*numerodecontatos].Endereco, endereco);
    agenda[*numerodecontatos].Telefone = telefone;
    agenda[*numerodecontatos].Situacao = 'L';
    *numerodecontatos += 1;
    
}

int PesquisarPessoa(Pessoa *agenda, char *nome, int *numerodecontatos)
{
    int i = 0;
    for(i = 0; i < *numerodecontatos; i++)
    {
        if(!strcmp(agenda[i].Nome,nome))
            return i;
    }
    
    return -1;
}

void AlterarNome(Pessoa *agenda, char *nome, int indice)
{
    strcpy(agenda[indice].Nome, nome);
}
    
void AlterarEndereco(Pessoa *agenda, char *endereco, int indice)
{
    strcpy(agenda[indice].Endereco, endereco);
}
    
void AlterarTelefone(Pessoa *agenda, int telefone, int indice)
{
    agenda[indice].Telefone = telefone;
}

void AlterarSituacao(Pessoa *agenda, char situacao, int indice)
{
    agenda[indice].Situacao = situacao;
}

int main()
{
    int tamanho = 5, numerodecontatos = 0, telefone, achou = 0;
    Pessoa agenda[tamanho];
    char opcao, nome[35], endereco[100], situacao;
    
    while(1)
    {
        printf("\n\n");
        printf("1 - Inserir pessoa\n");
        printf("2 - Pesquisar em contatos\n");
        printf("3 - Alterar um contato\n");
        printf("Qualquer outra tecla - Sair\n");
        printf("Opção: ");
        scanf("%c", &opcao);
        
        if(opcao == '1')
        {
            if(numerodecontatos >= 5)
                printf("Agenda cheia\n");
            else
            {
                printf("Nome: ");
                scanf("%s", nome);
                printf("Endereço: ");
                scanf("%s", endereco);
                printf("Telefone: ");
                scanf("%d", &telefone);
                getchar();
                
                AdicionarPessoa(agenda, nome, endereco, telefone, &numerodecontatos);
            }
        }
        else if(opcao == '2')
        {
            printf("Nome: ");
            scanf("%s", nome);
            getchar();
            achou = PesquisarPessoa(agenda, nome, &numerodecontatos);
            
            if(achou == -1)
                printf("Achou não\n");
            else
            {
                printf("\n");
                printf("Nome: %s\n", agenda[achou].Nome);
                printf("Endereço: %s\n", agenda[achou].Endereco);
                printf("Telefone: %d\n", agenda[achou].Telefone);
                printf("Situação: %c\n", agenda[achou].Situacao);
            }
        }
        else if(opcao == '3')
        {
            printf("Nome: ");
            scanf("%s", nome);
            getchar();
            achou = PesquisarPessoa(agenda, nome, &numerodecontatos);
            
            if(achou == -1)
                printf("Achou não\n");
            else
            {
                printf("\n");
                printf("Nome: %s\n", agenda[achou].Nome);
                printf("Endereço: %s\n", agenda[achou].Endereco);
                printf("Telefone: %d\n", agenda[achou].Telefone);
                printf("Situação: %c\n", agenda[achou].Situacao);
                
                printf("Alterar nome? S - Sim N - Não ");
                scanf("%c", &opcao);
                getchar();
                if(opcao == 'S')
                {
                    printf("Nome: ");
                    scanf("%s", nome);
                    getchar();
                    AlterarNome(agenda, nome, achou);
                }
                
                printf("Alterar endereço? S - Sim N - Não ");
                scanf("%c", &opcao);
                getchar();
                if(opcao == 'S')
                {
                    printf("Endereço: ");
                    scanf("%s", endereco);
                    getchar();
                    AlterarEndereco(agenda, endereco, achou);
                }
                
                printf("Alterar telefone? S - Sim N - Não ");
                scanf("%c", &opcao);
                getchar();
                if(opcao == 'S')
                {
                    printf("Telefone: ");
                    scanf("%d", &telefone);
                    getchar();
                    AlterarTelefone(agenda, telefone, achou);
                }
                
                printf("Alterar situação? S - Sim N - Não ");
                scanf("%c", &opcao);
                getchar();
                if(opcao == 'S')
                {
                    printf("Situação(L, X, *): ");
                    scanf("%c", &situacao);
                    getchar();
                    AlterarSituacao(agenda, situacao, achou);
                }
            }
        }
        else
            break;
    }
}
