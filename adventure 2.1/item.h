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
