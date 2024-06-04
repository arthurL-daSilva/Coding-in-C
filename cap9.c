#include<stdio.h>
#include<locale.h>
#include <string.h>

#define ex6
#ifdef ex1

/*
1 - Escreva um programa que receba em uma funcao 2 strings de ate' 10 caracteres
    passando como parametro ponteiro.
    Os vetores devem ser declarados como variaveis LOCAIS na função main().
    Escreva uma funcao para comparar as 2 strings. Passe como parametros para
    a funcao as 2 strings usando ponteiros e retorne como resultado se IGUAIS 1
    ou se DIFERENTES 0. Mostre o resultado no video na funcao main().
*/

void recs(char *n1, char *n2){
    printf("String 1: ");
    fgets(n1, 12, stdin);
    printf("String 2: ");
    fgets(n2, 12, stdin);
}

int comps(char *n1, char *n2){
    int cont;

    for(cont=0;cont<12 && *(n1 + cont) != '\0' && *(n2 + cont) != '\0';cont++){
        if(*(n1+cont) != *(n2+cont)){return 0;}
        }
    return 1;
}

int main(){
    setlocale(LC_ALL, "");
    int i;
    char *n1, *n2;
    char name1[12];
    char name2[12];

    n1 = name1;
    n2 = name2;

    printf("Digite 2 strings de até 10 caracteres:\n");
    recs(n1, n2);
    i = comps(n1, n2);
    system("cls");

    if(i == 0){printf("Strings diferentes:\n");}
    else{printf("Strings iguais:\n");}

    printf("\nString 1: %s", n1);
    printf("\nString 2: %s\n", n2);

}

#endif // ex1

#ifdef ex2

/*
2 - Escreva um programa que receba n valores via teclado e receba tambem a
    operação a ser executada. Quando for digitado "=" o programa deve mostrar
    o resultado acumulado dos n valores. As operações aritmeticas e a entrada
    de dados devem ser funcoes que recebe os valores usando ponteiros.
    As variaveis sao LOCAIS na funcao main().
*/

void operator1(float *n1, float *n2, float *result, char *ope, int *ope2){
        system("cls");
        printf("----------------------------------------------------------------------\n");
        printf("\nDigite + para adição;");
        printf("\nDigite - para subtração;");
        printf("\nDigite * para multiplicação;");
        printf("\nDigite / para divisão.");
        printf("\nDigite = para mostrar o resultado.");
        printf("\n----------------------------------------------------------------------\n\n");
        printf("Digite a opção desejada: ");
        *ope = getchar();

        if(*ope == '+'){*ope2 = 1;}
        if(*ope == '-'){*ope2 = 2;}
        if(*ope == '*'){*ope2 = 3;}
        if(*ope == '/'){*ope2 = 4;}
        if(*ope == '='){*ope2 = 0;}

        if(*ope2 != 0){
        printf("Digite dois numeros:");
        printf("\nNumero 1: ");
        scanf("%f",&*n1);
        printf("Numero 2: ");
        scanf("%f",&*n2);

        switch(*ope2){
        case 1:
            adicao(n1, n2, result);
            break;
        case 2:
            subtracao(n1, n2, result);
            break;
        case 3:
            multiplicacao(n1, n2, result);
            break;
        case 4:
            divisao(n1, n2, result);
            break;
        }
    }
}

void operator2(float *n1, float *result, char *ope, int *ope2){

    if(*ope2 != 0){
        do{
                getchar();
                printf("----------------------------------------------------------------------\n");
                printf("\nDigite + para adição;");
                printf("\nDigite - para subtração;");
                printf("\nDigite * para multiplicação;");
                printf("\nDigite / para divisão.");
                printf("\n----------------------------------------------------------------------\n\n");
                printf("Digite a operação que deseja fazer(digite \"=\" para mostrar o resultado): ");
                *ope = getchar();

                if(*ope == '+'){*ope2 = 1;}
                if(*ope == '-'){*ope2 = 2;}
                if(*ope == '*'){*ope2 = 3;}
                if(*ope == '/'){*ope2 = 4;}
                if(*ope == '='){*ope2 = 0;}

            if(*ope2 != 0){
                printf("Digite o numero: ");
                scanf("%f",&*n1);


                switch(*ope2){
                    case 1:
                        adicao2(n1, result);
                        break;
                    case 2:
                        subtracao2(n1, result);
                        break;
                    case 3:
                        multiplicacao2(n1, result);
                        break;
                    case 4:
                        divisao2(n1, result);
                        break;
                    }
                }
            }while(*ope2 != 0);
        }
}


int main(){
    setlocale(LC_ALL, "");
    char ope, *p1;
    int ope2, *p2;
    float n1, n2, result=0, *p3, *p4, *p5;

    p1 = &ope;
    p2 = &ope2;
    p3 = &n1;
    p4 = &n2;
    p5 = &result;

    operator1(p3, p4, p5, p1, p2);
    operator2(p3, p5, p1, p2);

    if(result == 0){printf("Não houveram operações aritiméticas.");}
    else{printf("O resultado das operações foi: %g", result);}
}

void adicao(float *n1, float *n2, float *nr){
    *nr += (*n1)+(*n2);
}

void subtracao(float *n1, float *n2, float *nr){
    *nr += (*n1)-(*n2);
}

void multiplicacao(float *n1, float *n2, float *nr){
    *nr += (*n1)*(*n2);
}

void divisao(float *n1, float *n2, float *nr){
    if(*n1 == 0 || *n2 == 0){*nr = 0;}
    else{*nr += (*n1) / (*n2);}
}

void adicao2(float *n1, float *nr){
    *nr = (*n1)+(*nr);
}

void subtracao2(float *n1, float *nr){
    *nr = (*n1)-(*nr);
}

void multiplicacao2(float *n1, float *nr){
    *nr = (*n1)*(*nr);
}

void divisao2(float *n1, float *nr){
    if(*n1 == 0 || *nr == 0){*nr = 0;}
    else{*nr = (*n1) / (*nr);}
}

#endif // ex2

#ifdef ex3

/*
3 - Escreva um programa que receba uma letra via teclado usando ponteiro. Escreva
    uma funcao que pesquise se esta letra existe no vetor abaixo usando ponteiros.
    Imprima o resultado da pesquisa no video na funcao main(). Passe como informacao
    para a funcao a letra digitada e o vetor usando ponteiros e faca a pesquisa
    usando ponteiros.(utilize o comando return).
    O vetor deve ser declarado como variavel LOCAL na funcao main().

    vetor -> b,d,f,h,j,k,m,o,q,s,u,w,y
*/

int pesqvet(char *let, char *lvet){
    int cont, *pc;

    pc = &cont;

    for(*pc = 0; *pc < 13; (*pc)++){
        if(*let == lvet[*pc]){
            return 1;
        }
    }
    return 0;
}

int main(){
    setlocale(LC_ALL, "");
    int num, *pn;
    char letra, *pl, *pv;
    char vet[13] = {'b','d','f','h','j','k','m','o','q','s','u','w','y'};

    pl = &letra;
    pv = vet;
    pn = &num;

    printf("Escreva uma letra: ");
    *pl = getchar();

    *pn = pesqvet(pl, pv);

    if(*pn == 1){printf("\nLetra encontrada no vetor: %c\n", letra);}
    else{printf("\nLetra não encontrada no vetor.\n");}
}

#endif // ex3

#ifdef ex4

/*
4 - Escreva um programa que tem uma estrutura da dados com os membros abaixo.
    A estrutura e' uma variavel LOCAL na funcao main(). Receba via teclado o
    conteudo de cada um dos membros numa funcao e imprima-os no video no
    seguinte formato(também numa função).

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

void pressV(struct variaveis *pc){
    setlocale(LC_ALL, "");

    printf("Digite os números inteiros:\n");
    printf("Unsigned Int: ");
    scanf("%d", &(*pc).UI);
    printf("Long: ");
    scanf("%ld", &(*pc).L);
    printf("Int: ");
    scanf("%d", &(*pc).I);
    printf("Unsigned Long: ");
    scanf("%ld", &(*pc).UL);
    printf("\nDigite dois números reais:\n");
    printf("Float: ");
    scanf("%g", &(*pc).F);
    printf("Double: ");
    scanf("%lf", &(*pc).D);
    getchar();
    printf("\nDigite um caracter: ");
    (*pc).C = getchar();
    getchar();
    printf("Digite outro caracter: ");
    (*pc).UC = getchar();

}

void pressC(struct variaveis *pc){
    printf("        10        20        30        40        50        60        70\n");
    printf("1234567890123456789012345678901234567890123456789012345678901234567890\n");

    printf("    %-c         %-7d   %-8ld            %-8.1f            %-9.1lf\n", (*pc).C, (*pc).I, (*pc).L, (*pc).F, (*pc).D);
    printf("          %-c                   %-ld                   %-8.1d", (*pc).UC, (*pc).UI, (*pc).UL);
}

int main(){
struct variaveis letras;
struct variaveis *pc;

pc = &letras;

    pressV(pc);
    pressC(pc);
    return 0;
}

#endif // ex4

#ifdef ex5

/*
5 - Escreva um programa com a estrutura abaixo. Defina um vetor de estruturas
    de 4 elementos como variavel LOCAL na funcao main(). Receba os 4 registros
    sequencialmente pelo teclado numa função e imprima todos os registros no
    video em outra funcao. Faça um menu. Utilize ponteiros nas funcoes.
    Coloque no menu a opção de sair tambem. Utilize o comando switch.
    (vetor de estruturas)
     estutura: nome, end, cidade, estado, cep

*/

struct cadastro{
    char nome[30];
    char end[50];
    char cidade[15];
    char estado[20];
    char cep[12];
};

void cads(struct cadastro *pc){
    int cont, *cp;
    cp = &cont;
    setlocale(LC_ALL, "");
    for(*cp=0;*cp<4;(*cp)++){
        printf("Escreva os dados da pessoa %d:\n", (*cp)+1);
        fflush(stdin);
        printf("Nome: ");
        gets(pc[*cp].nome);
        fflush(stdin);
        printf("Endereço: ");
        gets(pc[*cp].end);
        fflush(stdin);
        printf("Cidade: ");
        gets(pc[*cp].cidade);
        fflush(stdin);
        printf("Estado: ");
        gets(pc[*cp].estado);
        fflush(stdin);
        printf("CEP: ");
        gets(pc[*cp].cep);
        system("cls");
    }
}

void imp(int *dp, struct cadastro *pc){
    setlocale(LC_ALL, "");
    int cont, *cp;
    cp = &cont;
    if(*dp == 0){printf("\nNão há dados.\n\n");}
    else{
        for(*cp=0;*cp<4;(*cp)++){
          printf("\n\nDados da pessoa %d:\n-------------------------------------\n", (*cp)+1);
          printf("Nome: %s\n", pc[*cp].nome);
          printf("Endereço: %s\n", pc[*cp].end);
          printf("Cidade: %s\n", pc[*cp].cidade);
          printf("Estado: %s\n", pc[*cp].estado);
          printf("CEP: %s\n", pc[*cp].cep);
        }
    }
    system("pause");
    system("cls");
}

int main(){
    int esc, dados=0, *dp, *ep;
    setlocale(LC_ALL, "");
    struct cadastro set[4];
    struct cadastro *pc;
    pc = &set[0];
    ep = &esc;
    do{
        do{
        printf("--------------------------\n");
        printf("1 - receber todos os dados\n");
        printf("2 - mostrar todos os dados\n");
        printf("3 - sair\n");
        printf("Qual ação deseja realizar?\n");
        printf("R: ");
        scanf("%d", &(*ep));
        }while(*ep < 1 || *ep > 3);
        system("cls");

        dp = &dados;

        switch(*ep){
            case 1:
                cads(pc);
                (*dp)++;
                break;
            case 2:
                imp(dp, pc);
                break;
            case 3:
                printf("Você escolheu sair.\n");
                exit(0);
                break;
        }
    }while(*ep != 3);
}

#endif // ex5

#ifdef ex6

/*
6 - Acrescente ao menu do exercicio anterior as funcoes de procura, altera e
    exclui um registro sempre usando ponteiros.
*/

struct cadastro{
    char nome[30];
    char end[50];
    char cidade[15];
    char estado[20];
    char cep[12];
};

struct cadastro set[4];

void cads(struct cadastro *pc){
    int cont, *cp;
    cp = &cont;
    setlocale(LC_ALL, "");
    for(*cp=0;*cp<4;(*cp)++){
        printf("Escreva os dados da pessoa %d:\n", (*cp)+1);
        fflush(stdin);
        printf("Nome: ");
        gets(pc[*cp].nome);
        fflush(stdin);
        printf("Endereço: ");
        gets(pc[*cp].end);
        fflush(stdin);
        printf("Cidade: ");
        gets(pc[*cp].cidade);
        fflush(stdin);
        printf("Estado: ");
        gets(pc[*cp].estado);
        fflush(stdin);
        printf("CEP: ");
        gets(pc[*cp].cep);
        system("cls");
    }
}

void imp(int *dp, struct cadastro *pc){
    setlocale(LC_ALL, "");
    int cont, *cp;
    cp = &cont;
    if(*dp == 0){printf("\nNão há dados.\n\n");}
    else{
        for(*cp=0;*cp<4;(*cp)++){
          if(pc[*cp].nome[0] == '*' && pc[*cp].end[0] == '*' && pc[*cp].cidade[0] == '*' && pc[*cp].estado[0] == '*' && pc[*cp].cep[0] == '*'){
            printf("\n\nDados da pessoa %d\n-------------------------------------\n", (*cp)+1);
            printf("\nDADOS EXCLUIDOS.");
          }else{
          printf("\n\nDados da pessoa %d:\n-------------------------------------\n", (*cp)+1);
          printf("Nome: %s\n", pc[*cp].nome);
          printf("Endereço: %s\n", pc[*cp].end);
          printf("Cidade: %s\n", pc[*cp].cidade);
          printf("Estado: %s\n", pc[*cp].estado);
          printf("CEP: %s\n", pc[*cp].cep);
          }
        }
    }
    system("pause");
    system("cls");
}

void proc(int *dp, struct cadastro *pc){
    setlocale(LC_ALL, "");
    int esc, cont, cont2, tent=0, *contp, *contp2, *ep, *tp;
    char nome[30], end[50], cidade[15], estado[20], cep[12];
    char *np, *enp, *cp, *esp, *cpe;
    np = &nome[0];
    enp = &end[0];
    cp = &cidade[0];
    esp = &estado[0];
    cpe = &cep[0];
    ep = &esc;
    contp = &cont;
    contp2 = &cont2;
    tp = &tent;

    if(*dp == 0){printf("\nNão há dados.\n\n");}
    else{
        do{
            printf("Procurar a partir de quais dados?\n");
            printf("1 - Nome;\n");
            printf("2 - Endereço;\n");
            printf("3 - Cidade;\n");
            printf("4 - Estado;\n");
            printf("5 - CEP;\n");
            printf("R: ");
            scanf("%d",&(*ep));
        }while(*ep < 1 || *ep > 5);

        switch(*ep){
            case 1:
                getchar();
                printf("\nDigite o nome: ");
                fgets(np, 30, stdin);
                for(*contp=0; *contp<4; (*contp)++){
                        for(*contp2=0; np[*contp2] !='\0'; (*contp2)++){        //ARRUMAR --------------------------------
                        if(np[*contp2] != pc[*contp].nome[*contp2]){break;}
                        }
                        if(pc[*contp].nome[*contp2] == '\0' &&  np[*contp2] =='\0'){
                        printf("\n\nDados da pessoa %d:\n-------------------------------------\n", (*cp)+1);
                        printf("Nome: %s\n", pc[*contp].nome);
                        printf("Endereço: %s\n", pc[*contp].nome);
                        printf("Cidade: %s\n", pc[*contp].nome);
                        printf("Estado: %s\n", pc[*contp].nome);
                        printf("CEP: %s\n", pc[*contp].nome);
                        (*tp)++;
                        break;
                        }
                }
                if(*tp == 0){printf("Pessoa não encontrada.\n\n");}
                break;

            case 2:
                getchar();
                printf("\nDigite o endereço: ");
                fgets(enp, 50, stdin);
                for(*contp=0; *contp<4; (*contp)++){
                        for(*contp2=0; enp[*contp2] !='\0'; (*contp2)++){
                        if(enp[*contp2] != pc[*contp].end[*contp2]){break;}
                        }
                        if(pc[*contp].end[*contp2] == '\0' &&  enp[*contp2] =='\0'){
                        printf("\n\nDados da pessoa %d:\n-------------------------------------\n", (*cp)+1);
                        printf("Nome: %s\n", pc[*contp].end);
                        printf("Endereço: %s\n", pc[*contp].end);
                        printf("Cidade: %s\n", pc[*contp].end);
                        printf("Estado: %s\n", pc[*contp].end);
                        printf("CEP: %s\n", pc[*contp].end);
                        (*tp)++;
                        break;
                        }
                }
                if(*tp == 0){printf("Endereço não encontrado.\n\n");}
                break;

            case 3:
                getchar();
                printf("\nDigite a cidade: ");
                fgets(cp, 15, stdin);
                for(*contp=0; *contp<4; (*contp)++){
                        for(*contp2=0; cp[*contp2] !='\0'; (*contp2)++){
                        if(cp[*contp2] != pc[*contp].cidade[*contp2]){break;}
                        }
                        if(pc[*contp].cidade[*contp2] == '\0' &&  cp[*contp2] =='\0'){
                        printf("\n\nDados da pessoa %d:\n-------------------------------------\n", (*cp)+1);
                        printf("Nome: %s\n", pc[*contp].cidade);
                        printf("Endereço: %s\n", pc[*contp].cidade);
                        printf("Cidade: %s\n", pc[*contp].cidade);
                        printf("Estado: %s\n", pc[*contp].cidade);
                        printf("CEP: %s\n", pc[*contp].cidade);
                        (*tp)++;
                        break;
                        }
                }
                if(*tp == 0){printf("Cidade não encontrada.\n\n");}
                break;

            case 4:
                getchar();
                printf("\nDigite o estado: ");
                fgets(esp, 20, stdin);
                for(*contp=0; *contp<4; (*contp)++){
                        for(*contp2=0; esp[*contp2] !='\0'; (*contp2)++){
                        if(esp[*contp2] != pc[*contp].estado[*contp2]){break;}
                        }
                        if(pc[*contp].estado[*contp2] == '\0' &&  esp[*contp2] =='\0'){
                        printf("\n\nDados da pessoa %d:\n-------------------------------------\n", (*cp)+1);
                        printf("Nome: %s\n", pc[*contp].estado);
                        printf("Endereço: %s\n", pc[*contp].estado);
                        printf("Cidade: %s\n", pc[*contp].estado);
                        printf("Estado: %s\n", pc[*contp].estado);
                        printf("CEP: %s\n", pc[*contp].estado);
                        (*tp)++;
                        break;
                        }
                }
                if(*tp == 0){printf("Estado não encontrado.\n\n");}
                break;


            case 5:
                getchar();
                printf("\nDigite o CEP: ");
                fgets(cpe, 12, stdin);
                for(*contp=0; *contp<4; (*contp)++){
                        for(*contp2=0; cpe[*contp2] !='\0'; (*contp2)++){
                        if(cpe[*contp2] != pc[*contp].cep[*contp2]){break;}
                        }
                        if(pc[*contp].cep[*contp2] == '\0' &&  cpe[*contp2] =='\0'){
                        printf("\n\nDados da pessoa %d:\n-------------------------------------\n", (*cp)+1);
                        printf("Nome: %s\n", pc[*contp].cep);
                        printf("Endereço: %s\n", pc[*contp].cep);
                        printf("Cidade: %s\n", pc[*contp].cep);
                        printf("Estado: %s\n", pc[*contp].cep);
                        printf("CEP: %s\n", pc[*contp].cep);
                        (*tp)++;
                        break;
                        }
                }
                if(*tp == 0){printf("CEP não encontrado.\n\n");}
                break;
        }
    }
    system("pause");
    system("cls");
}

void alt(int *dp, struct cadastro *pc, int cont){
    setlocale(LC_ALL, "");
    int esc, *ep;
    ep = &esc;
    if(*dp == 0){printf("\nNão há dados.\n\n");}
    else{
        do{
            printf("Qual registro deseja alterar?\n");
            printf("Pessoa 1;\n");
            printf("Pessoa 2;\n");
            printf("Pessoa 3;\n");
            printf("Pessoa 4;\n");
            printf("\nPessoa: ");
            scanf("%d",&(*ep));
        }while(*ep < 1 || *ep > 4);
            system("cls");
            printf("Escreva os dados da pessoa %d:\n", *ep);
            fflush(stdin);
            printf("Nome: ");
            gets(pc[(*ep)-1].nome);
            fflush(stdin);
            printf("Endereço: ");
            gets(pc[(*ep)-1].end);
            fflush(stdin);
            printf("Cidade: ");
            gets(pc[(*ep)-1].cidade);
            fflush(stdin);
            printf("Estado: ");
            gets(pc[(*ep)-1].estado);
            fflush(stdin);
            printf("CEP: ");
            gets(pc[(*ep)-1].cep);
            system("cls");
            printf("Dados alterados com sucesso!\n");
    }
    system("pause");
    system("cls");
}

void exc(int *dp, struct cadastro *pc){
    setlocale(LC_ALL, "");
    int esc, *ep;
    ep = &esc;
    if(*dp == 0){printf("\nNão há dados.\n\n");}
    else{
        do{
            printf("Qual registro deseja excluir?\n");
            printf("Pessoa 1;\n");
            printf("Pessoa 2;\n");
            printf("Pessoa 3;\n");
            printf("Pessoa 4;\n");
            printf("R: ");
            scanf("%d",&(*ep));
        }while(*ep < 1 || *ep > 4);
            system("cls");
            pc[*ep-1].nome[0] = '*';
            pc[*ep-1].end[0] = '*';
            pc[*ep-1].cidade[0] = '*';
            pc[*ep-1].estado[0] = '*';
            pc[*ep-1].cep[0] = '*';
            printf("\nDados excluídos com sucesso!\n");
    }
    system("pause");
    system("cls");
}

int main(){
    int esc, dados=0, c, *dp, *ep;
    setlocale(LC_ALL, "");
    struct cadastro *pc;
    pc = &set[0];
    ep = &esc;
    do{
        do{
        printf("--------------------------\n");
        printf("1 - receber todos os dados\n");
        printf("2 - mostrar todos os dados\n");
        printf("3 - procurar dados\n");
        printf("4 - alterar dados\n");
        printf("5 - excluir dados\n");
        printf("6 - sair\n");
        printf("Qual ação deseja realizar?\n");
        printf("R: ");
        scanf("%d", &(*ep));
        }while(*ep < 1 || *ep > 6);
        system("cls");

        dp = &dados;

        switch(*ep){
            case 1:
                cads(pc);
                (*dp)++;
                break;
            case 2:
                imp(dp, pc);
                break;
            case 3:
                proc(dp, pc);
                break;
            case 4:
                alt(dp, pc, c);
                break;
            case 5:
                exc(dp, pc);
                break;
            case 6:
                printf("Você escolheu sair.\n");
                exit(0);
                break;
        }
    }while(*ep != 6);
}

#endif // ex6
