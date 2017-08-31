#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Funcionario
{
    char Nome[35];
    char Sexo;
    int PecasProduzidas;
}Funcionario;

int QuantidadePecasSexo(Funcionario *funcionario, int numeroFuncionarios, char sexo)
{
    int i = 0, total = 0;
    for(i = 0; i < numeroFuncionarios; i++)
    {
        if(funcionario[i].Sexo == sexo)
            total += funcionario[i].PecasProduzidas;
    }

    return total;
}

char* FuncionarioDoMes(Funcionario *funcionario, int numeroFuncionarios)
{
    int i = 0, j = 0;
    for(i = 1; i < numeroFuncionarios; i++)
    {
        if(funcionario[i].PecasProduzidas > funcionario[j].PecasProduzidas)
            j = i;
    }

    return funcionario[j].Nome;
}

int main()
{
    int numeroFuncionarios = 5;
    Funcionario funcionarios[numeroFuncionarios];

    strcpy(funcionarios[0].Nome,"João");
    funcionarios[0].Sexo = 'M';
    funcionarios[0].PecasProduzidas = 10;

    strcpy(funcionarios[1].Nome,"Maria");
    funcionarios[1].Sexo = 'F';
    funcionarios[1].PecasProduzidas = 8;

    strcpy(funcionarios[2].Nome,"Arnaldo");
    funcionarios[2].Sexo = 'M';
    funcionarios[2].PecasProduzidas = 2;

    strcpy(funcionarios[3].Nome,"Fernanda");
    funcionarios[3].Sexo = 'F';
    funcionarios[3].PecasProduzidas = 12;

    strcpy(funcionarios[4].Nome,"José");
    funcionarios[4].Sexo = 'M';
    funcionarios[4].PecasProduzidas = 5;

    printf("Quantidade de Peças produzidas por mulheres: %d\n", QuantidadePecasSexo(funcionarios, numeroFuncionarios, 'F'));
    printf("Quantidade de Peças produzidas por homens: %d\n", QuantidadePecasSexo(funcionarios, numeroFuncionarios, 'M'));

    printf("Funcionário(a) do mês: %s\n", FuncionarioDoMes(funcionarios, numeroFuncionarios));
}
