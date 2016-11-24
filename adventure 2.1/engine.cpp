<<<<<<< HEAD
#include "engine.h"

void premiacao(jogador jose, int lvl, monstro derrotado){

    if(jose.giveExp(lvl))
        lvlUP_Screen(jose);

    if((rand()%10) == 0)
        item_drop(jose, derrotado);
}

void luta(jogador jose, monstro inimigo, int lvl){

    int opcao,dano_jose,dano_inimigo, fuga=0;

    system("clear");

    while(jose.vida_atual >0 && inimigo.vida >0){

        printf("Jose\n\nSeu nivel: %d\nSua vida: %d\nSua armadura: %d\nSeu dano: %d\nSeu dano magico: %d\n\n", jose.getNivel(), jose.vida_atual, jose.armor_total, jose.dano_total, jose.dano_magico_total);
        printf("%s\n\nVida do inimigo: %d\n", inimigo.nome.c_str(), inimigo.vida);

        printf("Escolha o que fazer\n1 - atacar com sua arma\n2 - atacar com sua magia\n3 - fugir\n");
        scanf("%d", &opcao);

        if(inimigo.tipo == 'f')
            dano_inimigo= (inimigo.dano - jose.armor_total);
        else if(inimigo.tipo == 'm')
            dano_inimigo= (inimigo.dano_magico - (jose.armor_total/2));

        if(opcao == 1)
            dano_jose= (jose.dano_total - inimigo.armor);
        else if(opcao == 2)
            dano_jose= (jose.dano_magico_total - (inimigo.armor/2));
        else{
            dano_jose=0;
            fuga= rand()%2;
            if(fuga == 1)
                return;
        }

        if(dano_inimigo < 1 && fuga ==0)
            dano_inimigo=1;

        if(dano_jose < 1 && fuga ==0)
            dano_jose=1;

        printf("Jose recebeu %d de dano\n", dano_inimigo);
        printf("o inimigo recebeu %d de dano\n\n", dano_jose);

        jose.vida_atual -= dano_inimigo;
        inimigo.vida -= dano_jose;
    }

    if(jose.vida_atual <= 0){
        printf("voce morreu\nEspero que jogue novamente\n\n");
        jose.kill();
    }
    if(inimigo.vida <= 0)
        premiacao(jose, lvl, inimigo);
}

void batalha(jogador jose, int lvl){

    int random;
    int ID=0;

    ID += lvl*1000;

    random =rand()%(QNT_MONST-1);
    random += 1;
    ID += random;

    monstro inimigo = monstro(ID);

    luta(jose, inimigo, lvl);
}

void batalha_boss(jogador jose, int lvl){

    int ID=0;

    ID += lvl*1000;
    ID += QNT_MONST;

    monstro inimigo = monstro(ID);

    luta(jose, inimigo, lvl);

    if(jose.getNivel())
        jose.boss[lvl-1] = 1;
}

void aventura(jogador jose){

    int opcao_lugar;
    int opcao_bat=1;
    int opcao_boss;
    jose.vida_atual=jose.vida_total;

        opcao_lugar = exibe_locais(jose);

    if(opcao_bat){
        printf("Deseja batalhar o chefe da fase?\nTecle 1 para sim e 0 para batalhar contra monstros menores\n");
        scanf("%d", &opcao_boss);
        if(opcao_boss){
            batalha_boss(jose,opcao_lugar);

        }
        else{
            while(opcao_bat){

                printf("voce deseja entrar em uma batalha?\nTecle 1 para sim e 0 para nao\n");
                scanf("%d", &opcao_bat);

                if(opcao_bat){
                    batalha(jose, opcao_lugar);
                }
            }
        }
    }
}
=======
void premiacao(jogador jose, int lvl, monstro derrotado){

    if(jose.giveExp(lvl))
        lvlUP_Screen(jose);

    if((rand()%10) == 0)
        item_drop(jose, derrotado);
}

void luta(jogador jose, monstro inimigo, int lvl){

    int opcao,dano_jose,dano_inimigo, fuga=0;

    system("clear");

    while(jose.vida_atual >0 && inimigo.vida >0){

        printf("Jose\n\nSeu nivel: %d\nSua vida: %d\nSua armadura: %d\nSeu dano: %d\nSeu dano magico: %d\n\n", jose.getNivel(), jose.vida_atual, jose.armor_total, jose.dano_total, jose.dano_magico_total);
        printf("%s\n\nVida do inimigo: %d\n", inimigo.nome.c_str(), inimigo.vida);

        printf("Escolha o que fazer\n1 - atacar com sua arma\n2 - atacar com sua magia\n3 - fugir\n");
        scanf("%d", &opcao);

        if(inimigo.tipo == 'f')
            dano_inimigo= (inimigo.dano - jose.armor_total);
        else if(inimigo.tipo == 'm')
            dano_inimigo= (inimigo.dano_magico - (jose.armor_total/2));

        if(opcao == 1)
            dano_jose= (jose.dano_total - inimigo.armor);
        else if(opcao == 2)
            dano_jose= (jose.dano_magico_total - (inimigo.armor/2));
        else{
            dano_jose=0;
            fuga= rand()%2;
            if(fuga == 1)
                return;
        }

        if(dano_inimigo < 1 && fuga ==0)
            dano_inimigo=1;

        if(dano_jose < 1 && fuga ==0)
            dano_jose=1;

        printf("Jose recebeu %d de dano\n", dano_inimigo);
        printf("o inimigo recebeu %d de dano\n\n", dano_jose);

        jose.vida_atual -= dano_inimigo;
        inimigo.vida -= dano_jose;
    }

    if(jose.vida_atual <= 0){
        printf("voce morreu\nEspero que jogue novamente\n\n");
        jose.kill();
    }
    if(inimigo.vida <= 0)
        premiacao(jose, lvl, inimigo);
}

void batalha(jogador jose, int lvl){

    int random;
    int ID=0;

    ID += lvl*1000;

    random =rand()%(QNT_MONST-1);
    random += 1;
    ID += random;

    monstro inimigo = monstro(ID);

    luta(jose, inimigo, lvl);
}

void batalha_boss(jogador jose, int lvl){

    int ID=0;

    ID += lvl*1000;
    ID += QNT_MONST;

    monstro inimigo = monstro(ID);

    luta(jose, inimigo, lvl);

    if(jose.getNivel())
        jose.boss[lvl-1] = 1;
}

void aventura(jogador jose){

    int opcao_lugar;
    int opcao_bat=1;
    int opcao_boss;
    jose.vida_atual=jose.vida_total;

        opcao_lugar = exibe_locais(jose);

    if(opcao_bat){
        printf("Deseja batalhar o chefe da fase?\nTecle 1 para sim e 0 para batalhar contra monstros menores\n");
        scanf("%d", &opcao_boss);
        if(opcao_boss){
            batalha_boss(jose,opcao_lugar);

        }
        else{
            while(opcao_bat){

                printf("voce deseja entrar em uma batalha?\nTecle 1 para sim e 0 para nao\n");
                scanf("%d", &opcao_bat);

                if(opcao_bat){
                    batalha(jose, opcao_lugar);
                }
            }
        }
    }
}
>>>>>>> 3b24ad18909041a2dfb571d0c3db2abf4aef6f2f
