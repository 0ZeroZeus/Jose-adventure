using namespace std;

jogador::jogador(){

    monta_personagem();

    update();
}

void jogador::cria_personagem(){

    FILE* status;
    int pontos_totais=5;
    int temp_vida=1;
    int temp_armor=1;
    int temp_dano=1;
    int temp_magico=0;
    int aux;

    printf("\n\nPor favor, distribua seus %d pontos\n\n", pontos_totais);
    printf("Vida: %d\nArmadura: %d\nDano: %d\nDano magico: so pode ser alterado por items\n", temp_vida, temp_armor , temp_dano);

    while((temp_vida + temp_armor + temp_dano -3) != pontos_totais){

        printf("quanto colocara em vida?\n");
        scanf("%d", &aux);
        temp_vida += aux;
        printf("quanto colocara em armadura/defesa?\n");
        scanf("%d", &aux);
        temp_armor += aux;
        printf("quanto colocara em dano?\n");
        scanf("%d", &aux);
        temp_dano += aux;

        if((temp_vida + temp_armor + temp_dano -3) != pontos_totais){
            printf("Voce nao distribuiu corretamente, por favor, refaca\n\n");

        }
    }

    status= fopen("status_basicos.txt","w");

    fprintf(status,"1 1 0 %d %d %d %d\n\n", temp_vida, temp_armor, temp_dano, temp_magico);
    fprintf(status, "0 0 0 0 0 0 0 0 0 0\n\n");
    fprintf(status, "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n\n");
    fprintf(status, "0 0 0 0 0\n");


    fclose(status);

}

void jogador::monta_personagem(){

    FILE* status;
    int existe;
    char checa_tipo;
    int temp_gear[5];

    status= fopen("status_basicos.txt","r");
    if(status == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    fscanf(status,"%d", &existe);
    if(existe == 0){
        fclose(status);
        cria_personagem();
    }

    status= fopen("status_basicos.txt","r");
    if(status == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
    }

    fscanf(status, "1 %d %d %d %d %d %d",&nivel, &exp, &vida, &armor, &dano, &dano_magico);
    fscanf(status, "%d %d %d %d %d %d %d %d %d %d\n", &boss[0], &boss[1], &boss[2], &boss[3], &boss[4], &boss[5], &boss[6], &boss[7], &boss[8], &boss[9]);
    fscanf(status, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &quest[0], &quest[1], &quest[2], &quest[3], &quest[4], &quest[5], &quest[6], &quest[7], &quest[8], &quest[9], &quest[10], &quest[11], &quest[12], &quest[13], &quest[14]);
    fscanf(status, "%d %d %d %d %d\n", &temp_gear[0], &temp_gear[1], &temp_gear[2], &temp_gear[3], &temp_gear[4]);

    for(int i = 0; i < 5; i++){
        gear[i].encontra_item[temp_gear[i]];
    }

    fclose(status);
}

void jogador::lvlUp(int vidaUP, int armorUP, int danoUP){

    nivel++;
    exp = 0;
    vida += vidaUp;
    armor += armorUP;
    dano += danoUP;

}

void jogador::update(){

    for(int i = 0; i < 5; i++){

        vida_total += gear[i].vida;
        armor_total += gear[i].armor;
        dano_total += gear[i].dano;
        dano_magico_total += gear[i].dano_magico;
    }

}

void jogador::save(){

    FILE* status;

    status= fopen("status_basicos.txt","w");
    if(status == NULL) {
        printf("\nNao foi possivel abrir o arquivo\n\n");
        getchar();
        return;
    }

    fprintf(status,"1 %d %d %d %d %d %d\n\n", nivel, exp, vida, armor, dano, dano_magico);
    fprintf(status, "%d %d %d %d %d %d %d %d %d %d\n\n", boss[0], boss[1], boss[2], boss[3], boss[4], boss[5], boss[6], boss[7], boss[8], boss[9]);
    fprintf(status, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", quest[0], quest[1], quest[2], quest[3], quest[4], quest[5], quest[6], quest[7], quest[8], quest[9], quest[10], quest[11], quest[12], quest[13], quest[14]);
    fprintf(status, "%d %d %d %d %d\n", gear[0].id, gear[1].id, gear[2].id, gear[3].id, gear[4].id);

    fclose(status);


}

void jogador::kill(){

    nivel=1;
    exp=0;
    vida=0;
    armor=0;
    dano=0;
    dano_magico=0;
    vida_atual=0;

    for(int i = 0; i < 5; i++){
        gear[i].encontra_item[0];
    }
}
