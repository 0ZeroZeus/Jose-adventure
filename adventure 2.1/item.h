#define QNT_EQUIP 200
#define QNT_MONST 7
#define QNT_DROPS 4

#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef ITEM_H
#define ITEM_H

using namespace std;

class item{

    public:
        int id;
        string nome;
        int tipo;
        int vida;
        int armor;
        int dano;
        int dano_magico;

        item();
        item(int ID);
        void encontra_item(int ID);
        void limpa_item();

};

#endif // ITEM_H
