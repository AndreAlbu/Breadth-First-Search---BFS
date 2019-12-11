#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <queue>

// Definindo cores
#define BRANCO 0
#define CINZA 1
#define PRETO 2
#define NULO -1

// Definindo número de vertices
#define N 8

using namespace std;

int matriz[N][N]; //matriz-grafo
int cor [N];     //cor
int d   [N];    //distancia
int ant [N];   //antecessor
		

void BFS_VISIT(int s){
	
	int i;
			
	cor[s] = CINZA;
	d[s] = 0;
		
	queue<int> fila;
		
	fila.push(s);
	
	while(!fila.empty()){
		
		int u;
		
   		 u = fila.front();
   		 fila.pop();
									
		for(int j = 0; j < N; j++){
			
			if(matriz[u][j] == 1){
																
				if(cor[j] == BRANCO){
					
					cor[j] = CINZA;
					d[j] = d[u] + 1;
					ant[j] = u;
										
					fila.push(j);
					 
				}
				
			}
		}
		
		cor[u] = PRETO;
				
	}
	
}

void BFS(int matriz[N][N]){
	
	int i;
	         
	for(i = 0; i < N; i++){
		
		cor  [i] =  BRANCO;
		d	 [i] =  NULO;
		ant  [i] =  NULO;
	}
	
	
	for(i = 0; i < N; i++){
		
		if(cor[i] == BRANCO){
			
			BFS_VISIT(i);
		}
	}

}

void imprimi_info(){
	
	int i;

	printf("Posicao:    |");
	
	for(i = 0; i < N; i++){
		
		printf(" %d|", i);
	}
	
	printf("\n            -------------------\n");
	
	printf("Cor:        |");
	
	for(i = 0; i < N; i++){
		
		printf(" %d|", cor[i]);
	}
	
	printf("\n            -------------------\n");
	
	printf("Distancia:  |");
	
	for(i = 0; i < N; i++){
		
		printf(" %d|", d[i]);
	}
	
	printf("\n            -------------------\n");
	
	printf("Antecessor: |");
	
	for(i = 0; i < N; i++){
		
		printf(" %d|", ant[i]);
	}
}


void  criar(int matriz[N][N]){
	
	int i, j;
	
	for(i = 0; i < N; i++){
		
		for(j = 0; j < N; j++){
			
			matriz[i][j] = 0;
		}
	}
}

void imprimi(int matriz[N][N]){
	
	int i, j;
	
	for(i = 0; i < N; i++){
		printf("\n");
		for(j = 0; j < N; j++){
			
			printf(" %d ",matriz[i][j]);
		}
		
	}
}

void insere(int matriz[N][N]){
	
	int i, qtd;
	int origem, destino;
	
	printf("Informe os vertice a serem adcionados: \n");
	scanf("%d", &qtd);
	
	
	for(i = 0; i < qtd; i++){
		
		printf("Insira o %d ponto de origem: ", i);
		scanf("%d", &origem);
		
		if(origem >= N){
			
			origem = 0;
			printf("O vertice nao existe!\n");
			printf("Insira o %d ponto de origem: ", i);
			scanf("%d", &origem);
		}
		
		printf("Insira o %d ponto de destino: ", i);
		scanf("%d", &destino);
		
		if(destino >= N){
			
			destino = 0;
			printf("O vertice nao existe!\n");
			printf("Insira o %d ponto de destino: ", i);
			scanf("%d", &destino);
		}
		
		matriz[origem][destino] = 1;
		matriz[destino][origem] = 1;
		
	}
	
}

void retira(int matriz[N][N]){
	
	int origem, destino;
	
	printf("Informe a origem da aresta: ");
	scanf("%d", &origem);
	printf("Informe o destino da aresta: ");
	scanf("%d", &destino);
	
	matriz[origem][destino] = 0;
	matriz[destino][origem] = 0;
	
}


void vertice_adjacente(int matriz[N][N]){
	
	int i, cout = 0;
	int vertice;
	
	printf("Informe o vertice: ");
	scanf("%d", &vertice);
	
	for(i = 0; i < N; i++){
			
		if(matriz[vertice][i] == 1){
	
			printf(" %d -> %d\n", vertice, i);	
			cout++;
		}
	}
	
	if(cout == 0){
		
		printf("Nao existe!");
	}
		
}


int main(){
	
	int opcao;
	
	printf("1 -> Criar\n");
	printf("2 -> Adicionar\n");
	printf("3 -> Retirar\n");
	printf("4 -> Vertice Adjacente\n");
	printf("5 -> Imprimir Matriz\n");
	printf("6 -> Imprimir Informacao\n");
	printf("0 -> Sair\n");
	
	printf("\nOpcao: ");
	scanf("%d", &opcao);
	
	while(opcao != 0){
		
		switch(opcao){
			
			case 1:
				printf("Criando...\n");
				criar(matriz);
			break;
			
			case 2:
				insere(matriz);
			break;
					
			case 3:
				retira(matriz);
			break;
			
			case 4:
				vertice_adjacente(matriz);
			break;
			
			case 5:
				imprimi(matriz);
			break;
			
			case 6:
				BFS(matriz);
				imprimi_info();
			break;
	
		}
		
		printf("\nOpcao: ");
		scanf("%d", &opcao);
	}
			
	
	return 0;
}
