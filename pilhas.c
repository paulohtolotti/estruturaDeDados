#include <stdio.h>
#include <malloc.h>

//TAD para um membro da pilha
typedef struct temp {
	int		chave;
	struct temp *prox;
}membro;


//Ponteiros globais
membro *topo, *novo, *aux ;

void insert (int chave){
	//Alocando a chave ao novo
	novo = (membro *) malloc (sizeof(membro));
	novo->chave = chave;
	
	//Checar se a pilha está vazia ou não
	//Vazia
	if(topo == NULL){
		novo->prox = NULL;
	} 
	else {
		novo->prox = topo;
	}
	topo = novo;
	return;
} 

void showStack(){
	aux = topo;
	
	while(aux != NULL){
		printf("%i\n", aux->chave);
		printf("%c\n", 25);
		aux = aux->prox;
	}
	printf("NULL");
}
int main(){
	//Inicializando a pilha, que sempre começa vazia.
	topo = NULL;
	insert(15); insert(25);
	showStack();
	
}
