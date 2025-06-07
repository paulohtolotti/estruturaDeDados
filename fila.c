#include <stdio.h>
#include <malloc.h>

typedef struct temp{
	int				key;
	struct temp		*next;
}member;

member *head, *tail, *newMember, *aux;


void insert(int val) {
	newMember = (member *) malloc (sizeof(member));
	newMember->key = val;
	newMember->next = NULL; //Proximo do novo membro sempre é o NULL (fim da fila)
	
	if (head == NULL) head = newMember; //Fila vazia. O inicio vira o novo membro
	else tail->next = newMember; //Proximo do fim vira o novo.
	
	tail = newMember;
}

void dequeue(){
	if (head == NULL) {
		printf("Fila vazia");
		return;
	}
	aux = head;
	head = head->next;
	free(aux);
	
}
void showQueue(){
	aux = head;
	while (aux != NULL){
		printf("%i => ", aux->key);
		aux = aux->next;
	}
	printf("NULL\n\n");
}

void peek(){
	if (head == NULL) {
		printf("NULL");
		return;
	}
	printf("Peek: %i\n\n", head->key);
}
int main(){
	head = NULL;	//Inicializa a fila vazia
	insert(3); insert(1); insert(4); insert(1); insert(5);
	showQueue(); dequeue(); peek();
	showQueue(); dequeue(); peek(); dequeue(); dequeue(); dequeue();
	showQueue();
};
