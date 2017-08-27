#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int Primo(int numero)
{
    int i;
    
    if(numero < 2)
        return 0;
    else if(numero == 2)
        return 1;
    else
        for(i = 2;i < numero;i++)
        {
            if(numero % i == 0)
                return 0;
        }
        
        return 1;
}

int Anterior(int numero)
{
    int k;
    if(!Primo(numero) || numero == 2)
        return 0;
    else if(numero == 3)
        return 2;
    else
    {
        if(Primo(numero - 2))
            return numero - 2;
        
        k = numero - 1;
        
        if(k % 6 != 0)
            k += 2;
        
        while(1)
        {
            k -= 6;
            if(Primo(k + 1))
                return k + 1;
            else if(Primo(k - 1))
                return k - 1;
        }
    }
}

int Proximo(int numero)
{
    int k;
    if(!Primo(numero))
        return 0;
    else if(numero == 2)
        return 3;
    else
    {
        if(Primo(numero + 2))
            return numero + 2;
        
        k = numero - 1;
            
        if(k % 6 != 0)
                k += 2;
        while(1)
        {
            k += 6;
            
            if(Primo(k - 1))
                return k - 1;
            else if(Primo(k + 1))
                return k + 1;
        }
    }
}

int main()
{
    int numero = 0, anterior1 = 0, anterior2 = 0, proximo1 = 0, proximo2 = 0;
    //clock_t inicio, fim;
    //double seila;
    
    while(!numero)
    {
        scanf("%d", &numero);
        if(Primo(numero))
        {
            //inicio = clock();
            printf("É primo.\n");
            anterior1 = Anterior(numero);
            if(anterior1 != 0)
            {
                printf("Primo anterior 1: %d\n", anterior1);
                anterior2 = Anterior(anterior1);
                if(anterior2 != 0)
                    printf("Primo anterior 2: %d\n", anterior2);
                else
                    printf("Não há primo anterior.\n");
            }
            else
                printf("Não há primo anterior.\n");
            proximo1 = Proximo(numero);
            proximo2 = Proximo(proximo1);
            printf("Próximo primo 1: %d\n", proximo1);
            printf("Próximo primo 2: %d\n", proximo2);
            //fim = clock();
            
            //seila = (double)(fim-inicio)/CLOCKS_PER_SEC;
            //printf("%f\n", seila);
        }
        else
        {
            printf("Não é primo.\n");
            numero = 0;
        }
    }
}
