#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "funcoes.h"

int users()             //conta as linhas do arquivo, consequentemente a quantidade de usuarios
{
    int linha = 1;
    char letra;

    FILE *rank;
    rank = fopen("rank.txt","r");

    do
    {
        letra = getc(rank);
        linha++;
    }
    while(letra != EOF);    //EOF indica o fim do arquivo

    fclose(rank);
    return(linha);
}

typedef struct           //variavel global para armazenar dados dos jogadores
{
    char nome[20];
    int ponto;
} dados;
int num_linha;

void salvar_dados(int ponto) //recebe o nome e pontuação do jogador
{
    char nome[20];


    textcolor(12);
    FILE *rank;
    rank = fopen("rank.txt", "a");
    gotoxy(25,17);
    printf(" Digite seu nome (sem espacos) \n");
    textcolor(12);
    gotoxy(25,20);
    fgets(nome, 20, stdin);
    fprintf(rank, "%s - %d \n", nome, ponto);
    fclose(rank);
    system("cls");
    textcolor(15);
}


void print_dados(dados player[num_linha])   // printa os dados dos jogadores no console
{
    int i = 0;

    for(i = 0; i<num_linha; i++)
    {
        if (strlen(player[i].nome)<=1)
        {
            printf("%c",0); /*se não tem o que printar,
                            não vai printar espaços vazios*/
        }
        else
            printf("\t |    %4d     |%20s      | %10d    | \n", i+1, player[i].nome, player[i].ponto);
    }
}


void ordena(dados player[num_linha])    //faz a ordenação dos jogadores no ranking em ordem decrescente
{
    int i,j, muda_ponto;
    char muda_nome[20];
    num_linha = users();

    for (i=0; i<num_linha; i++)
    {
        for(j=i+1; j<num_linha; j++)
        {
            if(player[i].ponto<=player[j].ponto)
            {
                strcpy(muda_nome, player[i].nome); // copia o nome para o vetor de transiçao
                muda_ponto = player[i].ponto; //copia o ponto para a variavel de transicao
                strcpy(player[i].nome, player[j].nome);
                player[i].ponto = player[j].ponto;
                strcpy(player[j].nome, muda_nome);
                player[j].ponto = muda_ponto;
            }
        }
    }
}


void mostra_ranking()   //mostra o ranking no console
{

    int i=0, ponto;
    char nome[20];
    num_linha = users();
    dados player[num_linha];
    FILE *rank;
    rank = fopen("rank.txt", "r");


    for(i=0; i<num_linha; i++) //vai retirar os lixos da memória
    {
        strcpy(player[i].nome," ");
        player[i].ponto = 0;
    }

    printf("\t\t\t\tRANKING\n");
    printf("\n\n\t |   POSICAO   |       NOME               |     PONTOS    |");
    printf("\n\t |-------------|--------------------------|---------------|\n");

    i=0;
    while(fscanf(rank, "%s - %d", nome, &ponto)!=EOF) //EOF é o fim do arquivo
    {
        if(i<num_linha)
        {
            strcpy(player[i].nome, nome);
            player[i].ponto = ponto;
            i++;
        }
    }
    ordena(player);
    print_dados(player);
    gotoxy(1,34);
    system("pause");

    fclose(rank);
    system("cls");
    menu();

}
