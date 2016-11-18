#ifndef JOGADOR_H
#define JOGADOR_H


class jogador{

    public:
        int nivel;
        int exp;
        int vida;
        int armor;
        int dano;
        int dano_magico;

        void cria_personagem(void);
        void monta_personagem(void);

        int vida_total;
        int armor_total;
        int dano_total;
        int dano_magico_total;

        int vida_atual;
        int quest[15];
        int boss[10];
        item gear[5];

        void lvlUp(int vidaUP, int armorUP, int danoUP);
        void update();
        void save();
        void kill();
        jogador();
};


#endif // JOGADOR_H
