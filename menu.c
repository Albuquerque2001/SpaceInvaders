#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "ranking.h"
#include "funcoes.h"

char l1 = 128, l2 = 229;


void titulo() // orinta o titulo
{

    printf("                       _______  ______  _______   _______  _______    \n");
    printf("                      |  _____||    _ ||   _   | |       ||       |   \n");
    printf("                      | |_____ |   | |||  |_|  | |   ____||    ___|   \n");
    printf("                      |_____  ||   |_|||       | |  |     |   |___    \n");
    printf("                       _____| ||    __||       | |  |____ |    ___|   \n");
    printf("                      |       ||   |   |   _   | |       ||   |___    \n");
    printf("                      |_______||___|   |__| |__| |_______||_______|   \n");




    printf("     ___  ____       __  __          __  _______  ______    _______  ______    _______ \n");
    printf("    |   ||     %c    |  |%c  %c        /  /|   _   ||  __  %c  |       ||    _ |  |  _____|\n", 92,92,92,92);
    printf("    |   ||   _  %c   |  | %c  %c      /  / |  |_|  || |  %c_ %c |    ___||   | ||  | |_____\n", 92,92,92,92,92);
    printf("    |   ||  | %c  %c  |  |  %c  %c    /  /  |       || |    | ||   |___ |   |_||_ |_____  |\n", 92,92,92,92);
    printf("    |   ||  |  %c  %c |  |   %c  %c  /  /   |       || |   _| ||    ___||    __  | _____| |\n", 92,92,92,92);
    printf("    |   ||  |   %c      |    %c  %c/  /    |   _   || |__/  / |   |___ |   |  | ||       | \n", 92,92);
    printf("    |___||__|    %c_____|     %c____/     |__| |__||______/  |_______||___|  |_||_______| \n", 92,92);
}



int menu()
{
    hidecursor();
    char seta;// char para o "seletor"
    int opcao = 0 ;

    do
    {
        textcolor(14);
        titulo();
        // opções do início

        escolha(opcao); // funcao para que voce escolha a opcao no menu

        seta=getch();
// 72= cima      80= baixo

        // move o seletor
        switch (seta)
        {
        case 72:
        case 'w':
        case 'W':
            opcao--;
            break;
        case 80:
        case 'S':
        case 's':
            opcao++;
            break;
        }
        system("cls");

        if (opcao < 0) //faz subir depois do ultimo
            opcao = 3;
        else if (opcao > 3)
            opcao = 0;
        if (seta == 13) // seleciona a opcao
        {
            system("cls");
            break;
        }
    }
    while(1);

    if (opcao == 0)         // começa o jogo
    {

        executajogo();

    }

    else if (opcao == 1)    //abre as instrucões
    {
        instrucao();
    }

    else if (opcao == 2)    // abre o ranking
    {
        mostra_ranking();
    }


    else if (opcao == 3)   //sai do jogo
    {
        gotoxy(29,10);
        printf(":'( At%c a pr%cxima! )': \n ",130,162);
        Sleep(1300);
        exit (0);
    }

    return 0;
}


void escolha(int x)        //mostra as opcoes do menu
{
    char seletor = 206;

    if (x == 0)           // da espaço nos nomes selecionados
    {

        printf("\n\n\n\n\n\n    \t\t\t\t  %c  JOGAR\n\t\t\t\t  INSTRU%c%cES\n\t\t\t\t  RANKING\n\t\t\t\t  SAIR\n",seletor, l1,l2);
    }
    else if (x == 1)
    {

        printf("\n\n\n\n\n\n    \t\t\t\t  JOGAR\n\t\t\t\t  %c  INSTRU%c%cES\n\t\t\t\t  RANKING\n\t\t\t\t  SAIR\n",seletor, l1,l2);
    }
    else if (x == 2)
    {

        printf("\n\n\n\n\n\n    \t\t\t\t  JOGAR\n\t\t\t\t  INSTRU%c%cES\n\t\t\t\t  %c  RANKING\n\t\t\t\t  SAIR\n",l1,l2,seletor);
    }
    else if (x == 3)
    {

        printf("\n\n\n\n\n\n    \t\t\t\t  JOGAR\n\t\t\t\t  INSTRU%c%cES\n\t\t\t\t  RANKING\n\t\t\t\t  %c  SAIR\n", l1,l2,seletor);
    }

}


int instrucao()         //printa as instruções na tela
{
    char enter;
    gotoxy(37,1);
    printf("INSTRU%c%cES", l1, l2);
    gotoxy(7,8);
    printf("%c Use ' A ' ou ' < '  para mover a nave para a esquerda.",219);
    gotoxy(7,10);
    printf("%c Use ' D ' ou ' > ' para mover a nave para a direita.", 219);
    gotoxy(7,12);
    printf("%c Use <BARRA DE ESPA%cO> para atirar contra as naves inimigas.", 219, l1);
    gotoxy(25,18);
    printf("Tecle <ENTER> para voltar ao menu");

    enter=getch();

    if (enter == 13)
    {
        system ("cls");
        menu();
    }

    else
    {
        system ("cls");
        instrucao();
    }

    return 0;
}
