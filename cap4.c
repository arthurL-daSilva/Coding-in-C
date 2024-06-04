#include "stdio.h"
#include "locale.h"

#define ex1

#ifdef ex1

/*
1 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de ordem impar
    e o outro tera´ as componentes de ordem par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 9}, o programa
    deve gerar os vetores u = {3, 6, 1, 2, 7} e w = {5, 8, 4, 3, 9}.
*/

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");

    int num[10], indice_impar[5], indice_par[5], cont, conti, contp;
    char opcao;

    do
    {
        conti= 0;
        contp= 0;

        printf("\nDigite dez valores quaisquer:");

        for(cont=0; cont<10; cont++)
        {
            printf("\n\tValor %d: ", cont+1);
            scanf("%d", &num[cont]);

            if(cont%2==0)
            {
                indice_par[contp]= num[cont];
                contp++;
            }

            else
            {
                indice_impar[conti]= num[cont];
                conti++;
            }
        }

        printf("\nEstes são os valores dos vetores:\n\tNúmeros informados:");

        for(cont=0; cont<10; cont++)
        {
            printf(" %d", num[cont]);
        }

        printf("\n\tVetor par:");

        for(cont=0; cont<contp; cont++)
        {
            printf(" %d", indice_par[cont]);
        }

        printf("\n\tVetor ímpar:");

        for(cont=0; cont<conti; cont++)
        {
            printf(" %d", indice_impar[cont]);
        }

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

#endif // ex1

#ifdef ex2

/*
2 - Escreva um programa que receba um vetor de inteiros com tamanho 10 e o
    decomponha em dois outros vetores. Um tera´ as componentes de valor impar
    e o outro tera´ as componentes de valor par.
    Por exemplo, se o vetor dado for v = {3, 5, 6, 8, 1, 4, 2, 3, 7, 4} o
    programa deve gerar os vetores u = {3, 5, 1, 3, 7} e w = {6, 8, 4, 2, 4}.
*/

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");

    int num[10], par[10], impar[10], cont, conti, contp, opcao;

    do
    {
        conti=0;
        contp=0;

        printf("\nInsira dez valores quaisquer:");

        for(cont=0; cont<10; cont++)
        {
            printf("\n\tValor %d: ", cont+1);
            scanf("%d", &num[cont]);

            if(num[cont]%2==0)
            {
                par[contp]= num[cont];
                contp++;
            }

            else
            {
                impar[conti]= num[cont];
                conti++;
            }
        }

        printf("\nEstes são os valores dos vetores:\n\tNúmeros informados:");

        for(cont=0; cont<10; cont++)
        {
            printf(" %d", num[cont]);
        }

        printf("\n\tVetor par:");

        for(cont=0; cont<contp; cont++)
        {
            printf(" %d", par[cont]);
        }

        printf("\n\tVetor ímpar:");

        for(cont=0; cont<conti; cont++)
        {
            printf(" %d", impar[cont]);
        }

        opcao= reiniciar(reiniciar);

    }
    while(opcao==1);
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar(1 para sim / 2 para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex2

#ifdef ex3

/*
3 - Defina 2 vetores bidimensionais do tipo inteiro de 2x3. Escreva um programa
    que recebe os dados via teclado para esses 2 vetores. Usando o operador
    adicao "+", some os elementos de mesmo indice dos 2 vetores e guarde o
    resultado em um 3. vetor. Imprima na tela o indice, os valores e o resultado
    dos 6 elementos dos vetores.
*/

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");

    int vetor1[2][3], vetor2[2][3], vetor3[2][3], cont, opcao;

    do
    {
        printf("\nDigite os valores do primeiro vetor:");

        for(cont=0; cont<3; cont++)
        {
            printf("\n\tColuna 0, linha %d: ", cont);
            scanf("%d", &vetor1[0][cont]);

            if(cont==2)
            {
                for(cont=0; cont<3; cont++)
                {
                    printf("\n\tColuna 1, linha %d: ", cont);
                    scanf("%d", &vetor1[1][cont]);
                }
            }
        }

        printf("\nDigite os valores do segundo vetor:");

        for(cont=0; cont<3; cont++)
        {
            printf("\n\tColuna 0, linha %d: ", cont);
            scanf("%d", &vetor2[0][cont]);

            if(cont==2)
            {
                for(cont=0; cont<3; cont++)
                {
                    printf("\n\tColuna1, linha %d: ", cont);
                    scanf("%d", &vetor2[1][cont]);
                }
            }
        }

        for(cont=0; cont<3; cont++)
        {
            vetor3[0][cont]= (vetor1[0][cont] + vetor2[0][cont]);

            if(cont==2)
            {
                for(cont=0; cont<3; cont++)
                {
                    vetor3[1][cont]= (vetor1[1][cont] + vetor2[1][cont]);
                }
            }
        }

        printf("\nEstes são os valores armazenados nos vetores:\n");

        printf("\nVetor 1:");

        for(cont=0; cont<3; cont++)
        {
            printf("\n\tColuna 0, linha %d: %d", cont, vetor1[0][cont]);

            if(cont==2)
            {
                for(cont=0; cont<3; cont++)
                {
                    printf("\n\tColuna 1, linha %d: %d", cont, vetor1[1][cont]);
                }
            }
        }

        printf("\nVetor 2:");

        for(cont=0; cont<3; cont++)
        {
            printf("\n\tColuna 0, linha %d: %d", cont, vetor2[0][cont]);

            if(cont==2)
            {
                for(cont=0; cont<3; cont++)
                {
                    printf("\n\tColuna 1, linha %d: %d", cont, vetor2[1][cont]);
                }
            }
        }

        printf("\nVetor 3:");

        for(cont=0; cont<3; cont++)
        {
            printf("\n\tColuna 0, linha %d: %d", cont, vetor3[0][cont]);

            if(cont==2)
            {
                for(cont=0; cont<3; cont++)
                {
                    printf("\n\tColuna 1, linha %d: %d", cont, vetor3[1][cont]);
                }
            }
        }


        opcao= reiniciar(reiniciar);

    }
    while(opcao==1);

}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar(1 para sim / 2 para não)? \nResposta: ");
    scanf("%d", &opcao);

    while(opcao!=1 && opcao!=2)
    {
        printf("\nOpcão inválida. Digite '1' para continuar a execução e '2' para encerrar o programa: \nResposta: ");
        scanf("%d", &opcao);
    }

    return opcao;
}

#endif // ex3

#ifdef ex4

/*
4 - Receba via teclado 10 valores inteiros e ordene por ordem crescente assim
    que sao digitados. Guarde-os em um vetor. Mostre ao final os valores
    ordenados.
*/

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");
    int numeros[10]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, opcao, cont, cont2, aux;

    do
    {
        printf("\nDigite 10 valores quaisquer:");

        for(cont=0; cont<10; cont++)
        {
            printf("\n\tValor %d: ", cont+1);
            scanf("%d", &numeros[cont]);

            for(cont2=0; cont2<10; cont2++)
            {
                if(numeros[cont]<numeros[cont2])
                {
                    aux= numeros[cont];
                    numeros[cont]= numeros[cont2];
                    numeros[cont2]=aux;
                }
            }
        }

        printf("\n\nRestulado final:");

        for(cont=0; cont<10; cont++)
        {
            printf(" %d", numeros[cont]);
        }

        opcao= reiniciar(reiniciar);

    }
    while(opcao==1);
}

int reiniciar(int opcao)
{
    printf("\n\nDeseja continuar(1 para sim / 2 para não)? \nResposta: ");
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
5 - Escreva um programa para receber via teclado em vetores 3 int, 3 long,
    3 unsigned, 3 float e 3 double e imprima-os no video no seguinte formato:

            10        20        30        40        50
    12345678901234567890123456789012345678901234567890
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
      int                 long                unsigned
                float               double
*/

#ifdef ex5

int reiniciar(int opcao);

main()
{
    setlocale(LC_ALL, "");

    int intvar [3], cont, opcao;
    long int longvar [3];
    unsigned unsignedvar [3];
    float floatvar [3];
    double doublevar [3];

    do
    {
        printf("\nDigite três números quaisquer para cada tipo de variável:");

        for(cont=0; cont<3; cont++)
        {
            printf("\n\tint, valor %d: ", cont+1);
            scanf("%d", &intvar[cont]);
        }

        for(cont=0; cont<3; cont++)
        {
            printf("\n\tlong, valor %d: ", cont+1);
            scanf("%ld", &longvar[cont]);
        }

        for(cont=0; cont<3; cont++)
        {
            printf("\n\tunsigned, valor %d: ", cont+1);
            scanf("%u", &unsignedvar[cont]);
        }

        for(cont=0; cont<3; cont++)
        {
            printf("\n\tfloat, valor %d: ", cont+1);
            scanf("%g", &floatvar[cont]);
        }

        for(cont=0; cont<3; cont++)
        {
            printf("\n\tdouble, valor %d: ", cont+1);
            scanf("%lf", &doublevar[cont]);
        }

        printf("\n        10        20        30        40        50");
        printf("\n12345678901234567890123456789012345678901234567890");

        for(cont=0; cont<3; cont++)
        {
            printf("\n  %-11d         %-11ld         %-u", intvar[cont], longvar[cont], unsignedvar[cont]);
            printf("\n            %-8.1e            %-9.1e", floatvar[cont], doublevar[cont]);

        }

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

#endif // ex5
