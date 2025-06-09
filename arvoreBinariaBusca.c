#include <stdio.h>
#include <malloc.h>

typedef struct temp {
	int				key;
	struct temp		*right;
	struct temp		*left;
}member;

member *root, *newMember, *aux;

void insert (int val){
	newMember = (member *) malloc (sizeof(member));
	newMember->key = val; newMember->right = NULL; newMember->left = NULL;
	
	//Árvore vazia: o novo membro vira a raíz.
	if(root == NULL){
		root = newMember;
		return;
	}
	
	aux = root;
	while(1){
		if(newMember->key > aux->key){
			if(aux->right == NULL) break //Encontrou
			else aux = aux->right //Continua percorrendo pela direita.
		} else {
			if(aux->left == NULL) break;
			else aux = aux->left;
		}
	}
	
	//Conecta o novo elemento ao pai.
	if(newMember->key > aux->key) aux->right = newMember;
	else aux->left = newMember;
}
int main() {
	root == NULL; //Inicializa a árvore vazia
}
