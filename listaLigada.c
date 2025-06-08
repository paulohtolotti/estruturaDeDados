#include <stdio.h>
#include <malloc.h>

typedef struct temp {
	int	key;
	struct temp *next;
}member;

member *start, *newMember, *aux;
int length = 0;

//Insere quando a lista está populada
void insert (int val, int pos){
	if (pos < 1 || pos > length + 1){
		printf("Posicao invalida\n");
		return;
	}
	newMember = (member *) malloc (sizeof(member));
	newMember->key = val;
	
	if(start == NULL){
		newMember->next = NULL; start = newMember;
	} else if(pos == 1){
		newMember->next = start;
		start = newMember;
	} else {
		aux = start; int i = 1;
		while (i <= pos - 2){
			aux = aux->next;
			i++;
		}
		newMember->next = aux->next;
		aux->next = newMember;
	}
	length ++;
}

void removeIn(int pos){
	if (start == NULL) {
		printf("Lista vazia\n\n"); 
		return;
	}
	
	if(pos < 1 || pos > length) {
		printf("Posicao invalida\n\n"); 
		return;
	}
	
	aux = start;
	if(pos == 1){
		start = start->next;
		free(aux);
	} else {
		int i = 1;
		while (i <= pos - 2) {
			aux = aux->next;
			i++; 
		} 
		aux->next = aux->next->next;
	}
	
	length--;
}
void showList(){
	aux = start;
	while (aux != NULL){
		printf("%i => ", aux->key); 
		aux = aux->next;	
	}
	printf("NULL\n\n");
}
int main(){
	
	start = NULL; //Inicializo a lista ligada vazia.
	removeIn(88);
	insert(1,1); insert(7,2); insert(15, 3);
	showList(); removeIn(88);
	insert(27, 2); showList(); insert(55, 5); showList();
	
	removeIn(2); showList(); removeIn(4); showList();
}
