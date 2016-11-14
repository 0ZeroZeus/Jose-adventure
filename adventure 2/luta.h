void Emorreu(jogador *jose){
	
	jose->nivel=1;
	jose->exp=0;
	jose->vida=0;
	jose->armor=0;
	jose->dano=0;
	jose->dano_magico=0;
	jose->vida_atual=0;
	limpa_itens(&jose->weapon);
	limpa_itens(&jose->headgear);
	limpa_itens(&jose->chestgear);
	limpa_itens(&jose->leggear);
	limpa_itens(&jose->footgear);
	
}

monstro encontra_monstro(int ID){
	
	FILE *fp;
	monstro ancora;
	
	fp=fopen("monstros.txt","r");
	
	do{
		fscanf(fp,"%d %[^\n]\n", &ancora.id, ancora.nome);
		fscanf(fp, "%c %d %d %d %d\n",&ancora.tipo, &ancora.vida, &ancora.armor, &ancora.dano, &ancora.dano_magico);
		fscanf(fp,"%d %d %d %d\n", &ancora.drops[0], &ancora.drops[1], &ancora.drops[2], &ancora.drops[3]);
		
	}while(ancora.id != ID);
	
	fclose(fp);
	return(ancora);
}

int luta(jogador* jose, monstro enemy){
	
	int opcao,dano_jose,dano_inimigo, fuga=0;
	
	srand(time(NULL));
	system("clear");
	
	while(jose->vida_atual >0 && enemy.vida >0){
		
		printf("Jose\n\nSeu nivel: %d\nSua vida: %d\nSua armadura: %d\nSeu dano: %d\nSeu dano magico: %d\n\n", jose->nivel, jose->vida_atual, jose->armor, jose->dano, jose->dano_magico);
		printf("%s\n\nVida do inimigo: %d\n", enemy.nome, enemy.vida);
		
		printf("Escolha o que fazer\n1 - atacar com sua arma\n2 - atacar com sua magia\n3 - fugir\n");
		scanf("%d", &opcao);
		
		if(enemy.tipo == 'f')
			dano_inimigo= (enemy.dano - jose->armor);
		else if(enemy.tipo == 'm')
			dano_inimigo= (enemy.dano_magico - (jose->armor/2));
		
		if(opcao == 1)
			dano_jose= (jose->dano - enemy.armor);
		else if(opcao == 2)
			dano_jose= (jose->dano_magico - (enemy.armor/2));
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
		Emorreu(jose);
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
	
	resultado= luta(jose, encontra_monstro(ID));
	
	if(resultado){
		premiacao(jose, lvl, encontra_monstro(ID));
	}
	
	return(resultado);
}

int batalha_boss(jogador* jose, int lvl){
	
	srand(time(NULL));
	int random, resultado;
	int ID=0;
	
	ID += lvl*1000;
	ID += QNT_MONST;

	resultado= luta(jose, encontra_monstro(ID));
	
	if(resultado){
		jose->boss[lvl-1] = 1;
		premiacao(jose, lvl, encontra_monstro(ID));
	}
	
	return(resultado);
}

void aventura(jogador* jose){
	
	int opcao_lugar=11;
	int opcao_bat=1;
	int opcao_boss;
	jose->vida_atual=jose->vida;
	
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
