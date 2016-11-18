int menu_principal(){

    int escolha;

    printf("O que voce gostaria de fazer?\n\n1 - Modo campanha\n2 - aventuras livres\n3 - Salvar o Jogo\n4 - Fechar o jogo\n\n");
    scanf("%d", &escolha);

    return(escolha);
}

void exibe_jose(jogador jose){

    FILE* status;

    status= fopen("status_basicos.txt","r");
    if(status == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }
    system("clear");
    printf("Nivel de Jose: %d\nExperiencia de jose: %d\nVida total de Jose: %d\nArmadura de Jose: %d\nDano de Jose: %d\nDano magico de Jose:%d\n\n\n", jose.nivel, jose.exp, jose.vida, jose.armor, jose.dano, jose.dano_magico);
    printf("Arma\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n\n",jose.gear[0].nome.c_str(), jose.gear[0].vida, jose.gear[0].armor, jose.gear[0].dano, jose.gear[0].dano_magico);
    printf("Acessorio de cabeca\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n\n",jose.gear[1].nome.c_str(), jose.gear[1].vida, jose.gear[1].armor, jose.gear[1].dano, jose.gear[1].dano_magico);
    printf("Peca de Torax\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n\n",jose.gear[2].nome.c_str(), jose.gear[2].vida, jose.gear[2].armor, jose.gear[2].dano, jose.gear[2].dano_magico);
    printf("Peca das pernas\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n\n",jose.gear[3].nome.c_str(), jose.gear[3].vida, jose.gear[3].armor, jose.gear[3].dano, jose.gear[3].dano_magico);
    printf("Sapato\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n\n",jose.gear[4].nome.c_str(), jose.gear[4].vida, jose.gear[4].armor, jose.gear[4].dano, jose.gear[4].dano_magico);
    getchar();
    fclose(status);


}

void item_drop(jogador* jose, monstro derrotado){

    item dropado;
    int qual_drop, escolha;

    system("clear");

    qual_drop=rand()%QNT_DROPS;
    dropado.encontra_item(derrotado.drops[qual_drop]);

        printf("O monstro derrubou um item!!, voce ira quere-lo?\n\nSeus itens:\n\n");

        printf("Arma\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",jose->gear[0].nome.c_str(), jose->gear[0].vida, jose->gear[0].armor, jose->gear[0].dano, jose->gear[0].dano_magico);
        printf("\nAcessorio de cabeca\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",jose->gear[1].nome.c_str(), jose->gear[1].vida, jose->gear[1].armor, jose->gear[1].dano, jose->gear[1].dano_magico);
        printf("\nPeca de Torax\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",jose->gear[2].nome.c_str(), jose->gear[2].vida, jose->gear[2].armor, jose->gear[2].dano, jose->gear[2].dano_magico);
        printf("\nPeca das pernas\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",jose->gear[3].nome.c_str(), jose->gear[3].vida, jose->gear[3].armor, jose->gear[3].dano, jose->gear[3].dano_magico);
        printf("\nSapato\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",jose->gear[4].nome.c_str(), jose->gear[4].vida, jose->gear[4].armor, jose->gear[4].dano, jose->gear[4].dano_magico);

        printf("\n\nItem dropado:\n%s\nTipo: %d\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",dropado.nome.c_str(), dropado.tipo, dropado.vida, dropado.armor, dropado.dano, dropado.dano_magico);

        printf("\nColoque 1 para ficar com o item(ele ira ficar no lugar do item que vc esta atualmente usando) ou 0 para deixa-lo\n");
        scanf("%d", &escolha);

        if(escolha){
            jose->gear[dropado.tipo] = dropado;
        }
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
void intro(){

    FILE *fp;

    fp=fopen("campanha\\intro.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}
void fase1(){/*floresta*/

    FILE *fp;

    fp=fopen("campanha\\fase1.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

void fase2(){/*lago*/

    FILE *fp;

    fp=fopen("campanha\\fase2.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);

}

void fase3(){/*bandidos*/

    FILE *fp;

    fp=fopen("campanha\\fase3.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

void fase4(){/*caverna*/

    FILE *fp;

    fp=fopen("campanha\\fase4.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

void fase5(){/*vampiro*/

    FILE *fp;

    fp=fopen("campanha\\fase5.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

void fase6(){/*goblin*/

    FILE *fp;

    fp=fopen("campanha\\fase6.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

void fase7(){/*cemiterio*/

    FILE *fp;

    fp=fopen("campanha\\fase7.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

void fase8(){/*necromantes*/

    FILE *fp;

    fp=fopen("campanha\\fase8.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

void fase9(){/*torre*/

    FILE *fp;

    fp=fopen("campanha\\fase9.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

void fase10(){/*dragoes*/

    FILE *fp;

    fp=fopen("campanha\\fase10.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

void side1(){/*samurai*/

    FILE *fp;

    fp=fopen("campanha\\side1.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

void side2(){/*magos*/

    FILE *fp;

    fp=fopen("campanha\\side2.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

void side3(){/*preparacao*/

    FILE *fp;

    fp=fopen("campanha\\side3.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);


}

int xaveca(){

    int garotinha, resultado;
    FILE *fp;

    fp=fopen("campanha\\xaveca.txt","r");
    if(fp == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    le_texto(fp);

    system("cls");

    getchar();

        switch(garotinha){

            case 1:
                printf("Asa: Sim, vamos marcar um encontro XD, estou muito ansiosa!\n\n");

                break;
            case 2:
                printf("Yukiko: *Blush*\nSim...\nEu irei num encontro com voce...\n\n*Sorriso*");

                break;
            case 3:
                printf("Sachiko: Pois bem acho que voce é digno de conhecer o meu lado da luz\n\n*Vira para o lado*\n\nSachiko: Eu irei em um encontro com voce\n\n");

                break;

        }



    fclose(fp);

    return(resultado);
}

void menu_campanha(jogador jose){

    int cont=0;


    for(cont=0;cont <=15;cont++){

        switch(cont){

            case 1:
                printf("Capitulo 1: Introducao\n");
                break;

            case 2:
                if(jose.quest[0])
                    printf("Capitulo 2: Comece perto de casa\n");
                    break;
            case 3:
                if(jose.boss[0])
                    printf("Capitulo 3: Ao inves de dar o peixe ensine a pescar\n");
                    break;
            case 4:
                if(jose.boss[1])
                    printf("Capitulo 4: O que eh um ladrao senao um vilao\n");
                    break;
            case 5:
                if(jose.boss[2])
                    printf("Capitulo 5: Nenhum heroi teme o escuro\n");
                    break;
            case 6:
                if(jose.quest[4])
                    printf("Capitulo 6: Problemas de comunicacao\n");
                    break;
            case 7:
                if(jose.boss[3])
                    printf("Capitulo 7: Brincadeira de crianca\n");
                    break;
            case 8:
                if(jose.boss[4])
                    printf("Capitulo 8: Monarquia tribal\n");
                    break;
            case 9:
                if(jose.boss[5])
                    printf("Capitulo 9: Fingindo de morto pra pegar coveiro\n");
                    break;
            case 10:
                if(jose.boss[6])
                    printf("Capitulo 10: Batendo na porta da morte\n");
                    break;
            case 11:
                if(jose.quest[9])
                    printf("Capitulo 11: A guilda dos magos\n");
                    break;
            case 12:
                if(jose.boss[7])
                    printf("Capitulo 12: Mas isso nao faz o menor sentido\n");
                    break;
            case 13:
                if(jose.quest[11])
                    printf("Capitulo 13: Tornando-se importante...?\n");
                    break;
            case 14:
                if(jose.boss[8])
                    printf("Capitulo 14: Jose, finalmente heroi\n");
                    break;
            case 15:
                if(jose.quest[13])
                    printf("Capitulo 15: Amor verdadeiro\n");
                    break;

        }
    }
    printf("\n\nDigite o numero do capitulo para le-lo ou 0 para sair\n\n");
}

void modo_campanha(jogador *jose){

    int opcao;

    menu_campanha(*jose);
    scanf("%d", &opcao);

    switch(opcao){

            case 1:
                intro();
                jose->quest[0]=1;
                break;

            case 2:
                fase1();
                jose->quest[1]=1;
                break;

            case 3:
                fase2();
                jose->quest[2]=1;
                break;

            case 4:
                fase3();
                jose->quest[3]=1;
                break;

            case 5:
                fase4();
                jose->quest[4]=1;
                break;

            case 6:
                side1();
                jose->quest[5]=1;
                break;

            case 7:
                fase5();
                jose->quest[6]=1;
                break;

            case 8:
                fase6();
                jose->quest[7]=1;
                break;

            case 9:
                fase7();
                jose->quest[8]=1;
                break;

            case 10:
                fase8();
                jose->quest[9]=1;
                break;

            case 11:
                side2();
                jose->quest[10]=1;
                break;

            case 12:
                fase9();
                jose->quest[11]=1;
                break;

            case 13:
                side3();
                jose->quest[12]=1;
                break;

            case 14:
                fase10();
                jose->quest[13]=1;
                break;

            case 15:
                xaveca();
                jose->quest[14]=1;
                break;

            default:
                break;

        }



}

void exibe_locais(jogador jose){


    int cont=0;

    printf("Onde voce gostaria de se aventurar?\n\n");

    for(cont=0;cont <10;cont++){

        switch(cont){

            case 0:
                if(jose.quest[1])
                    printf("1 - Floresta sombria(lvl 1)\n");
                break;

            case 1:
                if(jose.quest[2])
                    printf("2 - Lago espelhado(lvl 2)\n");
                break;

            case 2:
                if(jose.quest[3])
                    printf("3 - Acampamento de ladroes (lvl 3)\n");
                break;

            case 3:
                if(jose.quest[4])
                    printf("4 - Caverna umida e escura(lvl 4)\n");
                break;

            case 4:
                if(jose.quest[6])
                    printf("5 - Mansao antiga(lvl 5)\n");
                break;

            case 5:
                if(jose.quest[7])
                    printf("6 - Ninho de goblins(lvl 6)\n");
                break;

            case 6:
                if(jose.quest[8])
                    printf("7 - Vilarejo abandonado(lvl 7)\n");
                break;

            case 7:
                if(jose.quest[9])
                    printf("8 - Seita de necromantes(lvl 8)\n");
                break;

            case 8:
                if(jose.quest[11])
                    printf("9 - Torre dos desafios(lvl 9)\n");
                break;

            case 9:
                if(jose.quest[13])
                    printf("10- Lar dos dragoes(lvl 10)\n");
                break;

        }
    }
    printf("\n\nTecle 0 para sair\n\n");
}
