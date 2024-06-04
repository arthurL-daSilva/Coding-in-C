#include "stdio.h"
#include "locale.h"

#define ex1

/*
1 - Receba 2 string de ate 10 caracteres via teclado na funcao main(). Faça uma
    funcao para compara-las e retorne como resultado se são IGUAIS 1 ou se
    DIFERENTES 0 para a funcao main(). Imprima o resultado na funcao main().
    (Declare os vetores como variavel global) (nao pode usar funcao de biblioteca)
*/

#ifdef ex1

int reiniciar(int opcao);
int comparativo();
char primeira [10], segunda [10];

main()
{
    setlocale(LC_ALL, "");

    int cont, opcao, comparacao;

    do
    {
        printf("\nPreencha a primeira string: ");
        gets(primeira);

        printf("\nPreencha a segunda string: ");
        gets(segunda);

        comparacao= comparativo();

        if(comparacao==1)
        {
            printf("\n\nAs strings são iguais.");
        }

        else
        {
            printf("\n\nAs strings são diferentes.");
        }

        opcao= reiniciar(reiniciar);
        getchar();
    }
    while(opcao==1);
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar('1' para sim / '2' para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

int comparativo()
{
    int comparacao=1, cont;

    for(cont=0; cont<10; cont++)
    {
        if(primeira[cont]!=segunda[cont])
        {
            comparacao=0;
            break;
        }
    }

    return comparacao;
}

#endif // ex1

/*
2 - Escreva um programa para receber 5 nomes, com até 7 caracteres, via teclado
    e imprima-os no video no seguinte formato:(Declare os 5 vetores como variaveis
    globais)

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      nome1                                   nome5
                nome2               nome4
                          nome3
*/

#ifdef ex2

int reiniciar(int opcao);
char nome1[8], nome2[8], nome3[8], nome4[8], nome5[8];

main()
{
    setlocale(LC_ALL, "");
    int opcao, cont;

    do
    {
        printf("\nDigite cinco nomes, com até sete caracteres cada:");
        printf("\nNome 1: ");
        scanf("%s", &nome1);
        printf("\nNome 2: ");
        scanf("%s", &nome2);
        printf("\nNome 3: ");
        scanf("%s", &nome3);
        printf("\nNome 4: ");
        scanf("%s", &nome4);
        printf("\nNome 5: ");
        scanf("%s", &nome5);

        printf("\n        10        20        30        40        50");
        printf("\n12345678901234567890123456789012345678901234567890");
        printf("\n  %-9s                               %-s", nome1, nome5);
        printf("\n            %-9s           %-s", nome2, nome4);
        printf("\n                      %-s", nome3);

        opcao= reiniciar(reiniciar);
    }
    while(opcao==1);
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar('1' para sim / '2' para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex2

/*
3 - Escreva um programa que receba uma string na funcao main(). Faca uma funcao que
    calcula o comprimento de uma string recebida via teclado. Mostre o valor do
    comprimento na funcao main().
    (Declare o vetor como variavel global) (nao pode usar funcao de biblioteca)
*/

#ifdef ex3

int reiniciar(int opcao);
int contagem();
char string[20];

main()
{
    setlocale(LC_ALL, "");
    int opcao, contador;

    do
    {
        printf("\nPreencha a string: ");
        gets(string);
        contador= contagem();

        printf("\nA string digitada possuí %d caracteres.", contador);

        opcao= reiniciar(reiniciar);
        getchar();
    }
    while(opcao==1);
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar('1' para sim / '2' para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

int contagem()
{
    int cont;

    for(cont=0; cont<20; cont++)
    {
        if(string[cont]==0)
        {
            break;
        }
    }

    return cont;
}

#endif // ex3

/*
4 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras maiusculas. (nao pode usar funcao de biblioteca)
*/

#ifdef ex4

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");
    int cont, opcao, conversor;
    char string[10];

    do
    {
        printf("\nPreencha a string com letras minúsculas: ");
        gets(string);

        for(cont=0; cont<10; cont++)
        {
            if(string[cont]==0)
            {
                break;
            }

            conversor= string[cont];
            conversor-=32;
            string[cont]=conversor;
        }

        printf("\nResultado: %s", string);

        opcao= reiniciar(reiniciar);
        getchar();
    }
    while(opcao==1);
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar('1' para sim / '2' para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex4

/*
5 - Receba via teclado uma cadeia de caracteres (10) e converta todos os caracteres
    para letras minusculas. (nao pode usar funcao de biblioteca)
*/

#ifdef ex5

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");
    int cont, opcao, conversor;
    char string[10];

    do
    {
        printf("\nPreencha a string com letras maiúsculas: ");
        gets(string);

        for(cont=0; cont<10; cont++)
        {
            if(string[cont]==0)
            {
                break;
            }

            conversor= string[cont];
            conversor+=32;
            string[cont]=conversor;
        }

        printf("\nResultado: %s", string);

        opcao= reiniciar(reiniciar);
        getchar();
    }
    while(opcao==1);
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar('1' para sim / '2' para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex5
