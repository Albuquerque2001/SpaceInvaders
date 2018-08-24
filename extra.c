#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

void nave  (int x_nave, int y_nave)
{
    int i,j;
    char n[2][3]= {{' ',178,' '},
        {178,178,178}
    };

    gotoxy( x_nave, y_nave);
    for(i=0; i<2; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%c", n[i][j] );
        }
        gotoxt(x_nave, y_nave+1);
    }





}



