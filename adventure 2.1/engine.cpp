
void premiacao(jogador * jose, int lvl, monstro derrotado){

    srand(time(NULL));
    int se_dropou, upagem=0;
    int temp_vida=0,temp_armor=0,temp_dano=0;

    jose->exp += lvl;

    switch(jose->nivel){

        case 1:
            if(jose->exp > 100)
                upagem=1;

            break;
        case 2:
            if(jose->exp > 300)
                upagem=1;

            break;
        case 3:
            if(jose->exp > 600)
                upagem=1;

            break;
        case 4:
            if(jose->exp > 1000)
                upagem=1;

            break;
        case 5:
            if(jose->exp > 1500)
                upagem=1;

            break;
        case 6:
            if(jose->exp > 2100)
                upagem=1;

            break;
        case 7:
            if(jose->exp > 2800)
                upagem=1;

            break;
        case 8:
            if(jose->exp > 3600)
                upagem=1;

            break;
        case 9:
            if(jose->exp > 4500)
                upagem=1;

            break;
    }

    while(upagem == 1){

        system("clear");
        printf("Parabens, voce aumentou de nivel e ganhou 3 pontos de status novos\n");

        printf("quanto colocara em vida?\n");
        scanf("%d", &temp_vida);

        printf("quanto colocara em armadura/defesa?\n");
        scanf("%d", &temp_armor);

        printf("quanto colocara em dano?\n");
        scanf("%d", &temp_dano);


        if((temp_vida + temp_armor + temp_dano) > 3){
            printf("nao trapaceie\n");
        }
        else{
            upagem=0;
            jose->lvlUp(temp_vida, temp_armor, temp_dano);
        }
    }

    se_dropou= rand()%10;
    if(se_dropou == 0){
        item_drop(jose, derrotado);
    }

}


int luta(jogador* jose, monstro enemy){

    int opcao,dano_jose,dano_inimigo, fuga=0;

    srand(time(NULL));
    system("clear");

    while(jose->vida_atual >0 && enemy.vida >0){

        printf("Jose\n\nSeu nivel: %d\nSua vida: %d\nSua armadura: %d\nSeu dano: %d\nSeu dano magico: %d\n\n", jose->nivel, jose->vida_atual, jose->armor_total, jose->dano_total, jose->dano_magico_total);
        printf("%s\n\nVida do inimigo: %d\n", enemy.nome.c_str(), enemy.vida);

        printf("Escolha o que fazer\n1 - atacar com sua arma\n2 - atacar com sua magia\n3 - fugir\n");
        scanf("%d", &opcao);

        if(enemy.tipo == 'f')
            dano_inimigo= (enemy.dano - jose->armor_total);
        else if(enemy.tipo == 'm')
            dano_inimigo= (enemy.dano_magico - (jose->armor_total/2));

        if(opcao == 1)
            dano_jose= (jose->dano_total - enemy.armor);
        else if(opcao == 2)
            dano_jose= (jose->dano_magico_total - (enemy.armor/2));
        else{
            dano_jose=0;
            fuga= rand()%2;
            if(fuga == 1)
                return(0);
        }

        if(dano_inimigo < 1 && fuga ==0)
            dano_inimigo=1;

        if(dano_jose < 1 && fuga ==0)
            dano_jose=1;

        printf("Jose recebeu %d de dano\n", dano_inimigo);
        printf("o inimigo recebeu %d de dano\n\n", dano_jose);

        jose->vida_atual -= dano_inimigo;
        enemy.vida -= dano_jose;
    }

    if(jose->vida_atual <= 0){
        printf("voce morreu\nEspero que jogue novamente\n\n");
        jose->kill();
        return(0);
    }
    if(enemy.vida <= 0)
        return(1);
}

int batalha(jogador* jose, int lvl){

    srand(time(NULL));
    int random, resultado;
    int ID=0;

    ID += lvl*1000;

    random =rand()%(QNT_MONST-1);
    random += 1;
    ID += random;

    monstro inimigo(ID);

    resultado= luta(jose, inimigo);

    if(resultado){
        premiacao(jose, lvl, inimigo);
    }

    return(resultado);
}

int batalha_boss(jogador* jose, int lvl){

    srand(time(NULL));
    int resultado;
    int ID=0;

    ID += lvl*1000;
    ID += QNT_MONST;

    monstro inimigo(ID);

    resultado= luta(jose, inimigo);

    if(resultado){
        jose->boss[lvl-1] = 1;
        premiacao(jose, lvl, inimigo);
    }

    return(resultado);
}

void aventura(jogador* jose){

    int opcao_lugar=11;
    int opcao_bat=1;
    int opcao_boss;
    jose->vida_atual=jose->vida_total;

    while(opcao_lugar > 10){

        exibe_locais(*jose);
        scanf("%d", &opcao_lugar);
        opcao_bat=opcao_lugar;
    }
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

                    opcao_bat= batalha(jose, opcao_lugar);
                }
            }
        }
    }
}
