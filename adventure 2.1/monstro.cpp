using namespace std;

monstro::monstro(int ID){

    FILE *fp;
    char aux[50];

    fp=fopen("monstros.txt","r");

    do{
        fscanf(fp,"%d %[^\n]\n", &id, aux);
        fscanf(fp, "%c %d %d %d %d\n",&tipo, &vida, &armor, &dano, &dano_magico);
        fscanf(fp,"%d %d %d %d\n", &drops[0], &drops[1], &drops[2], &drops[3]);

    }while(id != ID);
    nome = aux;

    fclose(fp);
}
