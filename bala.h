#ifndef BALA_H_INCLUDED
#define BALA_H_INCLUDED

int ponto;
extern int balasAtiradas;

extern struct BALA
{
    int x_tiro;
    int y_tiro;
};

extern struct BALA tiro[1000];

void criaBala(int, int);

void desenhabala();

void apagabala();

void sobebala();

void mata_invader();

void destroi(int i);

#endif // BALA_H_INCLUDED
