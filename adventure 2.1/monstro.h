#include "item.h"

#ifndef MONSTRO_H
#define MONSTRO_H

using namespace std;

class monstro{

    public:
        int id;
        string nome;
        char tipo;
        int vida;
        int armor;
        int dano;
        int dano_magico;
        int drops[QNT_DROPS];

        monstro(int ID);

};

#endif // MONSTRO_H
