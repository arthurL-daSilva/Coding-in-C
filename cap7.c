#include<stdio.h>
#include <stdlib.h>
#include<locale.h>

#define ex4

#ifdef ex1

/*1 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    Receba dados via teclado em uma funcao e imprima estes conteudos no video,
    em outra funcao, no seguinte formato.
     estrutura: char, int, long, float, double, unsigned char, unsigned int,
                unsigned long

            10        20        30        40        50        60        70
    1234567890123456789012345678901234567890123456789012345678901234567890
        char      int       long                float               double
              unsigned char       unsigned int        unsigned long
*/

struct variaveis{
    long L;
    int I;
    float F;
    double D;
    char C;
    unsigned char UC;
    unsigned int UI;
    unsigned long UL;
};

struct variaveis letras;

void pressV(){
    setlocale(LC_ALL, "");

    printf("Digite os números inteiros:\n");
    printf("Unsigned Int: ");
    scanf("%d", &letras.UI);
    printf("Long: ");
    scanf("%ld", &letras.L);
    printf("Int: ");
    scanf("%d", &letras.I);
    printf("Unsigned Long: ");
    scanf("%ld", &letras.UL);
    printf("\nDigite dois números reais:\n");
    printf("Float: ");
    scanf("%g", &letras.F);
    printf("Double: ");
    scanf("%lf", &letras.D);
    getchar();
    printf("\nDigite um caracter: ");
    letras.C = getchar();
    getchar();
    printf("Digite outro caracter: ");
    letras.UC = getchar();

}

void pressC(){
    printf("        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");

    printf("    %-c         %-7d   %-8ld            %-8.1f            %-9.1lf\n", letras.C, letras.I, letras.L, letras.F, letras.D);
    printf("          %-c                   %-ld                   %-8.1d", letras.UC, letras.UI, letras.UL);
}

int main(){
    pressV();
    pressC();
    return 0;
}

#endif // ex1

#ifdef ex2

/*2 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estruturas de 4 elementos. Receba os dados pelo teclado em uma funcao
    e imprima-os no video em uma funcao. Utilize vetor de estruturas.
    Faça um menu com uma opcao para saida do programa.
		estrutura: nome, end, cidade, estado, cep
*/

struct cadastro{
    char nome[30];
    char end[50];
    char cidade[15];
    char estado[20];
    char cep[12];
};

struct cadastro set[4];

void cads(){
    int cont;
    setlocale(LC_ALL, "");
    for(cont=0;cont<4;cont++){
        printf("Escreva os dados da pessoa %d:\n", cont+1);
        fflush(stdin);
        printf("Nome: ");
        gets(set[cont].nome);
        fflush(stdin);
        printf("Endereço: ");
        gets(set[cont].end);
        fflush(stdin);
        printf("Cidade: ");
        gets(set[cont].cidade);
        fflush(stdin);
        printf("Estado: ");
        gets(set[cont].estado);
        fflush(stdin);
        printf("CEP: ");
        gets(set[cont].cep);
        system("cls");
    }
}

void imp(int dados){
    setlocale(LC_ALL, "");
    int cont;
    if(dados == 0){printf("\nNão há dados.\n\n");}
    else{
        for(cont=0;cont<4;cont++){
          printf("\n\nDados da pessoa %d:\n-------------------------------------\n", cont+1);
          printf("Nome: %s\n", set[cont].nome);
          printf("Endereço: %s\n", set[cont].end);
          printf("Cidade: %s\n", set[cont].cidade);
          printf("Estado: %s\n", set[cont].estado);
          printf("CEP: %s\n", set[cont].cep);
        }
    }
    system("pause");
    system("cls");
}

int main(){
    int esc, dados=0;
    setlocale(LC_ALL, "");
    do{
        do{
        printf("--------------------------\n");
        printf("1 - receber todos os dados\n");
        printf("2 - mostrar todos os dados\n");
        printf("3 - sair\n");
        printf("Qual ação deseja realizar?\n");
        printf("R: ");
        scanf("%d", &esc);
        }while(esc < 1 || esc > 3);
        system("cls");

        switch(esc){
            case 1:
                cads();
                dados++;
                break;
            case 2:
                imp(dados);
                break;
            case 3:
                exit(0);
                break;
        }
    }while(esc != 3);
}

#endif // ex2

#ifdef ex3

/*3 - Escreva um programa com a estrutura de dados abaixo. Receba 2 datas via
    teclado na funcao main(). Faca uma funcao que calcule o numero de dias
    entre elas e mostre o resultado no video na funcao main().
    Utilize vetor de estruturas.
                estrutura: dia, mes, ano
*/

struct data{
    int dian, mesn, anon, diaa, mesa, anoa;
    int dias, mes, anos;
    int diatotal;
};

struct data gend;

int main(){
    setlocale(LC_ALL, "");
        int va;

            printf("\nDigite a primeira data:");
        do{
            printf("\n\tDia: ");
            scanf("%d", &gend.dian);
        }while (gend.dian > 31);
        do{
            printf("\n\tMês: ");
            scanf("%d", &gend.mesn);
        }while (gend.mesn > 12);
        printf("\n\tAno: ");
        scanf("%d", &gend.anon);

            printf("\nDigite a segunda data:");
        do{
            printf("\n\tDia: ");
            scanf("%d", &gend.diaa);
        }while (gend.diaa > 31);
        do
        {
            printf("\n\tMês: ");
            scanf("%d", &gend.mesa);
        } while (gend.mesa > 12);
        printf("\n\tAno: ");
        scanf("%d", &gend.anoa);

        //**********ANOS
        if(gend.anoa > gend.anon){gend.anos = gend.anoa - gend.anon;}
        else if(gend.anoa == gend.anon){gend.anos = 0;}
        else{gend.anos = gend.anon - gend.anoa;}

        //**********MESES

        if(gend.mesn > gend.mesa){
            va = gend.mesn;
            gend.mesn = gend.mesa;
            gend.mesa = va;
        }

        if (gend.mesa < gend.mesn || (gend.mesa == gend.mesn && gend.diaa < gend.dian)){
            gend.anos--;
            gend.mes = 12 - gend.mesn + gend.mesa;
        }else{gend.mes = gend.mesa - gend.mesn;}

        //**********DIAS

        if (gend.diaa < gend.dian){
            gend.mes--;
            if (gend.mesn == 2 && ((gend.anoa % 4 == 0 && gend.anoa % 100 != 0) || (gend.anoa % 400 == 0))){gend.dias = 29 - gend.dian + gend.diaa;}
            else if (gend.mesn == 2){gend.dias = 28 - gend.dian + gend.diaa;}
            else if (gend.mesn == 4 || gend.mesn == 6 || gend.mesn == 9 || gend.mesn == 11){gend.dias = 30 - gend.dian + gend.diaa;}
            else{gend.dias = 31 - gend.dian + gend.diaa;}
            }
        else{
            if (gend.mesn == 2 && ((gend.anoa % 4 == 0 && gend.anoa % 100 != 0) || (gend.anoa % 400 == 0))){gend.dias = gend.diaa - gend.dian;}
            else if (gend.mesn == 2){gend.dias = gend.diaa - gend.dian;}
            else if (gend.mesn == 4 || gend.mesn == 6 || gend.mesn == 9 || gend.mesn == 11){gend.dias = gend.diaa - gend.dian;}
            else{gend.dias = gend.diaa - gend.dian;}
        }

        diast();

        printf("O número de dias entre as datas é: %d", gend.diatotal);

    return 0;
}

void diast(){
    int cont;
    int anob=0;

    for(cont=0;cont<=gend.anos;cont++){
        if(cont % 4 == 0){anob++;}
    }
    gend.diatotal = ((gend.anos * 365) + anob) + gend.dias + (gend.mes * 30);

}

#endif // ex3

#ifdef ex4

/*4 - Escreva um programa com a estrutura de dados abaixo. Defina um vetor de
    estrutura de 4 elementos. Receba dados via teclado e imprima-os no video.
    Faca um menu com as seguintes opcoes:
    1 - receber todos os dados
    2 - imprime todos os dados
    3 - calcula o IMC de todas as pessoas.
    4 - sair
        Calculo do IMC = peso/(altura*altura).
        estrutura: nome, peso, altura
*/


struct datta{
    char nome[30];
    float peso;
    float alt;
};

struct datta strike[4];


void recdata(){
    setlocale(LC_ALL, "");
    int cont;
    for(cont=0;cont<4;cont++){
        printf("Entre com os dados da pessoa %d:\n",cont+1);
        printf("Nome: ");
        fflush(stdin);
        gets(strike[cont].nome);
        printf("Peso(kg): ");
        scanf("%f", &strike[cont].peso);
        printf("Altura: ");
        scanf("%f", &strike[cont].alt);
        system("cls");
    }

}

int impdata(int dados){
    setlocale(LC_ALL, "");
    int cont;
    if(dados == 0){printf("\nNão há dados.\n\n");}
    else{
        for(cont=0;cont<4;cont++){
            printf("\n\nDados da pessoa %d:\n-------------------------------------\n", cont+1);
            printf("Nome: %s\n", strike[cont].nome);
            printf("Peso(kg): %g\n", strike[cont].peso);
            printf("Altura: %g\n", strike[cont].alt);
            system("cls");
        }
    }
}

int caldata(int dados){
    setlocale(LC_ALL, "");
    int cont;
    float imc;

    if(dados == 0){printf("\nNão há dados.\n\n");}
    else{
        for(cont=0;cont<4;cont++){
            printf("\n\nDados da pessoa %d:\n-------------------------------------\n", cont+1);
            printf("Nome: %s\n", strike[cont].nome);
            imc = strike[cont].peso / (strike[cont].alt * strike[cont].alt);
            printf("Cálculo do IMC: %g\n", imc);
            if(imc < 18.5){printf("Seu peso está abaixo do normal.\n");}
            else if(imc > 18.6 && imc < 24.9){printf("Seu peso está normal.\n");}
            else if(imc > 25 && imc < 29.9){printf("Está sobrepeso.\n");}
            else if(imc > 30 && imc < 34.9){printf("Obesidade grau I.\n");}
            else if(imc > 35 && imc < 39.9){printf("Obesidade grau II.\n");}
            else if(imc > 40){printf("Obesidade grau III.\n");}
        }
    }
}

int main(){
    setlocale(LC_ALL, "");
    int esc, dados=0;
    do{
        do{
        printf("--------------------------\n");
        printf("1 - receber todos os dados\n");
        printf("2 - imprime todos os dados\n");
        printf("3 - calcula o IMC de todas as pessoas. \n");
        printf("4 - sair\n");
        printf("Qual ação deseja realizar?\n");
        printf("R: ");
        scanf("%d", &esc);
        system("cls");
        }while(esc < 1 || esc > 4);

        switch(esc){
            case 1:
                recdata();
                dados++;
                break;
            case 2:
                impdata(dados);
                break;
            case 3:
                caldata(dados);
                break;
            case 4:
                exit(0);
                break;
        }
    }while(esc != 4);
}

#endif // ex4
