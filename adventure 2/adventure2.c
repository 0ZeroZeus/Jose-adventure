/*projeto adventure 2-  Rafael Cascardo Campos 05/08/2015*/

#include <stdio.h>
#include <stdlib.h>       
#include <string.h>
#include <time.h>
#include "itens.h"
#include "campanha.h"
#include "luta.h"




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
	printf("Arma\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n\n",jose.weapon.nome, jose.weapon.vida, jose.weapon.armor, jose.weapon.dano, jose.weapon.dano_magico);
	printf("Acessorio de cabeca\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n\n",jose.headgear.nome, jose.headgear.vida, jose.headgear.armor, jose.headgear.dano, jose.headgear.dano_magico);
	printf("Peca de Torax\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n\n",jose.chestgear.nome, jose.chestgear.vida, jose.chestgear.armor, jose.chestgear.dano, jose.chestgear.dano_magico);
	printf("Peca das pernas\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n\n",jose.leggear.nome, jose.leggear.vida, jose.leggear.armor, jose.leggear.dano, jose.leggear.dano_magico);
	printf("Sapato\n%s\nBonus de vida: %d\nBonus de armadura: %d\nBonus de dano: %d\nBonus de dano magico: %d\n\n",jose.footgear.nome, jose.footgear.vida, jose.footgear.armor, jose.footgear.dano, jose.footgear.dano_magico);
	getchar();
	fclose(status);
	
	
}

void cria_personagem(){
	
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
	fprintf(status, "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n");
	
		
	fclose(status);
	
}

void monta_personagem(jogador* jose){
	
	FILE* equips;
	FILE* status;
	int existe, cont;
	char aux[50];
	char checa_tipo;
	int temp_vida, temp_armor, temp_dano, temp_magico;
	
	
	equips= fopen("equipamentos.txt","r");
	if(equips == NULL) {
		printf("\nNao foi possivel abrir o arquivo\n\n");
		getchar();
	}
	
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
	
	fscanf(status, "1 %d %d %d %d %d %d",&jose->nivel, &jose->exp, &jose->vida, &jose->armor, &jose->dano, &jose->dano_magico);
	fscanf(status, "%d %d %d %d %d %d %d %d %d %d\n", &jose->boss[0], &jose->boss[1], &jose->boss[2], &jose->boss[3], &jose->boss[4], &jose->boss[5], &jose->boss[6], &jose->boss[7], &jose->boss[8], &jose->boss[9]);
	fscanf(status, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", &jose->quest[0], &jose->quest[1], &jose->quest[2], &jose->quest[3], &jose->quest[4], &jose->quest[5], &jose->quest[6], &jose->quest[7], &jose->quest[8], &jose->quest[9], &jose->quest[10], &jose->quest[11], &jose->quest[12], &jose->quest[13], &jose->quest[14]);
	
	/*Aqui começa a leitura dos equipamentos de jose*/
	fscanf(equips,"%d", &existe);
	if(existe ==1){
		
		for(cont=0 ;cont<6 ;cont++){
			
			fscanf(equips,"%[^\n]\n", aux);
			fscanf(equips, "%c %d %d %d %d\n",&checa_tipo ,&temp_vida, &temp_armor, &temp_dano, &temp_magico);
			
			switch(checa_tipo){
				
				case 'w':
					
					strcpy(jose->weapon.nome, aux); 
					jose->weapon.tipo = checa_tipo;
					jose->weapon.vida = temp_vida;
					jose->weapon.armor = temp_armor;
					jose->weapon.dano = temp_dano;
					jose->weapon.dano_magico = temp_magico;
					break;
				
				case 'h':
					
					strcpy(jose->headgear.nome, aux);  
					jose->headgear.tipo = checa_tipo;
					jose->headgear.vida = temp_vida;
					jose->headgear.armor = temp_armor;
					jose->headgear.dano = temp_dano;
					jose->headgear.dano_magico = temp_magico;
					break;
					
				case 'c':
				
					strcpy(jose->chestgear.nome, aux); 
					jose->chestgear.tipo = checa_tipo;
					jose->chestgear.vida = temp_vida;
					jose->chestgear.armor = temp_armor;
					jose->chestgear.dano = temp_dano;
					jose->chestgear.dano_magico = temp_magico;
					break;
					
				case 'l':
					
					strcpy(jose->leggear.nome, aux); 
					jose->leggear.tipo = checa_tipo;
					jose->leggear.vida = temp_vida;
					jose->leggear.armor = temp_armor;
					jose->leggear.dano = temp_dano;
					jose->leggear.dano_magico = temp_magico;
					break;
					
				case 'f':
					
					strcpy(jose->footgear.nome, aux); 
					jose->footgear.tipo = checa_tipo;
					jose->footgear.vida = temp_vida;
					jose->footgear.armor = temp_armor;
					jose->footgear.dano = temp_dano;
					jose->footgear.dano_magico = temp_magico;
					break;
			}
		}
	}
		
		jose->vida += jose->weapon.vida + jose->headgear.vida + jose->chestgear.vida + jose->leggear.vida + jose->footgear.vida;
		jose->armor += jose->weapon.armor + jose->headgear.armor + jose->chestgear.armor + jose->leggear.armor + jose->footgear.armor;
		jose->dano += jose->weapon.dano + jose->headgear.dano + jose->chestgear.dano + jose->leggear.dano + jose->footgear.dano;
		jose->dano_magico += jose->weapon.dano_magico + jose->headgear.dano_magico + jose->chestgear.dano_magico + jose->leggear.dano_magico + jose->footgear.dano_magico;
		
	/*Aqui termina a leitura dos equipamentos de jose*/
	fclose(equips);
	fclose(status);
}

void save(jogador jose){
	
	FILE* equips;
	FILE* status;
	int opcao;
	
	printf("Voce deseja salvar o jogo?\n\nDigite 1 para sim e 0 para nao\n\n");
	scanf("%d", &opcao);
	
	if(opcao){
		
		equips= fopen("equipamentos.txt","w");
		if(equips == NULL) {
			printf("\nNao foi possivel abrir o arquivo\n\n");
			getchar();
		}
		
		fprintf(equips,"1\n\n");
		fprintf(equips,"%s\n%c %d %d %d %d\n\n",jose.weapon.nome,jose.weapon.tipo, jose.weapon.vida, jose.weapon.armor, jose.weapon.dano, jose.weapon.dano_magico);
		fprintf(equips,"%s\n%c %d %d %d %d\n\n",jose.headgear.nome,jose.headgear.tipo, jose.headgear.vida, jose.headgear.armor, jose.headgear.dano, jose.headgear.dano_magico);
		fprintf(equips,"%s\n%c %d %d %d %d\n\n",jose.chestgear.nome,jose.chestgear.tipo, jose.chestgear.vida, jose.chestgear.armor, jose.chestgear.dano, jose.chestgear.dano_magico);
		fprintf(equips,"%s\n%c %d %d %d %d\n\n",jose.leggear.nome,jose.leggear.tipo, jose.leggear.vida, jose.leggear.armor, jose.leggear.dano, jose.leggear.dano_magico);
		fprintf(equips,"%s\n%c %d %d %d %d\n\n",jose.footgear.nome,jose.footgear.tipo, jose.footgear.vida, jose.footgear.armor, jose.footgear.dano, jose.footgear.dano_magico);
		
		fclose(equips);
		
		status= fopen("status_basicos.txt","w");
		if(status == NULL) {
			printf("\nNao foi possivel abrir o arquivo\n\n");
			getchar();
		}
		fprintf(status,"1 %d %d %d %d %d %d\n\n", jose.nivel, jose.exp, jose.vida, jose.armor, jose.dano, jose.dano_magico);
		fprintf(status, "%d %d %d %d %d %d %d %d %d %d\n\n", jose.boss[0], jose.boss[1], jose.boss[2], jose.boss[3], jose.boss[4], jose.boss[5], jose.boss[6], jose.boss[7], jose.boss[8], jose.boss[9]);
		fprintf(status, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", jose.quest[0], jose.quest[1], jose.quest[2], jose.quest[3], jose.quest[4], jose.quest[5], jose.quest[6], jose.quest[7], jose.quest[8], jose.quest[9], jose.quest[10], jose.quest[11], jose.quest[12], jose.quest[13], jose.quest[14]);
		
		
		fclose(status);
	
	}
}
	



int main(){
	
	jogador jose;
	int escolha=0;
	
	limpa_itens(&jose.weapon);
	limpa_itens(&jose.headgear);
	limpa_itens(&jose.chestgear);
	limpa_itens(&jose.leggear);
	limpa_itens(&jose.footgear);
	monta_personagem(&jose);

	
	while(escolha != 4){
	
		escolha= menu_principal();
		
		switch(escolha){
			
			case 1:
				
				modo_campanha(&jose);
				
				break;
			case 2:
				system("clear");
				aventura(&jose);
				
				break;
			case 3:
				exibe_jose(jose);
				save(jose);
				
				break;
			case 4:
				
				break;
		}
	
	}
	
	return 0;
}