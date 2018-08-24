#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "bala.h"
#include "funcoes.h"
#include "invader.h"
#include "nave.h"
#include "tab.h"
#include "menu.h"

int x_nave;
int y_nave;
int vida=2;                                 //quantidade de vidas inicial
int velocidade=50 ;                     // velocidade inicial
int invadersmortos=0;                   // variavel que conta os invaders mortos
void executajogo()
{
    vida=2;
    ponto=0;
    velocidade=60;

restart:

    invadersmortos=0;
    hidecursor();
    x_nave=33;
    y_nave=27;                         // posição inicial da nave
    int x_barra=12,y_barra=18,x_score=70,y_score=3,y_life=15;                          // posição inicial da barra de proteção
    char c;                                              // char que pega os movimentos da nave
    int i;
    tab();
    barra_protecao(x_barra,y_barra);                    //posiciona barra de proteção
    score(x_score,y_score);
    life(x_score,y_life);

    cria_invader();                                       //cria primeira fila de invaders
    cria_invader2();                                      //cria segunda fila de invaders
    desenhainvader();                                     //desenha primeira fila de invaders
    desenhainvader2();                                    //desenha segunda fila de invaders

    while(vida>0)
    {

        mov_invaderx();                                    //faz movimento da primeira fila de invaders
        mov_invader2x();                                    //faz movimento da segunda fila de invaders
        desenhainvader();                                   //desenha primeira fila de invaders
        desenhainvader2();                                  //desenha segunda fila de invaders
        apagainvader();                                     //apaga rastro da primeira fila de invaders
        apagainvader2();                                    //apaga rastro da segunda fila de invaders
        mata_invader();                                     // função que checa se a bala bateu no invader
        c = 0;
        nave(x_nave,y_nave);
        desenhabala();
        Sleep(velocidade);
        if (kbhit())
            c = getch();

        switch(c)
        {
        case 75:                            //mover nave para esquerda
        case 'a':
        case 'A':
            apagador_nave(x_nave,y_nave);
            x_nave--;
            if (x_nave==1)
                x_nave++;
            break;

        case 77:                            // mover nave para direita
        case 'd':
        case 'D':
            apagador_nave(x_nave,y_nave);
            x_nave++;

            if (x_nave==62)
                x_nave--;
            break;

        case 32:                            // apertar espaço pra atirar
            criaBala(x_nave, y_nave);
            break;

        case 27:                            //apertar esc pra pausar
            gotoxy(24,24);
            printf("voce pausou o jogo\n\t");
            system ("pause");
            gotoxy(24,24);
            printf("                      \n");
            gotoxy(6,25);
            printf("                                                ");
            break;

        }

        apagabala();                            //apaga rastros da bala
        sobebala();                             // faz o movimento pra cima da bala
        velocidade = muda_veloc(ponto, velocidade);
        printa_vida(vida);                      // mostra quantidade de vidas na tela

        for(i=0; i<6; i++)                      // verificar se os invaders da primeira fila bateram na nave
        {
            if (inv[i].y_invasor==25&&inv[i].x_invasor==x_nave)
            {
                textcolor(12);
                vida--;
                if (vida==1)
                {
                    gotoxy(24,24);
                    printf("voce perdeu uma vida! \n\t");
                    system ("pause");
                    gotoxy(24,24);
                    printf("                      \n");
                    gotoxy(6,25);
                    printf("                                                ");
                    system("cls");
                    mostra_ponto(ponto);
                    goto restart;

                }
            }
        }
        for(i=0; i<6; i++)                      // verificar se os invaders da primeira fila passaram da nave
        {
            if (inv[i].y_invasor>26)
            {
                textcolor(12);
                vida--;
                if (vida==1)
                {
                    gotoxy(24,24);
                    printf("voce perdeu uma vida! \n\t");
                    system ("pause");
                    gotoxy(24,24);
                    printf("                      \n");
                    gotoxy(6,25);
                    printf("                                                ");
                    system("cls");
                    mostra_ponto(ponto);
                    goto restart;

                }
            }
        }
        for(i=0; i<6; i++)                      // verificar se os invaders da segunda fila bateram na nave ou passaram da nave
        {
            if (inv2[i].y_invasor==26&&inv2[i].x_invasor==x_nave)
            {
                textcolor(12);
                vida--;
                if (vida==1)
                {
                    gotoxy(24,24);
                    printf("voce perdeu uma vida! \n\t");
                    system ("pause");
                    gotoxy(24,24);
                    printf("                      \n");
                    gotoxy(6,25);
                    printf("                                                ");
                    Sleep(300);

                    system("cls");
                    mostra_ponto(ponto);
                    goto restart;

                }
            }
            if (inv2[i].y_invasor>26)
            {
                textcolor(12);
                vida--;
                if (vida==1)
                {
                    gotoxy(24,24);
                    printf("voce perdeu uma vida! \n\t");
                    system ("pause");
                    gotoxy(24,24);
                    printf("                      \n");
                    gotoxy(6,25);
                    printf("                                                ");
                    system("cls");
                    mostra_ponto(ponto);
                    goto restart;

                }
            }
        }
        if(invadersmortos==12)      // no caso de eliminar todos invaders começar o game de novo
        {
            gotoxy(24,24);
            printf("Voce passou de fase! \n\t");
            system ("pause");
            gotoxy(24,24);
            printf("                      \n");
            gotoxy(6,25);
            printf("                                                ");
            system("cls");
            mostra_ponto(ponto);
            goto restart;

        }

        mostra_ponto(ponto);

    }
    game_over(ponto);
}
int muda_veloc(int ponto, int velocidade)       // função para aumentar a velocidade do jogo
{
    if(ponto==1200)
        velocidade =35 ;
    else if(ponto==2400)
        velocidade = 25;
    else if(ponto==3600)
        velocidade = 15;
    else if (ponto == 4800)
        velocidade = 10 ;


    return velocidade;
}

