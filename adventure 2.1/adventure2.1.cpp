/*projeto adventure 2.1-  Rafael Cascardo Campos 02/11/2016*/

#include <iostream>
#include <string>

#include <stdio.h>
#include <stdlib.h>       
#include <time.h>

#include "classes.cpp"
#include "interface.cpp"
#include "engine.cpp"

using namespace std;

int main(){
	
	int escolha=0;
	int opcao;

	
	jogador jose();

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
				printf("Voce deseja salvar o jogo?\n\nDigite 1 para sim e 0 para nao\n\n");
				scanf("%d", &opcao);

				if(opcao)
					jose.save();
				
				break;
			case 4:
				
				break;
		}
	
	}
	
	return 0;
}