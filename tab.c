#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "invader.h"
#include "executa_jogo.h"
#include "nave.h"


void mgotoxy (int x, int y)         // gotoxy usado no tabuleiro
{
    COORD p= {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}
void tab ()         //printa o tabuleiro
{
    textcolor(13);
    int x_tab;
    for(x_tab=0; x_tab<35; x_tab++)
    {
        mgotoxy(0,x_tab);
        printf("%c", 219);
    }
    for(x_tab=0; x_tab<90; x_tab++)
    {
        mgotoxy(x_tab,0);
        printf("%c", 219);
    }
    for(x_tab=0; x_tab<35; x_tab++)
    {
        mgotoxy(65,x_tab);
        printf("%c", 219);
    }
    for(x_tab=0; x_tab<30; x_tab++)
    {
        mgotoxy(89,x_tab);
        printf("%c", 219);
    }
    for(x_tab=0; x_tab<90; x_tab++)
    {
        mgotoxy(x_tab,29);
        printf("%c", 219);
    }

}


void barra_protecao(int x_barra, int y_barra)    // printa a barra de proteção
{
    textcolor(13);
    int i,j;
    char n[6][10]= {{219,219,219,219,219,219,219,219,219,219},
        {219,' ',' ',' ',' ',' ',' ',' ',' ',219},
        {219,' ',' ',' ',' ',' ',' ',' ',' ',219},
        {219,' ',' ',' ',' ',' ',' ',' ',' ',219},
        {219,' ',' ',' ',' ',' ',' ',' ',' ',219},
        {219,' ',' ',' ',' ',' ',' ',' ',' ',219}
    };

    gotoxy(x_barra, y_barra);

    for(i=0; i<6; i++)
    {
        for (j=0; j<10; j++)
        {
            printf("%c", n[i][j] );
        }
        gotoxy(x_barra, y_barra+1);
    }


    x_barra+=34;
    gotoxy(x_barra, y_barra);

    for(i=0; i<6; i++)
    {
        for (j=0; j<10; j++)
        {
            printf("%c", n[i][j] );
        }
        gotoxy(x_barra, y_barra+1);
    }


}
void score (int x_score, int y_score)   //printa o nome "score" da lateral
{
    int i,j;
    char n[6][16]= {{219,219,' ',219,219,' ',219,219,219,' ',219,219,219,' ',219,219,},
        {219,219,' ',219,219,' ',219,219,219,' ',219,219,219,' ',219,219,},
        {219,' ',' ',219,' ',' ',219,' ',219,' ',219,' ',219,' ',219,' ',},
        {219,219,' ',219,' ',' ',219,' ',219,' ',219,219,219,' ',219,219,},
        {' ',219,' ',219,' ',' ',219,' ',219,' ',219,219,' ',' ',219,' ',},
        {219,219,' ',219,219,' ',219,219,219,' ',219,' ',219,' ',219,219,}

    };

    gotoxy(x_score, y_score);

    for(i=0; i<6; i++)
    {
        for (j=0; j<16; j++)
        {
            printf("%c", n[i][j] );
        }
        gotoxy(x_score, y_score++);
    }


}

void life (int x_score, int y_life)     // printa o nome "lives" da lateral da tela
{
    int i,j;
    char n[6][14]= {{219,' ',' ',219,' ',219,' ',219,' ',219,219,' ',219,219,},
        {219,' ',' ',219,' ',219,' ',219,' ',219,219,' ',219,219,},
        {219,' ',' ',219,' ',219,' ',219,' ',219,' ',' ',219,' ',},
        {219,' ',' ',219,' ',219,' ',219,' ',219,219,' ',219,219,},
        {219,' ',' ',219,' ',219,' ',219,' ',219,' ',' ',' ',219,},
        {219,219,' ',219,' ',' ',219,' ',' ',219,219,' ',219,219,}

    };

    gotoxy(x_score, y_life);

    for(i=0; i<6; i++)
    {
        for (j=0; j<14; j++)
        {
            textcolor(10);
            printf("%c", n[i][j] );
        }
        gotoxy(x_score, y_life++);
    }


}

int printa_vida(int x)      //printa a vida do jogador
{
    int i,j,k,l;
    char n[2][3]= {{' ',219,' '},
        {219,219,219}
    };
    l=0;
    gotoxy(73, 22);
    printf(" Vidas :");

    for(i=0; i<x; i++)
    {

        gotoxy(73+l, 25);
        printf("      ");
        gotoxy(73+l,25);
        for(j=0; j<2; j++)
        {

            for (k=0; k<3; k++)
            {
                textcolor(10);
                printf("%c", n[j][k] );
            }
            gotoxy(73+l, 26);
        }
        l=6;
    }


    return x;
}

void mostra_ponto(int x) // mostra o ponto do jogador
{
    gotoxy(74,10);
    printf("      ");
    gotoxy(74,10);
    printf("Pontos: %i", x);
}
