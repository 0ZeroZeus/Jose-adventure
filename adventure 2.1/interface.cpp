int menu_principal(){

    int escolha;

    printf("O que voce gostaria de fazer?\n\n1 - Modo campanha\n2 - aventuras livres\n3 - Salvar o Jogo\n4 - Fechar o jogo\n\n");
    scanf("%d", &escolha);

    return(escolha);
}

void exibe_jose(jogador jose){

    item aux = item();

    system("clear");
    printf("Nivel de Jose: %d\nExperiencia de jose: %d\nVida total de Jose: %d\nArmadura de Jose: %d\nDano de Jose: %d\nDano magico de Jose:%d\n\n\n", jose.getNivel(), jose.getExperience(), jose.getVida(), jose.getArmor(), jose.getDano(), jose.getDano_magico());
    aux = jose.getItem(0);
    printf("Arma\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n", aux .nome.c_str(),  aux .vida,  aux .armor,  aux .dano,  aux .dano_magico);
    aux = jose.getItem(1);
    printf("\nAcessorio de cabeca\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n", aux.nome.c_str(),  aux.vida,  aux.armor,  aux.dano,  aux.dano_magico);
    aux = jose.getItem(2);
    printf("\nPeca de Torax\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n", aux.nome.c_str(),  aux.vida,  aux.armor,  aux.dano,  aux.dano_magico);
    aux = jose.getItem(3);
    printf("\nPeca das pernas\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n", aux.nome.c_str(),  aux.vida,  aux.armor,  aux.dano,  aux.dano_magico);
    aux = jose.getItem(4);
    printf("\nSapato\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n", aux.nome.c_str(),  aux.vida,  aux.armor,  aux.dano,  aux.dano_magico);

}

void item_drop(jogador jose, monstro derrotado){

    item dropado = item();
    item aux = item();
    int qual_drop, escolha;

    system("clear");

    qual_drop=rand()%QNT_DROPS;
    dropado.encontra_item(derrotado.drops[qual_drop]);

        printf("O monstro derrubou um item!!, voce ira quere-lo?\n\nSeus itens:\n\n");

        aux = jose.getItem(0);
        printf("Arma\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n", aux .nome.c_str(),  aux .vida,  aux .armor,  aux .dano,  aux .dano_magico);
        aux = jose.getItem(1);
        printf("\nAcessorio de cabeca\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n", aux.nome.c_str(),  aux.vida,  aux.armor,  aux.dano,  aux.dano_magico);
        aux = jose.getItem(2);
        printf("\nPeca de Torax\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n", aux.nome.c_str(),  aux.vida,  aux.armor,  aux.dano,  aux.dano_magico);
        aux = jose.getItem(3);
        printf("\nPeca das pernas\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n", aux.nome.c_str(),  aux.vida,  aux.armor,  aux.dano,  aux.dano_magico);
        aux = jose.getItem(4);
        printf("\nSapato\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n", aux.nome.c_str(),  aux.vida,  aux.armor,  aux.dano,  aux.dano_magico);

        printf("\n\nItem dropado:\n%s\nTipo: %d\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",dropado.nome.c_str(), dropado.tipo, dropado.vida, dropado.armor, dropado.dano, dropado.dano_magico);

        printf("\nColoque 1 para ficar com o item(ele ira ficar no lugar do item que vc esta atualmente usando) ou 0 para deixa-lo\n");
        scanf("%d", &escolha);

        if(escolha){
            jose.setItem(dropado);
        }
}

void lvlUP_Screen(jogador jose){

    int temp_vida=0,temp_armor=0,temp_dano=0;

    do{

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
        else
            jose.lvlUp(temp_vida, temp_armor, temp_dano);


    }while((temp_vida + temp_armor + temp_dano) > 3);

}

void le_texto(FILE *fp){

    char paragrafo[1000];

    getchar();
    while(fgetc(fp) != EOF){

        fscanf(fp, "%[^\n]\n", paragrafo);
        printf("%s\n", paragrafo);
        getchar();
    }

}

int menu_campanha(jogador jose){

    int opcao=0;

    while(opcao >= 16 ||opcao <= 0){
        system("clear");

        printf("Capitulo 1: Introducao\n");

        if(jose.quest[0])
            printf("Capitulo 2: Comece perto de casa\n");

        if(jose.boss[0])
            printf("Capitulo 3: Ao inves de dar o peixe ensine a pescar\n");

        if(jose.boss[1])
            printf("Capitulo 4: O que eh um ladrao senao um vilao\n");

        if(jose.boss[2])
            printf("Capitulo 5: Nenhum heroi teme o escuro\n");

        if(jose.quest[4])
            printf("Capitulo 6: Problemas de comunicacao\n");

        if(jose.boss[3])
            printf("Capitulo 7: Brincadeira de crianca\n");

        if(jose.boss[4])
            printf("Capitulo 8: Monarquia tribal\n");

        if(jose.boss[5])
            printf("Capitulo 9: Fingindo de morto pra pegar coveiro\n");

        if(jose.boss[6])
            printf("Capitulo 10: Batendo na porta da morte\n");

        if(jose.quest[9])
            printf("Capitulo 11: A guilda dos magos\n");

        if(jose.boss[7])
            printf("Capitulo 12: Mas isso nao faz o menor sentido\n");

        if(jose.quest[11])
            printf("Capitulo 13: Tornando-se importante...?\n");

        if(jose.boss[8])
            printf("Capitulo 14: Jose, finalmente heroi\n");

        if(jose.quest[13])
            printf("Capitulo 15: Amor verdadeiro\n");

        printf("\n\nDigite o numero do capitulo para le-lo ou 0 para sair\n\n");
        scanf("%d", &opcao);
    }
    return(opcao);
}

void modo_campanha(jogador jose){

    FILE *fp;
    int opcao = menu_campanha(jose);

    switch(opcao){

            case 1:
                fp=fopen("campanha\\intro.txt","r");
                break;

            case 2:
                fp=fopen("campanha\\fase1.txt","r");
                break;

            case 3:
                fp=fopen("campanha\\fase2.txt","r");
                break;

            case 4:
                fp=fopen("campanha\\fase3.txt","r");
                break;

            case 5:
                fp=fopen("campanha\\fase4.txt","r");
                break;

            case 6:
                fp=fopen("campanha\\side1.txt","r");
                break;

            case 7:
                fp=fopen("campanha\\fase5.txt","r");
                break;

            case 8:
                fp=fopen("campanha\\fase6.txt","r");
                break;

            case 9:
                fp=fopen("campanha\\fase7.txt","r");
                break;

            case 10:
                fp=fopen("campanha\\fase8.txt","r");
                break;

            case 11:
                fp=fopen("campanha\\side2.txt","r");
                break;

            case 12:
                fp=fopen("campanha\\fase9.txt","r");
                break;

            case 13:
                fp=fopen("campanha\\side3.txt","r");
                break;

            case 14:
                fp=fopen("campanha\\fase10.txt","r");;
                break;

            case 15:
                fp = NULL;
                /*funcao do end game deveria vir aqui*/
                break;
    }

    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);
    jose.quest[opcao-1]=1;

}

int exibe_locais(jogador jose){

    int opcao_lugar=0;
    system("clear");

    while(opcao_lugar >= 11 ||opcao_lugar <= 0){
        printf("Onde voce gostaria de se aventurar?\n\n");

                    if(jose.quest[1])
                        printf("1 - Floresta sombria(lvl 1)\n");

                    if(jose.quest[2])
                        printf("2 - Lago espelhado(lvl 2)\n");

                    if(jose.quest[3])
                        printf("3 - Acampamento de ladroes (lvl 3)\n");

                    if(jose.quest[4])
                        printf("4 - Caverna umida e escura(lvl 4)\n");

                    if(jose.quest[6])
                        printf("5 - Mansao antiga(lvl 5)\n");

                    if(jose.quest[7])
                        printf("6 - Ninho de goblins(lvl 6)\n");

                    if(jose.quest[8])
                        printf("7 - Vilarejo abandonado(lvl 7)\n");

                    if(jose.quest[9])
                        printf("8 - Seita de necromantes(lvl 8)\n");

                    if(jose.quest[11])
                        printf("9 - Torre dos desafios(lvl 9)\n");

                    if(jose.quest[13])
                        printf("10- Lar dos dragoes(lvl 10)\n");

        printf("\n\nTecle 0 para sair\n\n");
        scanf("%d", &opcao_lugar);
    }
    return(opcao_lugar);
}
