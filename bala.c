#include <stdio.h>
#include "bala.h"
#include "funcoes.h"
#include "invader.h"
#include "menu.h"
#include "executa_jogo.h"
int ponto=0;
int balasAtiradas = 0;

struct BALA tiro[1000];

void criaBala(int x, int y)       //cria a bala e atribui as posições
{
    tiro[balasAtiradas].x_tiro = x+1;
    tiro[balasAtiradas].y_tiro = y-1;

    balasAtiradas++;
}

void desenhabala()   // printa a bala
{
    int i;

    textcolor(14);
    for(i = 0; i< balasAtiradas; i++)
    {
        if(tiro[i].y_tiro > 1)
        {
            gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
            printf("%c", 254);
        }
    }
}

void apagabala()   //apaga o rastro da bala
{
    int i;

    for(i = 0; i< balasAtiradas; i++)
    {
        if(tiro[i].y_tiro > 1)
        {
            gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
            printf(" ");
        }
    }
}

void sobebala()            // faz a bala subir
{
    int i=0;

    for(i = 0; i< balasAtiradas; i++)
    {
        tiro[i].y_tiro--;
    }
}


void mata_invader()         // verifica se a bala bateu no invader, destroi, aumenta pontuação e conta os invaders mortos
{
    int i,j;
    for(i = 0; i< balasAtiradas; i++)
    {
        for(j=0; j<6; j++)
        {

            if (tiro[i].y_tiro-1 == inv[j].y_invasor && tiro[i].x_tiro == inv[j].x_invasor)
            {

                destroi(i);
                tiro[i].x_tiro=0;
                inv[j].y_invasor=-3;
                inv[j].x_invasor=-3;
                ponto+=100;
                invadersmortos+=1;
            }
            else if (tiro[i].y_tiro-1 == inv[j].y_invasor&&tiro[i].x_tiro == inv[j].x_invasor+1)
            {

                destroi(i);

                tiro[i].x_tiro=0;
                inv[j].y_invasor=-3;
                inv[j].x_invasor=-3;
                ponto+=100;
                invadersmortos+=1;
            }
            else if (tiro[i].y_tiro-1 == inv[j].y_invasor&&tiro[i].x_tiro == inv[j].x_invasor+2)
            {

                destroi(i);


                tiro[i].x_tiro=0;
                inv[j].y_invasor=-3;
                inv[j].x_invasor=-3;
                ponto+=100;
                invadersmortos+=1;
            }
            else if (tiro[i].y_tiro-1 == inv2[j].y_invasor && tiro[i].x_tiro == inv2[j].x_invasor)
            {

                destroi(i);
                tiro[i].x_tiro=0;
                inv2[j].y_invasor=-3;
                inv2[j].x_invasor=-3;
                ponto+=100;
                invadersmortos+=1;
            }
            else if (tiro[i].y_tiro-1 == inv2[j].y_invasor&&tiro[i].x_tiro == inv2[j].x_invasor+1)
            {

                destroi(i);

                tiro[i].x_tiro=0;
                inv2[j].y_invasor=-3;
                inv2[j].x_invasor=-3;
                ponto+=100;
                invadersmortos+=1;
            }
            else if (tiro[i].y_tiro-1 == inv2[j].y_invasor&&tiro[i].x_tiro == inv2[j].x_invasor+2)
            {

                destroi(i);


                tiro[i].x_tiro=0;
                inv2[j].y_invasor=-3;
                inv2[j].x_invasor=-3;
                ponto+=100;
                invadersmortos+=1;
            }

        }
    }
}
void destroi(int i)                     // apaga o invader da tela
{
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro-1);
    printf(" ");

    tiro[i].x_tiro+=3;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro--;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro--;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro--;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro-=3;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro++;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro++;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro++;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].y_tiro--;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro+=2;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro--;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro--;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro-=2;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro++;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

    tiro[i].x_tiro++;
    gotoxy(tiro[i].x_tiro, tiro[i].y_tiro);
    printf(" ");

}
