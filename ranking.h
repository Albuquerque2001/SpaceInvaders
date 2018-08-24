#ifndef RANKING_H_INCLUDED
#define RANKING_H_INCLUDED

int users();

struct dados;

void salvar_dados(int );

void print_dados(struct dados *player);

void ordena(struct dados *player);

void mostra_ranking();


#endif // RANKING_H_INCLUDED
