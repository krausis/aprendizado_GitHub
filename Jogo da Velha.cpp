// Instituição: FAFIT - Faculdades Integradas de Itararé
// Trabalho: JOGO DA VELHA
// Matéria: INTELIGENCIA ARTIFICIAL
// Professor: JOSE RICARDO
// Aluno: KLEBER RAUSIS FERREIRA
#include<stdio.h>
#include <stdlib.h>// necessario p/ as funcoes rand() e srand()
#include <time.h>//necessario p/ funcao time()
#include<math.h>

int tabuleiro[3][3];
int jog_atual, sel_jogada, contador=0;

void imprime_tabuleiro(){
	int cont=1;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(tabuleiro[i][j]==0){
				printf(" %d |",cont);
			}
			else if(tabuleiro[i][j]==1){
				printf(" X |");
			}
			else if(tabuleiro[i][j]==2){
				printf(" O |");
			}
			cont++;	
		}
		printf("\n");	
	}
}

int tabuleiro_completo(){
	int aux=1;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(tabuleiro[i][j]==0){
				aux=0;
			}
		}
	}
	return aux;
}

int verifica_jogada(int jogada,int jogador){
	switch(jogada){
		case 1:
			if(tabuleiro[0][0]==0){
				tabuleiro[0][0]=jogador;
				return 1;
			}
			else{
				return 0;
			}
		break;
		case 2:
			if(tabuleiro[0][1]==0){
				tabuleiro[0][1]=jogador;
				return 1;
			}
			else{
				return 0;
			}
		break;
		case 3:
			if(tabuleiro[0][2]==0){
				tabuleiro[0][2]=jogador;
				return 1;
			}
			else{
				return 0;
			}
		break;
		case 4:
			if(tabuleiro[1][0]==0){
				tabuleiro[0][3]=jogador;
				return 1;
			}
			else{
				return 0;
			}
		break;
		case 5:
			if(tabuleiro[1][1]==0){
				tabuleiro[1][1]=jogador;
				return 1;
			}
			else{
				return 0;
			}
		break;
		case 6:
			if(tabuleiro[1][2]==0){
				tabuleiro[1][2]=jogador;
				return 1;
			}
			else{
				return 0;
			}
		break;
		case 7:
			if(tabuleiro[2][0]==0){
				tabuleiro[2][0]=jogador;
				return 1;
			}
			else{
				return 0;
			}
		break;
		case 8:
			if(tabuleiro[2][1]==0){
				tabuleiro[2][1]=jogador;
				return 1;
			}
			else{
				return 0;
			}
		break;
		case 9:
			if(tabuleiro[2][2]==0){
				tabuleiro[2][2]=jogador;
				return 1;
			}
			else{
				return 0;
			}
		break;
	}
}

//Jogadas para vencer
int vitoria()
{
	if(tabuleiro[0][0]==1 && tabuleiro[0][2]==1 && tabuleiro[0][1]==0)
	{
		tabuleiro[0][1]=1;
		return 1;
	}
	else if(tabuleiro[1][1]==1 && tabuleiro[2][1]==1 && tabuleiro[0][1]==0)
	{
		tabuleiro[0][1]=1;
		return 1;
	}
	else if(tabuleiro[1][0]==1 && tabuleiro[1][1]==1 && tabuleiro[1][2]==0)
	{
		tabuleiro[1][2]=1;
		return 1;	
	}
	else if(tabuleiro[1][1]==1 && tabuleiro[0][1]==1 && tabuleiro[2][1]==0)
	{
		tabuleiro[2][1]=1;
		return 1;
	}
	else if(tabuleiro[2][1]==1 && tabuleiro[0][1]==1 && tabuleiro[1][1]==0)
	{
		tabuleiro[1][1]=1;
		return 1;					
	}
	else if(tabuleiro[0][0]==1 && tabuleiro[2][0]==1 && tabuleiro[1][0]==0)
	{
		tabuleiro[1][0]=1;
		return 1;
	}
	else if(tabuleiro[1][2]==1 && tabuleiro[1][1]==1 && tabuleiro[1][0]==0)
	{
		tabuleiro[1][0]=1;
		return 1;
	}
	else if(tabuleiro[1][0]==1 && tabuleiro[1][2]==1 && tabuleiro[1][1]==0)
	{
		tabuleiro[1][1]=1;
		return 1;		
	}
	else if(tabuleiro[0][2]==1 && tabuleiro[2][2]==1 && tabuleiro[1][2]==0)
	{
		tabuleiro[1][2]=1;
		return 1;
	}
	else if(tabuleiro[2][0]==1 && tabuleiro[2][2]==1 && tabuleiro[2][1]==0)
	{
		tabuleiro[2][1]=1;
		return 1;
	}
	else if((tabuleiro[0][0]==1 && tabuleiro[2][2]==1 && tabuleiro[1][1]==0) || (tabuleiro[0][2]==1 && tabuleiro[2][0]==1 && tabuleiro[1][1]==0))
	{
		tabuleiro[1][1]=1;
		return 1;
	}
	else if((tabuleiro[0][0]==1 && tabuleiro[0][1]==1 && tabuleiro[0][2]==0) || (tabuleiro[1][2]==1 && tabuleiro[2][2]==1 && tabuleiro[0][2]==0) || (tabuleiro[2][0]==1 && tabuleiro[1][1]==1 && tabuleiro[0][2]==0))
	{
		tabuleiro[0][2]=1;
		return 1;
	}
	else if((tabuleiro[0][0]==1 && tabuleiro[1][0]==1 && tabuleiro[2][0]==0) || (tabuleiro[2][1]==1 && tabuleiro[2][2]==1 && tabuleiro[2][0]==0) || (tabuleiro[0][2]==1 && tabuleiro[1][1]==1 && tabuleiro[2][0]==0))
	{
		tabuleiro[2][0]=1;
		return 1;
	}
	else if((tabuleiro[0][1]==1 && tabuleiro[0][2]==1 && tabuleiro[0][0]==0) || (tabuleiro[1][0]==1 && tabuleiro[2][0]==1 && tabuleiro[0][0]==0) || (tabuleiro[1][1]==1 && tabuleiro[2][2]==1 && tabuleiro[0][0]==0))
	{
		tabuleiro[0][0]=1;
		return 1;
	}
	else if((tabuleiro[0][2]==1 && tabuleiro[1][2]==1 && tabuleiro[2][2]==0) || (tabuleiro[2][0]==1 && tabuleiro[2][1]==1 && tabuleiro[2][2]==0) || (tabuleiro[0][0]==1 && tabuleiro[1][1]==1 && tabuleiro[2][2]==0))
	{
		tabuleiro[2][2]=1;
		return 1;
	}else{
		return 0;
	}	
}

//Jogadas para fechar oponente
int fecharJogador()
{
	if(tabuleiro[0][0]==2 && tabuleiro[0][2]==2 && tabuleiro[0][1]==0)
	{
		tabuleiro[0][1]=1;
		return 1;
	}
	else if(tabuleiro[1][0]==2 && tabuleiro[1][1]==2 && tabuleiro[1][2]==0)
	{
		tabuleiro[1][2]=1;
		return 1;	
	}
	else if(tabuleiro[1][0]==2 && tabuleiro[1][2]==2 && tabuleiro[1][1]==0)
	{
		tabuleiro[1][1]=1;
		return 1;	
	}
	else if(tabuleiro[1][1]==2 && tabuleiro[2][1]==2 && tabuleiro[0][1]==0)
	{
		tabuleiro[0][1]=1;
		return 1;
	}
	else if(tabuleiro[2][1]==2 && tabuleiro[0][1]==2 && tabuleiro[1][1]==0)
	{
		tabuleiro[1][1]=1;
		return 1;	
	}
	else if(tabuleiro[1][1]==2 && tabuleiro[0][1]==2 && tabuleiro[2][1]==0)
	{
		tabuleiro[2][1]=1;
		return 1;
	}
	else if(tabuleiro[1][1]==2 && tabuleiro[1][2]==2 && tabuleiro[1][0]==0)
	{
		tabuleiro[1][0]=1;
		return 1;					
	}
	else if(tabuleiro[0][0]==2 && tabuleiro[2][0]==2 && tabuleiro[1][0]==0)
	{
		tabuleiro[1][0]=1;
		return 1;
	}
	else if(tabuleiro[0][2]==2 && tabuleiro[2][2]==2 && tabuleiro[1][2]==0)
	{
		tabuleiro[1][2]=1;
		return 1;
	}
	else if(tabuleiro[2][0]==2 && tabuleiro[2][2]==2 && tabuleiro[2][1]==0)
	{
		tabuleiro[2][1]=1;
		return 1;
	}
	else if(tabuleiro[0][2]==2 && tabuleiro[1][1]==2 && tabuleiro[2][0]==0)
	{
		tabuleiro[2][0]=1;
		return 1;	
	}
	else if((tabuleiro[0][0]==2 && tabuleiro[2][2]==2 && tabuleiro[1][1]==0) || (tabuleiro[0][2]==2 && tabuleiro[2][0]==2 && tabuleiro[1][1]==0))
	{
		tabuleiro[1][1]=1;
		return 1;
	}
	else if((tabuleiro[0][0]==2 && tabuleiro[0][1]==2 && tabuleiro[0][2]==0) || (tabuleiro[1][2]==2 && tabuleiro[2][2]==2 && tabuleiro[0][2]==0) || (tabuleiro[2][0]==2 && tabuleiro[1][1]==2 && tabuleiro[0][2]==0))
	{
		tabuleiro[0][2]=1;
		return 1;
	}
	else if((tabuleiro[0][0]==2 && tabuleiro[1][0]==2 && tabuleiro[2][0]==0) || (tabuleiro[2][1]==2 && tabuleiro[2][2]==2 && tabuleiro[2][0]==0) || (tabuleiro[0][2]==2 && tabuleiro[1][1]==2 && tabuleiro[2][0]==0))
	{
		tabuleiro[2][0]=1;
		return 1;
	}
	else if((tabuleiro[0][1]==2 && tabuleiro[0][2]==2 && tabuleiro[0][0]==0) || (tabuleiro[1][0]==2 && tabuleiro[2][0]==2 && tabuleiro[0][0]==0) || (tabuleiro[1][1]==2 && tabuleiro[2][2]==2 && tabuleiro[0][0]==0))
	{
		tabuleiro[0][0]=1;
		return 1;
	}
	else if((tabuleiro[0][2]==2 && tabuleiro[1][2]==2 && tabuleiro[2][2]==0) || (tabuleiro[2][0]==2 && tabuleiro[2][1]==2 && tabuleiro[2][2]==0) || (tabuleiro[0][0]==2 && tabuleiro[1][1]==2 && tabuleiro[2][2]==0))
	{
		tabuleiro[2][2]=1;
		return 1;
	}
	else
	{
		return 0;
	}	
}

//Jogada 1 IA
void jogada1(){
	int aux;
	aux=rand()%3+1;
	
	if(aux==1)
	{
		tabuleiro[0][0]=1;
	}
	else if(aux==2)
	{
		tabuleiro[0][2]=1;
	}
	else if(aux==3)
	{
		tabuleiro[2][0]=1;
	}
	else if(aux==4)
	{
		tabuleiro[2][2]=1;
	}				
}

//Jogada 2 IA	
void jogada2()
{
	if(tabuleiro[0][0]==2 || tabuleiro[0][2]==2 || tabuleiro[2][0]==2 || tabuleiro[2][2]==2)
	{
		tabuleiro[1][1]=1;
	}
	else if(tabuleiro[0][1]==2 || tabuleiro[1][0]==2)
	{
		tabuleiro[0][0]=1;
	}
	else if(tabuleiro[1][2]==2 || tabuleiro[2][1]==2)
	{
		tabuleiro[2][2]=1;
	}
	else if(tabuleiro[1][1]==2)
	{
		jogada1();
	}	
}	

//Jogada 3 IA
void jogada3()
{
	// Jogadas no centro
		if(tabuleiro[1][1]==2)
		{
			if(tabuleiro[0][0]==1)
			{
				tabuleiro[2][2]=1;
			}
			else if(tabuleiro[0][2]==1)
			{
				tabuleiro[2][0]=1;
			}
			else if(tabuleiro[2][0]==1)
			{
				tabuleiro[0][2]=1;
			}
			else if(tabuleiro[2][2]==1)
			{
				tabuleiro[0][0]=1;
			}
		}
		else
		{
			// Jogadas fora do centro
			if(tabuleiro[0][0]==1)
			{
				//Horizontal 1 e vertical 1
				if(tabuleiro[0][1]==0 && tabuleiro[0][2]==0)
				{
					tabuleiro[0][2]=1;
				}
				else if(tabuleiro[1][0]==0 && tabuleiro[2][0]==0)
				{
					tabuleiro[2][0]=1;
				}
			}
			else if(tabuleiro[0][2]==1)
			{
				//Jogadas para Horizontal 3 e vertical 1
				if(tabuleiro[0][1]==0 && tabuleiro[0][0]==0)
				{
					tabuleiro[0][0]=1;
				}
				else if(tabuleiro[1][2]==0 && tabuleiro[2][2]==0)
				{
					tabuleiro[2][2]=1;
				}
			}
			else if(tabuleiro[2][0]==1)
			{
				//Horizontal 1 e vertical 3
				if(tabuleiro[1][0]==0 && tabuleiro[0][0]==0)
				{
					tabuleiro[0][0]=1;
				}
				else if(tabuleiro[2][1]==0 && tabuleiro[2][2]==0)
				{
					tabuleiro[2][2]=1;
				}
			}
			else if(tabuleiro[2][2]==1)
			{
				//Horizontal 3 e vertical 3
				if(tabuleiro[1][2]==0 && tabuleiro[0][2]==0)
				{
					tabuleiro[0][2]=1;
				}
				else if(tabuleiro[2][1]==0 && tabuleiro[2][0]==0)
				{
					tabuleiro[2][0]=1;
				}
			}
		}		
}

//Jogada 4 IA
void jogada4()
{
	if(fecharJogador()==0)
	{
		if(tabuleiro[1][1]==1)
		{
			//Jogadas de defesa
			if(tabuleiro[0][0]==2 && tabuleiro[0][1]==2)
			{
				tabuleiro[0][2]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[0][2]==2)
			{
				tabuleiro[0][0]=1;
			}
			else if(tabuleiro[2][0]==2 && tabuleiro[2][1]==2)
			{
				tabuleiro[2][2]=1;
			}
			else if(tabuleiro[2][1]==2 && tabuleiro[2][2]==2)
			{
				tabuleiro[2][0]=1;
			}
			else if(tabuleiro[0][0]==2 && tabuleiro[1][0]==2)
			{
				tabuleiro[2][0]=1;
			}
			else if(tabuleiro[2][0]==2 && tabuleiro[1][0]==2)
			{
				tabuleiro[0][0]=1;
			}
			else if(tabuleiro[2][2]==2 && tabuleiro[1][2]==2)
			{
				tabuleiro[0][2]=1;
			}
			else if(tabuleiro[0][2]==2 && tabuleiro[1][2]==2)
			{
				tabuleiro[2][2]=1;
			}
			else if(tabuleiro[0][0]==2 && tabuleiro[0][2]==2)
			{
				tabuleiro[0][1]=1;
			}
			else if(tabuleiro[0][0]==2 && tabuleiro[2][0]==2)
			{
				tabuleiro[1][0]=1;
			}
			else if(tabuleiro[2][0]==2 && tabuleiro[2][2]==2)
			{
				tabuleiro[2][1]=1;
			}
			else if(tabuleiro[2][2]==2 && tabuleiro[0][2]==2)
			{
				tabuleiro[1][2]=1;
			}
			else if(tabuleiro[0][0]==2 && tabuleiro[1][2]==2)
			{
				tabuleiro[2][1]=1;
			}
			else if(tabuleiro[0][2]==2 && tabuleiro[1][0]==2)
			{
				tabuleiro[0][0]=1;
			}
			else if(tabuleiro[2][0]==2 && tabuleiro[1][2]==2)
			{
				tabuleiro[0][1]=1;
			}
			else if(tabuleiro[1][0]==2 && tabuleiro[2][2]==2)
			{
				tabuleiro[0][0]=1;
			}
			else if((tabuleiro[0][0]==2 && tabuleiro[2][2]==2)|| (tabuleiro[2][0]==2 && tabuleiro[0][2]==2))
			{
				tabuleiro[0][1]=1;
			}
		}
		else if(tabuleiro[1][1]==2)
		{
			//Defesa nos cantos
			if(tabuleiro[0][1]==2)
			{
				tabuleiro[2][1]=1;
			}
			else if((tabuleiro[0][2]==2) || (tabuleiro[0][0]==2 && tabuleiro[2][2]==1))
			{
				tabuleiro[2][0]=1;
			}
			else if(tabuleiro[1][0]==2)
			{
				tabuleiro[1][2]=1;
			}
			else if(tabuleiro[1][2]==2 && tabuleiro[0][0]==1)
			{
				tabuleiro[1][0]=1;
			}
			else if((tabuleiro[2][0]==2 && tabuleiro[0][0]==1) || (tabuleiro[2][2]==2 && tabuleiro[0][0]==1) || (tabuleiro[2][0]==2 && tabuleiro[2][2]==1))
			{
				tabuleiro[0][2]=1;
			}
			else if(tabuleiro[2][1]==2)
			{
				tabuleiro[0][1]=1;
			}
			else if((tabuleiro[0][0]==2 && tabuleiro[0][1]==1) || (tabuleiro[2][0]==2 && tabuleiro[0][2]==1) || (tabuleiro[0][0]==2 && tabuleiro[2][0]==1))
			{
				tabuleiro[2][2]=1;
			}
			else if((tabuleiro[2][2]==2) || (tabuleiro[0][2]==2 && tabuleiro[2][0]==1))
			{
				tabuleiro[0][0]=1;
			}
		}
		else
		{
			//Defesa nos centros
			if(tabuleiro[0][1]==2 && tabuleiro[0][2]==2 && tabuleiro[0][0]==1)
			{
				tabuleiro[1][0]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[1][0]==2 && tabuleiro[0][0]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[1][2]==2 && tabuleiro[0][0]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if((tabuleiro[0][1]==2 && tabuleiro[2][1]==2 && tabuleiro[1][1]==0) || (tabuleiro[1][0]==2 && tabuleiro[1][2]==2 && tabuleiro[1][1]==0) || (tabuleiro[0][1]==2 && tabuleiro[2][0]==2 && tabuleiro[0][0]==1))
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[2][2]==2 && tabuleiro[0][0]==1)
			{
				tabuleiro[2][1]=1;
			}
			else if(tabuleiro[0][0]==2 && tabuleiro[0][1]==2 && tabuleiro[0][2]==1)
			{
				tabuleiro[2][1]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[1][0]==2 && tabuleiro[0][2]==1)
			{
				tabuleiro[1][2]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[1][2]==2 && tabuleiro[0][2]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[2][0]==2 && tabuleiro[0][2]==1)
			{
				tabuleiro[2][1]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[2][0]==2 && tabuleiro[0][2]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[2][2]==2 && tabuleiro[0][2]==1)
			{
				tabuleiro[2][1]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[1][0]==2 && tabuleiro[2][0]==1)
			{
				tabuleiro[2][2]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[1][2]==2 && tabuleiro[2][0]==1)
			{
				tabuleiro[0][0]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[2][2]==2 && tabuleiro[2][0]==1)
			{
				tabuleiro[0][0]=1;
			}
			else if(tabuleiro[0][1]==2 && tabuleiro[1][0]==2 && tabuleiro[0][0]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[1][0]==2 && tabuleiro[2][0]==2 && tabuleiro[0][0]==1)
			{
				tabuleiro[0][2]=1;
			}
			else if(tabuleiro[1][0]==2 && tabuleiro[2][1]==2 && tabuleiro[0][0]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[1][0]==2 && tabuleiro[2][2]==2 && tabuleiro[0][0]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if((tabuleiro[0][0]==2 && tabuleiro[1][2]==2 && tabuleiro[2][2]==1) || (tabuleiro[0][1]==2 && tabuleiro[1][2]==2 && tabuleiro[2][2]==1))
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[1][2]==2 && tabuleiro[2][0]==2 && tabuleiro[2][2]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[1][2]==2 && tabuleiro[2][1]==2 && tabuleiro[2][2]==1)
			{
				tabuleiro[0][0]=1;
			}
			else if(tabuleiro[1][2]==2 && tabuleiro[2][2]==2 && tabuleiro[2][2]==1)
			{
				tabuleiro[0][0]=1;
			}
			else if(tabuleiro[2][1]==2 && tabuleiro[0][0]==2 && tabuleiro[2][2]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[2][1]==2 && tabuleiro[0][2]==2 && tabuleiro[2][2]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[2][1]==2 && tabuleiro[1][0]==2 && tabuleiro[2][2]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[2][1]==2 && tabuleiro[1][2]==2 && tabuleiro[2][2]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[2][1]==2 && tabuleiro[2][0]==2 && tabuleiro[2][2]==1)
			{
				tabuleiro[0][1]=1;
			}
			else if(tabuleiro[0][2]==2 && tabuleiro[1][2]==2 && tabuleiro[2][2]==1)
			{
				tabuleiro[1][1]=1;
			}
			else if(tabuleiro[1][1]==2 && tabuleiro[1][2]==2 && tabuleiro[2][2]==1)
			{
				tabuleiro[1][0]=1;
			}
		}
	}
}

// Jogada 5 IA
void jogada5(){
	
	if(vitoria()==0){
		//Defesa fachando jogadas
		if(fecharJogador()==0)
		{
			if((tabuleiro[0][0]==1 && tabuleiro[2][0]==1 && tabuleiro[0][2]==2) || (tabuleiro[0][0]==1 && tabuleiro[2][0]==1 && tabuleiro[0][1]==2))
			{
				tabuleiro[2][2]=1;
			}
			else if((tabuleiro[0][0]==1 && tabuleiro[2][0]==1 && tabuleiro[2][2]==2) || (tabuleiro[0][0]==1 && tabuleiro[2][0]==1 && tabuleiro[2][1]==2))
			{
				tabuleiro[0][2]=1;
			}
			else if((tabuleiro[0][0]==1 && tabuleiro[0][2]==1 && tabuleiro[2][2]==2) || (tabuleiro[0][0]==1 && tabuleiro[0][2]==1 && tabuleiro[1][2]==2))
			{
				tabuleiro[2][0]=1;
			}
			else if((tabuleiro[0][0]==1 && tabuleiro[0][2]==1 && tabuleiro[2][0]==2) || (tabuleiro[0][0]==1 && tabuleiro[0][2]==1 && tabuleiro[1][0]==2))
			{
				tabuleiro[2][2]=1;
			}
			else if((tabuleiro[0][2]==1 && tabuleiro[2][2]==1 && tabuleiro[0][0]==2) || (tabuleiro[0][2]==1 && tabuleiro[2][2]==1 && tabuleiro[0][1]==2))
			{
				tabuleiro[2][0]=1;
			}
			else if((tabuleiro[0][2]==1 && tabuleiro[2][2]==1 && tabuleiro[2][0]==2) || (tabuleiro[0][2]==1 && tabuleiro[2][2]==1 && tabuleiro[2][1]==2))
			{
				tabuleiro[0][0]=1;
			}
			else if((tabuleiro[2][0]==1 && tabuleiro[2][2]==1 && tabuleiro[0][2]==2) || (tabuleiro[2][0]==1 && tabuleiro[2][2]==1 && tabuleiro[1][2]==2))
			{
				tabuleiro[0][0]=1;
			}
			else if((tabuleiro[2][0]==1 && tabuleiro[2][2]==1 && tabuleiro[0][0]==2) || (tabuleiro[2][0]==1 && tabuleiro[2][2]==1 && tabuleiro[1][0]==2))
			{
				tabuleiro[0][2]=1;
			}
		}
	}
}

// Procura jogada disponivel a partir da jogada 6
void jogDisp()
{
	int l,c;
	int j,i;
	for(i=0;i<3;i++)
	{
		//Procura primeira jogadas possiveis
		for(j=0;j<3;j++)
		{
			if(tabuleiro[i][j]==0)
			{
				l=i;
				c=j;
			}
		}
	}
	//Joga em jogada disponivel encontrada
	tabuleiro[l][c]=1;	
}

void chamaIA(){
	
	if(contador==1){
		jogada1();
		}
	
	if(contador==2){
		jogada2();
	}
	
	if(contador==3){
		jogada3();	
	}
	
	if(contador==4){
		jogada4();
	} 	
	
	if(contador==5){
		jogada5();
	}
	
	if(contador==6){
		if(vitoria()==0){
			if(fecharJogador()==0){
				jogDisp();
			}	
		}
	}
	
	if(contador==7){
		if(vitoria()==0){
			if(fecharJogador()==0){
				jogDisp();
			}		
		}
	}
	
	if(contador==8){
		if(vitoria()==0){
			if(fecharJogador()==0){
				jogDisp();
			}
							
		}
	}
	
	if(contador==9){
		if(vitoria()==0){
			if(fecharJogador()==0){
				jogDisp();
			}
		}
	}
	
}

int verifica_termino(){
	if(((tabuleiro[0][0]==tabuleiro[0][1]&&tabuleiro[0][0]==tabuleiro[0][2])&&
	(tabuleiro[0][0]==1))||
	((tabuleiro[1][0]==tabuleiro[1][1]&&tabuleiro[1][0]==tabuleiro[1][2])&&
	(tabuleiro[1][0]==1))||
	((tabuleiro[2][0]==tabuleiro[2][1]&&tabuleiro[2][0]==tabuleiro[2][2])&&
	(tabuleiro[2][0]==1))||
	((tabuleiro[0][0]==tabuleiro[1][0]&&tabuleiro[0][0]==tabuleiro[2][0])&&
	(tabuleiro[0][0]==1))||
	((tabuleiro[0][1]==tabuleiro[1][1]&&tabuleiro[0][1]==tabuleiro[2][1])&&
	(tabuleiro[0][1]==1))||
	((tabuleiro[0][2]==tabuleiro[1][2]&&tabuleiro[0][2]==tabuleiro[2][2])&&
	(tabuleiro[0][2]==1))||
	((tabuleiro[0][0]==tabuleiro[1][1]&&tabuleiro[0][0]==tabuleiro[2][2])&&
	(tabuleiro[0][0]==1))||
	((tabuleiro[2][0]==tabuleiro[1][1]&&tabuleiro[0][2]==tabuleiro[2][0])&&
	(tabuleiro[2][0]==1)))
	{
		return 1;
	}
	else if(((tabuleiro[0][0]==tabuleiro[0][1]&&tabuleiro[0][0]==tabuleiro[0][2])&&
	(tabuleiro[0][0]==2))||
	((tabuleiro[1][0]==tabuleiro[1][1]&&tabuleiro[1][0]==tabuleiro[1][2])&&
	(tabuleiro[1][0]==2))||
	((tabuleiro[2][0]==tabuleiro[2][1]&&tabuleiro[2][0]==tabuleiro[2][2])&&
	(tabuleiro[2][0]==2))||
	((tabuleiro[0][0]==tabuleiro[1][0]&&tabuleiro[0][0]==tabuleiro[2][0])&&
	(tabuleiro[0][0]==2))||
	((tabuleiro[0][1]==tabuleiro[1][1]&&tabuleiro[0][1]==tabuleiro[2][1])&&
	(tabuleiro[0][1]==2))||
	((tabuleiro[0][2]==tabuleiro[1][2]&&tabuleiro[0][2]==tabuleiro[2][2])&&
	(tabuleiro[0][2]==2))||
	((tabuleiro[0][0]==tabuleiro[1][1]&&tabuleiro[0][0]==tabuleiro[2][2])&&
	(tabuleiro[0][0]==2))||
	((tabuleiro[2][0]==tabuleiro[1][1]&&tabuleiro[0][2]==tabuleiro[2][0])&&
	(tabuleiro[2][0]==2)))
	{
		return 2;
	}
	else if(tabuleiro_completo())
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int main(){
	int jogada,termino;
	//inicializa matriz
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			tabuleiro[i][j]=0;		
		}
	}
	
	//Seleciona jogador aleatoriamente	
	srand(time(NULL));
	jog_atual=(rand()%2)+1;
	
	do{
		imprime_tabuleiro();
		//Computador
		if(jog_atual==1){
			contador++;
			//chama IA
			chamaIA();
			
			//Range de selecao de jogada
			sel_jogada=(rand()%2);
			if(sel_jogada==1){
				tabuleiro[0][0]==1;
			}else if(tabuleiro[0][0]==1 && tabuleiro[0][1]==1){
				tabuleiro[0][2]==1;
			}
			printf("\n");
		}
		else if(jog_atual==2){
			//Jogador
			contador++;
			printf("\nJogador %d",jog_atual);
			printf("\nInforme sua jogada:");
			scanf("%d",&jogada);
			while(verifica_jogada(jogada,jog_atual)==0){
				imprime_tabuleiro();
				printf("\nJogada invalida tente denovo:");
				scanf("%d",&jogada);
			}			
		}
		if(jog_atual==1){
			jog_atual=2;
		}	
		else{
			jog_atual=1;
		}
		termino=verifica_termino();
	}while(termino==0);
	imprime_tabuleiro();
	if(termino!=3){
		printf("O Jogador %d ganhou!\n\n",termino);
	}
	else{
		printf("Jogo terminou, deu velha!\n\n");
	}
	system("pause");
}
