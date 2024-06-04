#include "stdio.h"
#include "locale.h"

#define ex2

#ifdef ex1

/*
1 - As ligacoes telefonicas s�o cobradas pela sua duracao. O sistema registra os
    instantes em que a ligacao foi iniciada e concluida.
    Escreva um programa que recebe via teclado dois instantes dados em
    horas, minutos e segundo e determina o intervalo de tempo
    (em horas, minutos e segundos) decorrido entre eles.
*/

main()
{
    setlocale(LC_ALL, "");

    unsigned int inicioseg, iniciomin, iniciohora, fimseg, fimmin, fimhora, intervalohora, intervalomin, intervaloseg, iniciosegundos, fimsegundos, intervalosegundos;
    char reiniciar;

    // Recebimento dos valores

    do
    {
        printf("\n\n***PROGRAMA PARA CALCULAR O INTERVALO DE TEMPO DE UMA LIGA��O***\n\nComece preenchendo as informa��es:");
        printf("\n\nIn�cio da liga��o:\n\tHora(s): ");
        scanf("%d", &iniciohora);
        printf("\n\tMinuto(s): ");
        scanf("%d", &iniciomin);
        printf("\n\tSegundo(s): ");
        scanf("%d", &inicioseg);
        printf("\n\nT�rmino da liga��o:\n\tHora(s): ");
        scanf("%d", &fimhora);
        printf("\n\tMinuto(s): ");
        scanf("%d", &fimmin);
        printf("\n\tSegundo(s): ");
        scanf("%d", &fimseg);

        printf("\nIn�cio da liga��o   : %dh %dmin %dseg\nT�rmino da liga��o  : %dh %dmin %dseg", iniciohora, iniciomin, inicioseg, fimhora, fimmin, fimseg);

        // Convers�o para segundos

        iniciomin= iniciomin*60;
        iniciohora= (iniciohora*60)*60;
        iniciosegundos= inicioseg + iniciomin + iniciohora;

        fimmin= fimmin*60;
        fimhora= (fimhora*60)*60;
        fimsegundos= fimseg + fimmin + fimhora;

        // C�lculo dos segundos do intervalo, para a hip�tese da liga��o passar de meia-noite

        if(iniciohora>fimhora)
        {
            iniciosegundos= (86400-iniciosegundos);
            intervalosegundos= iniciosegundos+fimsegundos;
        }

        // C�lculo dos segundos do intervalo, para liga��es finalizadas no mesmo dia

        else
        {

            intervalosegundos= fimsegundos-iniciosegundos;

        }

        // Convers�o dos segundos do intervalo

        intervalohora= intervalosegundos/3600;
        intervalosegundos-=(intervalohora*3600);
        intervalomin= intervalosegundos/60;
        intervalosegundos-=(intervalomin*60);
        intervaloseg= intervalosegundos;

        // Exibi��o do resultado

        printf("\nIntervalo da liga��o: %dh %dmin %dseg", intervalohora, intervalomin, intervaloseg);

        // Op��o para reiniciar o programa

        getchar();
        printf("\n\nDeseja jogar novamente(s/n)? \nResposta: ");
        reiniciar=getchar();

        while(reiniciar!='s' && reiniciar!='S' && reiniciar!='n' && reiniciar!='N')
        {
            getchar();
            printf("\nOp��o incorreta, digite 's' para executar o programa novamente e 'n' para encerrar a execu��o: \nResposta: ");
            reiniciar= getchar();
        }
    }
    while(reiniciar=='s' || reiniciar=='S');

}

#endif ex1

#ifdef ex2

/*
2 - Escreva um programa para adivinhar um numero entre 1 e 99 que o usuario
    pensou. Digite via teclado os simbolos =, > ou < a cada pergunta. Utilize o
    comando if-else.
*/

main()
{
    setlocale(LC_ALL, "");

    int numero, maximo, minimo;
    char opcao, reiniciar;

    do
    {
        system("cls");
        numero=50;
        maximo= 100;
        minimo=1;
        printf("\n\nPense em um n�mero entre 1 e 99... Pensou? Agora me deixe adivinhar\n\n");
        printf("Digite:\n\t'=': n�mero certo; \n\t'<': o n�mero � menor; \n\t'>': o n�mero � maior.");
        printf("\n\nVoc� pensou no n�mero %i\nResposta: ", numero);
        opcao= getchar();

        do
        {

            if(opcao == '>')
            {
                minimo= numero;
                numero= (maximo+minimo)/2;
                printf("\n\nVoc� pensou no n�mero %i\nResposta: ", numero);
                getchar();
                opcao= getchar();
            }

            if(opcao == '<')
            {
                maximo= numero;
                numero= (maximo+minimo)/2;
                printf("\n\nVoc� pensou no n�mero %i\nResposta: ", numero);
                getchar();
                opcao= getchar();
            }

        }
        while(opcao!='=');

        printf("\nAcertei!!");

        getchar();
        printf("\n\nDeseja jogar novamente(s/n)? \nResposta: ");
        reiniciar=getchar();
        getchar();

    }
    while(reiniciar=='s' || reiniciar=='S');
}

#endif // ex2

#ifdef ex3

/*
3 - Reescreva o programa do exercicio anterior agora utilizando o comando switch.
    Conte o n. de tentativas e imprima o resultado no video.
*/

main()
{
    setlocale(LC_ALL, "");

    int numero, maximo, minimo, tentativas;
    char reiniciar, opcao;

    do
    {
        numero=50;
        maximo=100;
        minimo=0;
        tentativas=0;

        printf("\nPense em um n�mero entre 1 e 99... Pensou? Agora me deixe adivinhar.\n\n");
        printf("Digite:\n\t'=': n�mero certo; \n\t'<': o n�mero � menor; \n\t'>': o n�mero � maior.");
        printf("\n\nVoc� pensou no n�mero %i\nResposta: ", numero);

        opcao= getchar();

        do
        {

            switch(opcao)
            {

            case '>':
            {
                tentativas++;
                minimo= numero;
                numero= (maximo+minimo)/2;
                getchar();
                printf("\n\nVoc� pensou no n�mero %i\nResposta: ", numero);
                opcao= getchar();
                break;
            }

            case '<':
            {
                tentativas++;
                maximo= numero;
                numero= (maximo+minimo)/2;
                getchar();
                printf("\n\nVoc� pensou no n�mero %i\nResposta: ", numero);
                opcao= getchar();
                break;
            }

            case '=':
            {
                tentativas++;
                printf("\nAcertei, depois de %d tentativas!", tentativas);

                if (tentativas==1)
                {
                    printf("\b\b!");
                }
                break;
            }

            default:
            {
                printf ("\nOp��o inv�lida. Digite:\n\t'=': n�mero certo; \n\t'<': o n�mero � menor; \n\t'>': o n�mero � maior.");
                printf("\n\nVoc� pensou no n�mero %i\nResposta: ", numero);
                getchar();
                opcao= getchar();
                break;
            }

            }

        }
        while(opcao!='=');

        getchar();
        printf("\n\nDeseja continuar(s/n)? \nResposta: ");
        reiniciar= getchar();
        getchar();

    }
    while(reiniciar== 's' || reiniciar== 'S');

}

#endif ex3

#ifdef ex4

/*
4 - Receba via teclado a distancia em km e a quantidade de litros de gasolina
    consumidos por um carro em um percurso.
    Calcule o consumo em km/l e escreva uma mensagem de acordo com a tabela
    abaixo:
    CONSUMO (km/l) MENSAGEM
    menor que 8    Venda o carro!
    entre 8 e 14   Economico!
    maior que 14   Super economico!
*/

main()
{
    setlocale(LC_ALL, "");

    int distancia, litros, consumo;
    char reiniciar;

    do
    {

        printf("\nPrograma para o c�lculo de consumo. Preencha as informa��es abaixo: \n\tDist�ncia percorrida (em km): ");
        scanf("%d", &distancia);
        printf("\n\tLitros de gasolina consumidos: ");
        scanf("%d", &litros);
        consumo= distancia/litros;

        printf("\n\nConsumo de %dkm/l, ", consumo);

        if(consumo<8)
        {
            printf("Venda o carro!");
        }

        if(consumo>=8 && consumo<=14)
        {
            printf("Economico!");
        }

        if(consumo>14)
        {
            printf("Super economico!");
        }

        getchar();
        printf("\n\nDeseja continuar(s/n)? \nResposta: ");
        reiniciar= getchar();

    }
    while(reiniciar== 's' || reiniciar== 'S');

}

#endif ex4

#ifdef ex5

/*
5 - Escreva um programa que receba via teclado numeros inteiros positivos.
    Quando o numero digitado for negativo o programa deve parar e calcula a
    media dos valores positivos digitados.
*/

int main()
{
    setlocale(LC_ALL, "");

    int numero, contsoma, contquant;
    char opcao;

    do
    {
        contsoma=0;
        contquant=0;

        printf("\nDigite valores positivos e, ao final, um valor negativo");

        for(;;)
        {
            printf("\n\tValor %i: ", contquant+1);
            scanf("%d", &numero);

            if(numero>=0)
            {

                contsoma+=numero;
                contquant++;
            }

            else
            {
                break;
            }
        }

        if(contquant!=0)
        {
            printf("\nForam digitados %d numeros positivos, a media entre eles � %d", contquant, contsoma/contquant);
        }

        else
        {
            printf("\nNao foram digitados numeros positivos\n");
        }

        getchar();
        printf("\n\nDeseja continuar(s/n)?\nResposta: ");

        opcao= getchar();

        while(opcao!='s' && opcao!='S' && opcao!='n' && opcao!='N')
        {
            printf("\nOp��o incorreta, digite 's' para executar o programa novamente e 'n' para encerrar a execu��o:");
            getchar();
            opcao= getchar();
        }
    }
    while(opcao=='s' || opcao=='S');
}

#endif ex5
