#include "stdio.h"
#include "locale.h"

#define ex5

#ifdef ex1

/*
1 - Escreva um programa que receba via teclado um tempo em segundos e converta
    para horas, minutos e segundos.
    Ex.: recebe 3850 segundos que converte para 1h 4min 10s.
*/

main()
{

    unsigned int seg, hora, minuto, segundo, abater;

    setlocale(LC_ALL, "");

    printf("\nDigite um intervalo de tempo, em segundos: ");
    scanf("%d", &seg);

    hora= seg/3600;
    abater = 3600*hora;
    minuto= (seg-abater)/60;
    segundo= (seg-abater)%60;

    printf("\nO intervalo corresponde a: %dh %dmin %ds", hora, minuto, segundo);

    return 0;

}

#endif // ex1

#ifdef ex2

/*
2 - Escreva um programa que receba dados via teclado para variaveis do tipo short,
    long, int, float, double e um char e imprima-os no video no seguinte
    formato:

             10        20        30        40        50        60
     12345678901234567890123456789012345678901234567890123456789012345
         short               long                int
                   float               double              char
*/

main()
{
    short S;
    long L;
    int I;
    float F;
    double D;
    char C;

    setlocale(LC_ALL, "");

    printf("Digite três números inteiro:\n");
    scanf("%hd", &S);
    scanf("%ld", &L);
    scanf("%hd", &I);
    printf("\nDigite dois números reais:\n");
    scanf("%g", &F);
    scanf("%lf", &D);
    getchar();
    printf("\nDigite um caracter:\n");
    C= getchar();

    printf("        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");

    printf("    %-11hd         %-11ld         %-11d\n", S, L, I);
    printf("              %-8.1e            %-9.1e           %-c", F, D, C);

    return 0;
}

#endif // ex2

/*
3 - Escreva um programa que permute o conteúdo de duas variáveis sem utilizar uma
    variável auxiliar.
*/

#ifdef ex3

int main()
{
    int a, b;

    setlocale(LC_ALL, "");

    printf("Digite os dois valores:");
    scanf("%d %d", &a, &b);

    a= a+b;
    b= a-b;
    a= a-b;

    printf("\nValores novos: a: %d / b: %d", a, b);

    return 0;
}

#endif // ex3

/*
4 - Faça um programa para ler um numero inteiro, positivo de tres digitos, e gerar
    outro número formado pelos dígitos invertidos do número lido.
*/

#ifdef ex4

int main()
{
    int num, invert;

    setlocale(LC_ALL, "");

    printf("Digite um numero inteiro com três dígitos:\nNúmero informado: ");
    scanf("%i", &num);

    printf("\nNúmero invertido: ", num);

    invert= num%10;
    printf("%i", invert);
    num/=10;
    invert= num%10;
    printf("%i", invert);
    num/=10;
    printf("%i\n", num);

    return 0;
}

#endif // ex4

/*
5 - Escreva um programa que determine o menor multiplo de um numero inteiro. Este
    multiplo deve ser maior que o limite minimo recebido. Recebe os 2 numeros via
    teclado.
*/

#ifdef ex5

int main()
{
    int numero, limite, auxiliar;

    setlocale(LC_ALL, "");

    printf("Digite um número inteiro qualquer: ");
    scanf("%d", &numero);

    printf("\nDigite o limite para verificações dos múltiplos: ");
    scanf("%d", &limite);

    if(numero>limite)
    {
        printf("\nO menor múltiplo é o próprio número informado: %d", numero);
    }

    else
    {

        auxiliar= numero;

        do
        {
            numero+=auxiliar;
        }
        while(numero<=limite);

    }

    printf("\nTendo como limite %d, este é o menor múltiplo encontrado: %d\n", limite, numero);

    return 0;
}

#endif // ex5
