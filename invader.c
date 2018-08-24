#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "invader.h"



struct INVASOR inv [6];

struct INVASOR inv2 [6];

void cria_invader ()            //cria primeira fila de invaders
{
    int i,n=0;
    for(i=0; i<6; i++)
    {
        inv[i].x_invasor = 5+n;
        inv[i].y_invasor = 3;
        n+=8;
    }
}
void cria_invader2 ()           //cria segunda fila de invaders
{
    int i,n=0;
    for(i=0; i<6; i++)
    {
        inv2[i].x_invasor = 5+n;
        inv2[i].y_invasor = 6;
        n+=8;
    }
}

void desenhainvader()           //desenha primeira fila de invaders
{
    int i;


    for(i = 0; i<6 ; i++)
    {
        if(inv[i].x_invasor!=-3)
        {
            gotoxy(inv[i].x_invasor, inv[i].y_invasor);
            invader(inv[i].x_invasor, inv[i].y_invasor);
        }
    }
}
void desenhainvader2()            //desenha segunda fila de invaders
{
    int i;


    for(i = 0; i<6 ; i++)
    {
        if(inv2[i].x_invasor!=-3)
        {
            gotoxy(inv2[i].x_invasor, inv2[i].y_invasor);
            invader(inv2[i].x_invasor, inv2[i].y_invasor);
        }
    }
}

void mov_invaderx()                 //faz movimento da primeira fila de invaders
{
    int i;
    if (inv[i].y_invasor<26)
    {

        for(i = 0; i<6 ; i++)
        {
            if(inv[i].x_invasor!=-3)
            {
                inv[i].x_invasor++;

                switch (i)
                {
                case 0:
                    if (inv[i].x_invasor==23)
                    {
                        apagainvader();
                        movxmenos();
                    }
                    break;


                case 1:
                    if (inv[i].x_invasor==31)
                    {
                        apagainvader();
                        movxmenos();
                    }
                    break;

                case 2:
                    if (inv[i].x_invasor==39)
                    {
                        apagainvader();
                        movxmenos();
                    }
                    break;

                case 3:
                    if (inv[i].x_invasor==47)
                    {
                        apagainvader();
                        movxmenos();
                    }
                    break;

                case 4:
                    if (inv[i].x_invasor==55)
                    {
                        apagainvader();
                        movxmenos();
                    }
                    break;

                case 5:
                    if (inv[i].x_invasor==63)
                    {
                        apagainvader();
                        movxmenos();
                    }
                    break;


                }
            }
        }
    }

}
void mov_invader2x()            //faz movimento da segunda fila de invaders
{
    int i;
    if (inv2[i].y_invasor<26)
    {

        for(i = 0; i<6 ; i++)
        {
            if(inv2[i].x_invasor!=-3)
            {
                inv2[i].x_invasor++;

                switch (i)
                {
                case 0:
                    if (inv2[i].x_invasor==23)
                    {
                        apagainvader2();
                        movxmenos2();
                    }
                    break;


                case 1:
                    if (inv2[i].x_invasor==31)
                    {
                        apagainvader2();
                        movxmenos2();
                    }
                    break;

                case 2:
                    if (inv2[i].x_invasor==39)
                    {
                        apagainvader2();
                        movxmenos2();
                    }
                    break;

                case 3:
                    if (inv2[i].x_invasor==47)
                    {
                        apagainvader2();
                        movxmenos2();
                    }
                    break;

                case 4:
                    if (inv2[i].x_invasor==55)
                    {
                        apagainvader2();
                        movxmenos2();
                    }
                    break;

                case 5:
                    if (inv2[i].x_invasor==63)
                    {
                        apagainvader2();
                        movxmenos2();
                    }
                    break;


                }
            }
        }
    }

}
void movxmenos() // desce os invaders da primeira fileira
{
    int k;

    for(k=0; k<6; k++)
    {
        if(inv[k].x_invasor!=-3)
        {
            inv[k].y_invasor+=2;
            apagainvader();
            gotoxy(inv[k].x_invasor+2,inv[k].y_invasor-2);
            printf(" ");
            gotoxy(inv[k].x_invasor+2,inv[k].y_invasor-1);
            printf(" ");
            if (inv[k].x_invasor==-3)
            {
                inv[k].y_invasor=-3;
            }
        }


    }
    for (k=0; k<6; k++)
    {
        if(inv[k].x_invasor!=-3)
        {
            inv[k].x_invasor-=18;
            apagainvader();
        }

    }

}
void movxmenos2()       //desce os invaders da segunda fileira
{
    int k;

    for(k=0; k<6; k++)
    {
        if(inv2[k].x_invasor!=-3)
        {
            inv2[k].y_invasor+=2;
            apagainvader2();
            gotoxy(inv2[k].x_invasor,inv2[k].y_invasor-2);
            printf(" ");
            gotoxy(inv2[k].x_invasor+1,inv2[k].y_invasor-2);
            printf(" ");
            gotoxy(inv2[k].x_invasor+2,inv2[k].y_invasor-2);
            printf(" ");
            gotoxy(inv2[k].x_invasor,inv2[k].y_invasor-1);
            printf(" ");
            gotoxy(inv2[k].x_invasor+1,inv2[k].y_invasor-1);
            printf(" ");
            gotoxy(inv2[k].x_invasor+2,inv2[k].y_invasor-1);
            printf(" ");

            if (inv2[k].x_invasor==-3)
            {
                inv2[k].y_invasor=-3;
            }
        }


    }
    for (k=0; k<6; k++)
    {
        if(inv2[k].x_invasor!=-3)
        {
            inv2[k].x_invasor-=18;
            apagainvader2();
        }

    }

}
void apagainvader()         //apaga rastro da primeira fila de invaders
{
    int i;

    for (i=0; i<6; i++)
    {
        if(inv[i].x_invasor!=-3)
        {
            gotoxy(inv[i].x_invasor-1,inv[i].y_invasor);
            printf(" ");
            gotoxy(inv[i].x_invasor-1,inv[i].y_invasor+1);
            printf(" ");



        }
        if (inv[i].y_invasor>3)
        {

            if(i==0&&inv[i].x_invasor<45)
            {
                gotoxy(inv[i].x_invasor+17,inv[i].y_invasor-1);
                printf(" ");
                gotoxy(inv[i].x_invasor+17,inv[i].y_invasor-2);
                printf(" ");

            }
            if(i==0&&inv[i].x_invasor<45)
            {
                gotoxy(60,inv[i].y_invasor-1);
                printf(" ");
                gotoxy(60,inv[i].y_invasor-2);
                printf(" ");

            }
            gotoxy(inv[i].x_invasor,inv[i].y_invasor-1);
            printf(" ");
            gotoxy(inv[i].x_invasor,inv[i].y_invasor-2);
            printf(" ");

            gotoxy(inv[i].x_invasor+1,inv[i].y_invasor-1);
            printf(" ");
            gotoxy(inv[i].x_invasor+1,inv[i].y_invasor-2);
            printf(" ");

        }

    }



}

void apagainvader2()        //apaga rastro da segunda fila de invaders
{
    int i;

    for (i=0; i<6; i++)
    {
        if(inv2[i].x_invasor!=-3)
        {
            gotoxy(inv2[i].x_invasor-1,inv2[i].y_invasor);
            printf(" ");
            gotoxy(inv2[i].x_invasor-1,inv2[i].y_invasor+1);
            printf(" ");
            if(inv2[i].x_invasor<55)
            {
                gotoxy(inv2[i].x_invasor+3,inv2[i].y_invasor-2);
                printf(" ");
            }


        }
        if (inv2[i].y_invasor>3)
        {

            gotoxy(inv2[i].x_invasor,inv2[i].y_invasor-1);
            printf(" ");

            gotoxy(inv2[i].x_invasor+1,inv2[i].y_invasor-1);
            printf(" ");


        }

    }



}

void invader(int x_invader, int y_invader)      // printa a matriz do invader
{
    int i, j;
    char n [2][3]= {{178,178,178},
        {178,178,178}
    };

    gotoxy(x_invader, y_invader);

    for(i=0; i<2; i++)
    {
        for (j=0; j<3; j++)
        {
            textcolor(11);
            printf("%c", n[i][j] );
        }
        gotoxy(x_invader, y_invader+1);
    }
}


