#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "funcoes.h"


int textcolor(int cor)      //mudar as cores
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
    return 0;
}

void gotoxy (int x, int y)   // localiza o curso no lugar desejado
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (COORD)
    {
        x-1,y-1
    });
}
void hidecursor()      // esconde o cursor
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}
void game_over(int x) // função pra dar game over
{

    system("cls");
    textcolor(12);
    gotoxy(34,8);
    printf("GAME OVER!\n");
    gotoxy(30,12);
    printf("Sua pontuacao foi :%i\n ", x);
    textcolor(15);
    salvar_dados(x);
    //Sleep(2000);
    system("cls");

    menu();
}

