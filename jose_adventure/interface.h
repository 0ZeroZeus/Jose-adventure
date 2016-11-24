#include "jogador.h"
#include "monstro.h"

#ifndef INTERFACE_H
#define INTERFACE_H


int menu_principal();

void exibe_jose(jogador jose);

void item_drop(jogador jose, monstro derrotado);

void lvlUP_Screen(jogador jose);

void le_texto(FILE *fp);

int menu_campanha(jogador jose);

void modo_campanha(jogador jose);

int exibe_locais(jogador jose);


#endif // INTERFACE_H
