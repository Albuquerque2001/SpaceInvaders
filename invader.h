#ifndef INVADER_H_INCLUDED
#define INVADER_H_INCLUDED

extern struct INVASOR
{

    int x_invasor;
    int y_invasor;
};
extern struct INVASOR inv [6];

extern  struct INVASOR inv2[6];

void cria_invader ();

void cria_invader2 ();

void desenhainvader();

void desenhainvader2();

void mov_invaderx();

void mov_invader2x();

void movxmenos();

void movxmenos2();

void apagainvader();

void apagainvader2();

void invader(int x_invader, int y_invader);



#endif // INVADER_H_INCLUDED
