#include "stdio.h"
#include "locale.h"

char medico[3][25], data_consulta[3][11];

int entrada_dados();
int lista_dados();
int pesquisa_medicos();
int pesquisa_data();
int alterar_dados();
int excluir_dados();
int sair();

main()
{
    setlocale(LC_ALL, "");
    FILE *file;
    int menu;

    do
    {
        printf("\n\n************MENU************");
        printf("\n\n1 - Entrada de dados. \n2 - Lista todos os dados na tela. \n3 – Pesquisa um médico pelo nome completo e mostra todo os dados na tela. \n4 – Pesquisa pela data de consulta e mostra todos na tela. \n5 – Altera dados. Pesquisa pelo nome completo do médico. \n6 – Exclui dados. Pesquisa pelo nome completo do médico. \n7 - Saída");
        printf("\nOpção: ");
        scanf("%d", &menu);
        getchar();

        switch(menu)
        {
        case 1:
            entrada_dados();
            break;

        case 2:
            lista_dados();
            break;

        case 3:
            printf("\n************PESQUISA MÉDICO************");
            pesquisa_medicos();
            break;

        case 4:
            pesquisa_data();
            break;

        case 5:
            alterar_dados();
            break;

        case 6:
            excluir_dados();
            break;

        case 7:
            sair();

        default:
            printf("\nOpção inválida");
        }

    }
    while(menu!=7);

}

int entrada_dados()
{
    printf("\n************ENTRADA DE DADOS************");

    int cont;
    FILE *file;
    file = fopen("desafio.txt", "w");

    for(cont=0; cont<3; cont++)
    {
        printf("\nNome médico %d: ", cont+1);
        gets(medico[cont]);
        printf("\nData da consulta: ");
        gets(data_consulta[cont]);
    }

    fwrite(medico, sizeof(medico), 1, file);
    fwrite(data_consulta, sizeof(data_consulta), 1, file);

    fclose(file);

    return 0;
}

int lista_dados()
{
    printf("\n************CONSULTA DE DADOS************");

    int cont;
    FILE *file;
    file = fopen("desafio.txt", "r");

    fread(medico, sizeof(medico), 1, file);
    fread(data_consulta, sizeof(data_consulta), 1, file);

    for(cont=0; cont<3; cont++)
    {
        if(medico[cont][0]!='*')
        {
            printf("\nMédico %d: %s\nData da consulta: %s", cont+1, medico[cont], data_consulta[cont]);
        }
    }

    fclose(file);
}

int pesquisa_medicos()
{
    int cont, cont2, tentativa=0;
    char nome[25];

    FILE *file;
    file = fopen("desafio.txt", "r");

    fread(medico, sizeof(medico), 1, file);
    fread(data_consulta, sizeof(data_consulta), 1, file);

    printf("\nInforme o nome do médico: ");
    gets(nome);

    for(cont=0; cont<3; cont++)
    {

        for(cont2=0; nome[cont2] !='\0'; cont2++)
        {
            if(nome[cont2] != medico[cont][cont2])
            {
                break;

            }
        }

        if(medico[cont][cont2]== '\0' &&  nome[cont2] =='\0')
        {
            printf("\nMédico %d: %s\nData da consulta: %s", cont+1, medico[cont], data_consulta[cont]);
            tentativa++;
            break;
        }
    }

    if(tentativa==0)
    {
        printf("\nNome não encontrado.");
    }

    fclose(file);

    return cont;
}

int pesquisa_data()
{
    printf("\n************PESQUISA DATA************");

    int cont, cont2, tentativa=0;
    char data[11];

    FILE *file;
    file = fopen("desafio.txt", "r");

    fread(medico, sizeof(medico), 1, file);
    fread(data_consulta, sizeof(data_consulta), 1, file);

    printf("\nInforme a data a ser consultada: ");
    gets(data);

    for(cont=0; cont<3; cont++)
    {

        for(cont2=0; data[cont2] !='\0'; cont2++)
        {
            if(data[cont2] != data_consulta[cont][cont2])
            {
                break;

            }
        }

        if(data_consulta[cont][cont2]== '\0' &&  data[cont2] =='\0')
        {
            printf("\nMédico %d: %s\nData da consulta: %s", cont+1, medico[cont], data_consulta[cont]);
            tentativa++;

        }
    }

    if(tentativa==0)
    {
        printf("\nData não encontrada.");
    }

    fclose(file);
}

int alterar_dados()
{
    printf("\n************ALTERAR DADOS************");

    int cont, cont2, escolha, tentativa=0;
    char data[11], nome[25];

    FILE *file;
    file = fopen("desafio.txt", "r");

    fread(medico, sizeof(medico), 1, file);
    fread(data_consulta, sizeof(data_consulta), 1, file);

    escolha= pesquisa_medicos();

    fclose(file);

    file = fopen("desafio.txt", "w");

    printf("\nNome médico: ");
    gets(medico[escolha]);
    printf("\nData da consulta: ");
    gets(data_consulta[escolha]);

    fwrite(medico, sizeof(medico), 1, file);
    fwrite(data_consulta, sizeof(data_consulta), 1, file);

    if(tentativa>0)
    {
        printf("\nRegistro alterado.");
    }

    fclose(file);
}

int excluir_dados()
{
    printf("\n************EXCLUIR DADOS************");

    int cont, cont2, escolha, tentativa=0;
    char data[11], nome[25];

    FILE *file;
    file = fopen("desafio.txt", "r");

    fread(medico, sizeof(medico), 1, file);
    fread(data_consulta, sizeof(data_consulta), 1, file);

    escolha= pesquisa_medicos();

    fclose(file);

    file = fopen("desafio.txt", "w");

    medico[escolha][0]='*';
    data_consulta[escolha][0]='*';

    fwrite(medico, sizeof(medico), 1, file);
    fwrite(data_consulta, sizeof(data_consulta), 1, file);

    fclose(file);
}

int sair()
{
    printf("\nPrograma finalizado.");

    exit(0);
}
