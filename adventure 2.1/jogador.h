#include "item.h"

#ifndef JOGADOR_H
#define JOGADOR_H


class jogador{

    private:
        int nivel;
        int experience;
        int vida;
        int armor;
        int dano;
        int dano_magico;
        item gear[5];

        void cria_personagem(void);
        void monta_personagem(void);
        void update();

    public:
        int vida_total;
        int armor_total;
        int dano_total;
        int dano_magico_total;

        int vida_atual;
        int quest[15];
        int boss[10];


        void lvlUp(int vidaUP, int armorUP, int danoUP);
        void save();
        void kill();
        bool giveExp(int exp);
        int getNivel();
        int getExperience();
        int getVida();
        int getArmor();
        int getDano();
        int getDano_magico();
        void setItem(item novo);
        item getItem(int tipoItem);
        jogador();
};


#endif // JOGADOR_H
