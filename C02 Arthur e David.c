#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct cadastro{
    char medico[30];
    char celular[12];
    char data_consulta[11];
};

void getD(struct cadastro *pc){

    FILE *file;
    file = fopen("desafio.txt", "a");

    printf("Escreva os dados do médico, celular e data da consulta:\n");
    fflush(stdin);
    printf("Médico: ");
    gets(pc->medico);
    fflush(stdin);
    printf("Celular: ");
    gets(pc->celular);
    fflush(stdin);
    printf("Data da consulta: ");
    gets(pc->data_consulta);
    fflush(stdin);

    fwrite(pc, sizeof(*pc), 1, file);

    fclose(file);
}

void shwD(struct cadastro *pc){
    FILE *file;
    file = fopen("desafio.txt", "r");
    int d;

    for(;;){

        d = fread(pc, sizeof(*pc), 1, file);
        if(d == 0){break;}
        else{
            if(pc->medico[0] == '*'&& pc->celular[0] == '*' && pc->data_consulta[0] == '*'){break;}
            else{
            printf("Médico: %s\n", pc->medico);
            printf("Celular: %s\n", pc->celular);
            printf("Data da consulta: %s\n", pc->data_consulta);
            }
        }
    }
    system("pause");
    system("cls");
    fclose(file);
}

void procM(struct cadastro *pc, int j){

    FILE *file;
    file = fopen("desafio.txt", "r");
    char med[30];
    int d, cont, tent=0;

    printf("Escreva o nome do médico: ");
    fflush(stdin);
    gets(med);

    for(;;){
        d = fread(pc, sizeof(*pc), 1, file);
        if(d == 0){break;}
        for(cont=0; med[cont] != '\0' ; cont++){
            if(med[cont] != pc->medico[cont]){break;}
            }
                if(pc->medico[cont] == '\0' && med[cont] == '\0' && j == 1){
                        if(pc->medico[0] == '*'&& pc->celular[0] == '*' && pc->data_consulta[0] == '*'){break;}
                        else{
                        tent++;
                        printf("\nNome do médico--------------------------------------\n");
                        printf("Médico: %s\n\n", pc->medico);
                        break;
                        }
                    }
                if(pc->medico[cont] == '\0' && med[cont] == '\0' && j == 2){
                        if(pc->medico[0] == '*'&& pc->celular[0] == '*' && pc->data_consulta[0] == '*'){break;}
                        else{
                        tent++;
                        printf("\nCelular do médico--------------------------------------\n");
                        printf("Celular: %s\n\n", pc->celular);
                        break;
                        }
                    }
        }
        if(tent == 0){printf("Médico não encontrado.\n\n");}
    system("pause");
    system("cls");
    fclose(file);
}

void procC(struct cadastro *pc){

    FILE *file;
    file = fopen("desafio.txt", "r");
    int j = 2;
    procM(pc, j);

    fclose(file);
}

void procD(struct cadastro *pc){

    FILE *file;
    file = fopen("desafio.txt", "r");

    char dat[12];
    int d, cont, tent=0;

    printf("Escreva a data da consulta: ");
    fflush(stdin);
    gets(dat);

    for(;;){
        d = fread(pc, sizeof(*pc), 1, file);
        if(d == 0){break;}
        for(cont=0; dat[cont] != '\0' ; cont++){
            if(dat[cont] != pc->data_consulta[cont]){break;}
            }
                if(pc->data_consulta[cont] == '\0' && dat[cont] == '\0'){
                    if(pc->medico[0] == '*'&& pc->celular[0] == '*' && pc->data_consulta[0] == '*'){break;}
                    else{
                    tent++;
                    printf("\nPesquisa pela data--------------------------------------\n");
                    printf("Médico: %s\n\n", pc->medico);
                    printf("Celular: %s\n\n", pc->celular);
                    printf("Data: %s\n\n", pc->data_consulta);
                    break;
                    }
                }
        }
        if(tent == 0){printf("Médico não encontrado.\n\n");}

    system("pause");
    system("cls");
    fclose(file);
}

void altD(struct cadastro *pc){
    FILE *file;
    file = fopen("desafio.txt", "r+");
    char med[30];
    int d, cont, tent=0;
    long a=0;

    printf("Escreva o nome do médico: ");
    fflush(stdin);
    gets(med);

    for(;;){
        d = fread(pc, sizeof(*pc), 1, file);
        if(d == 0){break;}
        for(cont=0; med[cont] != '\0' ; cont++){
            if(med[cont] != pc->medico[cont]){
                a++;
                break;
                }
            }
                if(pc->medico[cont] == '\0' && med[cont] == '\0'){
                tent++;
                printf("Escreva os dados do médico, celular e data da consulta:\n");
                fflush(stdin);
                printf("Médico: ");
                gets(pc->medico);
                fflush(stdin);
                printf("Celular: ");
                gets(pc->celular);
                fflush(stdin);
                printf("Data da consulta: ");
                gets(pc->data_consulta);
                fflush(stdin);
                fseek(file, a*sizeof(*pc),0);
                fwrite(pc, sizeof(*pc), 1, file);
                break;
                }
        }
        if(tent == 0){printf("Médico não encontrado.\n\n");}
    system("pause");
    system("cls");
    fclose(file);
}

void excD(struct cadastro *pc){
    FILE *file;
    file = fopen("desafio.txt", "r+");
    char med[30];
    int d, cont, tent=0;
    long a=0;

    printf("Escreva o nome do médico: ");
    fflush(stdin);
    gets(med);

    for(;;){
        d = fread(pc, sizeof(*pc), 1, file);
        if(d == 0){break;}
        for(cont=0; med[cont] != '\0' ; cont++){
            if(med[cont] != pc->medico[cont]){
                a++;
                break;
                }
            }
                if(pc->medico[cont] == '\0' && med[cont] == '\0'){
                tent++;
                printf("Dados excluídos com sucesso!\n\n");
                pc->medico[0] = '*';
                pc->celular[0] = '*';
                pc->data_consulta[0] = '*';
                fseek(file, a*sizeof(*pc),0);
                fwrite(pc, sizeof(*pc), 1, file);
                break;
                }
        }
        if(tent == 0){printf("Médico não encontrado.\n\n");}
    system("pause");
    system("cls");
    fclose(file);
}

int main(){
    FILE *file;
    setlocale(LC_ALL, "");
    struct cadastro data;
    struct cadastro *pc;
    pc = &data;
    int esc, dados=0, *ep, j = 1;
    ep = &esc;

    do{
        do{
        printf("-----------------------------------------\n");
        printf("1 - receber todos os dados\n");
        printf("2 - mostrar todos os dados\n");
        printf("3 - procurar um medico pelo nome completo\n");
        printf("4 - pesquisar um celular pelo nome completo\n");
        printf("5 - pesquisar pela data\n");
        printf("6 - alterar dados\n");
        printf("7 - excluir dados\n");
        printf("8 - sair\n");
        printf("Qual ação deseja realizar?\n");
        printf("R: ");
        scanf("%d", &(*ep));
        }while(*ep < 1 || *ep > 8);
        system("cls");

        switch(*ep){
            case 1:
                getD(pc);
                break;
            case 2:
                shwD(pc);
                break;
            case 3:
                procM(pc, j);
                break;
            case 4:
                procC(pc);
                break;
            case 5:
                procD(pc);
                break;
            case 6:
                altD(pc);
                break;
            case 7:
                excD(pc);
                break;
            case 8:
                printf("Você escolheu sair.\n");
                exit(0);
                break;
        }
    }while((*ep) != 8);
}
