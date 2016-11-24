using namespace std;

item::item(){}

item::item(int ID){
    encontra_item(ID);

}

void item::encontra_item(int ID){

    FILE *fp;
    char aux[50];

    fp=fopen("drops.txt","r");

    do{
        fscanf(fp,"%d %[^\n]\n", &id, aux);
        fscanf(fp, "%d %d %d %d %d\n",&tipo ,&vida, &armor, &dano, &dano_magico);

    }while(id != ID);
    nome = aux;

    fclose(fp);
}

void item::limpa_item(){
    encontra_item(0);
}
