#define QNT_EQUIP 200
#define QNT_MONST 7
#define QNT_DROPS 4

typedef struct{
	
	int id;
	char nome[150];
	char tipo;
	int vida;
	int armor;
	int dano;
	int dano_magico;
	
}item;
typedef struct{
	
	int nivel;
	int exp;
	int vida;
	int armor;
	int dano;
	int dano_magico;
	int vida_atual;
	int quest[15];
	int boss[10];
	item weapon;
	item headgear;
	item chestgear;
	item leggear;
	item footgear;
	
}jogador;
typedef struct{
	
	int id;
	char nome[70];
	char tipo;
	int vida;
	int armor;
	int dano;
	int dano_magico;
	int drops[QNT_DROPS];
	
}monstro;


void limpa_itens(item* equip){
	
	strcpy(equip->nome,"nao ha");
	equip->tipo='n';
	equip->vida=0;
	equip->armor=0;
	equip->dano=0;
	equip->dano_magico=0;
}


item encontra_item(int ID){
	
	FILE *fp;
	item ancora;
	
	limpa_itens(&ancora);
	fp=fopen("drops.txt","r");
	
	do{
		fscanf(fp,"%d %[^\n]\n", &ancora.id, ancora.nome);
		fscanf(fp, "%c %d %d %d %d\n",&ancora.tipo ,&ancora.vida, &ancora.armor, &ancora.dano, &ancora.dano_magico);
		
		
		
	}while(ancora.id != ID);
	
	fclose(fp);
	return(ancora);
}

void entrega_equips(jogador* jose, monstro derrotado){
	
	item dropado;
	int qual_drop, escolha;
		
	system("clear");
		
	qual_drop=rand()%QNT_DROPS;
	dropado= encontra_item(derrotado.drops[qual_drop]);	
		
		printf("O monstro derrubou um item!!, voce ira quere-lo?\n\nSeus itens:\n\n");
		
		printf("Arma\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",jose->weapon.nome, jose->weapon.vida, jose->weapon.armor, jose->weapon.dano, jose->weapon.dano_magico);
		printf("\nAcessorio de cabeca\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",jose->headgear.nome, jose->headgear.vida, jose->headgear.armor, jose->headgear.dano, jose->headgear.dano_magico);
		printf("\nPeca de Torax\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",jose->chestgear.nome, jose->chestgear.vida, jose->chestgear.armor, jose->chestgear.dano, jose->chestgear.dano_magico);
		printf("\nPeca das pernas\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",jose->leggear.nome, jose->leggear.vida, jose->leggear.armor, jose->leggear.dano, jose->leggear.dano_magico);
		printf("\nSapato\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",jose->footgear.nome, jose->footgear.vida, jose->footgear.armor, jose->footgear.dano, jose->footgear.dano_magico);
		
		printf("\n\nItem dropado:\n%s\nTipo: %c\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n",dropado.nome, dropado.tipo, dropado.vida, dropado.armor, dropado.dano, dropado.dano_magico);
		
		printf("\nColoque 1 para ficar com o item(ele ira ficar no lugar do item que vc esta atualmente usando) ou 0 para deixa-lo\n");
		scanf("%d", &escolha);
		
		if(escolha){
			
			switch(dropado.tipo){
			
				case 'w':
					
					strcpy(jose->weapon.nome, dropado.nome); 
					jose->weapon.tipo = dropado.tipo;
					jose->weapon.vida =  dropado.vida;
					jose->weapon.armor = dropado.armor;
					jose->weapon.dano = dropado.dano;
					jose->weapon.dano_magico = dropado.dano_magico;
					break;
				
				case 'h':
					
					strcpy(jose->headgear.nome, dropado.nome); 
					jose->headgear.tipo = dropado.tipo;
					jose->headgear.vida = dropado.vida;
					jose->headgear.armor = dropado.armor;
					jose->headgear.dano = dropado.dano;
					jose->headgear.dano_magico = dropado.dano_magico;
					break;
					
				case 'c':
				
					strcpy(jose->chestgear.nome, dropado.nome); 
					jose->chestgear.tipo = dropado.tipo;
					jose->chestgear.vida = dropado.vida;
					jose->chestgear.armor = dropado.armor;
					jose->chestgear.dano = dropado.dano;
					jose->chestgear.dano_magico = dropado.dano_magico;
					break;
					
				case 'l':
					
					strcpy(jose->leggear.nome, dropado.nome); 
					jose->leggear.tipo = dropado.tipo;
					jose->leggear.vida = dropado.vida;
					jose->leggear.armor = dropado.armor;
					jose->leggear.dano = dropado.dano;
					jose->leggear.dano_magico = dropado.dano_magico;
					break;
					
				case 'f':
					
					strcpy(jose->footgear.nome, dropado.nome); 
					jose->footgear.tipo = dropado.tipo;
					jose->footgear.vida = dropado.vida;
					jose->footgear.armor = dropado.armor;
					jose->footgear.dano = dropado.dano;
					jose->footgear.dano_magico = dropado.dano_magico;
					break;
			}
		}	
}

void premiacao(jogador * jose, int lvl, monstro derrotado){
	
	srand(time(NULL));
	int se_dropou, upagem=0;
	int temp_vida=0,temp_armor=0,temp_dano=0;
	
	switch(jose->nivel){
		
		case 1:
			jose->exp += lvl;
			
			if(jose->exp > 100){
				
				jose->nivel++;
				upagem=1;
				jose->exp=0;
			}
			break;
		case 2:
			jose->exp += lvl;
			
			if(jose->exp > 300){
				
				jose->nivel++;
				upagem=1;
				jose->exp=0;
			}
			break;
		case 3:
			jose->exp += lvl;
			
			if(jose->exp > 600){
				
				jose->nivel++;
				upagem=1;
				jose->exp=0;
			}
			break;
		case 4:
			jose->exp += lvl;
			
			if(jose->exp > 1000){
				
				jose->nivel++;
				upagem=1;
				jose->exp=0;
			}
			break;
		case 5:
			jose->exp += lvl;
			
			if(jose->exp > 1500){
				
				jose->nivel++;
				upagem=1;
				jose->exp=0;
			}
			break;
		case 6:
			jose->exp += lvl;
			
			if(jose->exp > 2100){
				
				jose->nivel++;
				upagem=1;
				jose->exp=0;
			}
			break;
		case 7:
			jose->exp += lvl;
			
			if(jose->exp > 2800){
				
				jose->nivel++;
				upagem=1;
				jose->exp=0;
			}
			break;
		case 8:
			jose->exp += lvl;
			
			if(jose->exp > 3600){
				
				jose->nivel++;
				upagem=1;
				jose->exp=0;
			}
			break;
		case 9:
			jose->exp += lvl;
			
			if(jose->exp > 4500){
				
				jose->nivel++;
				upagem=1;
				jose->exp=0;
			}
			break;
		case 10:
			
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
		else
			upagem=0;
	}
	
	jose->vida += temp_vida;
	jose->armor += temp_armor;
	jose->dano += temp_dano;
	
	se_dropou= rand()%10;
	if(se_dropou == 0){
		entrega_equips(jose, derrotado);
	}
	
}

