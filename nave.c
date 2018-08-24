#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


void apagador_nave(int x_a, int y_a)    // apaga rastros da nave
{
    int i,j;
    for(i=0; i<2; i++)
    {
        gotoxy(x_a,y_a);
        for(j=0; j<3; j++)
        {
            printf(" ");
        }
        y_a++;
    }
}


void nave  (int x_nave, int y_nave)     //declara matriz e printa  nave na tela
{
    int i,j;
    char n[2][3]= {{' ',219,' '},
        {219,219,219}
    };
    gotoxy(x_nave, y_nave);
    for(i=0; i<2; i++)
    {
        for (j=0; j<3; j++)
        {
            textcolor(10);
            printf("%c", n[i][j] );
        }
        gotoxy(x_nave, y_nave+1);
    }
}



