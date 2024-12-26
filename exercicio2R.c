#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int valor;
	struct node* next;
} node;


node* createNode(int valor);
void include(node** cabeca, int valor);
void printL(node* cabeca);
node* merge(node* array1, node* array);

int main(){

	int
	
	return 0;
}

node* createNode(int valor) {
	
	node* newNode = (node*) malloc(sizeof(node));
	if(newNode == NULL)
	{
		exit(1);
	}
	newNode->valor = valor;
	newNode->proximo = NULL;

	return newNode;
}

void include(node** cabeca, int valor){

	node* newNode = criarNo(valor);
	if(*cabeca == NULL){
		*cabeca = newNode;
	} else {
		node* temp = *cabeca;
		while(temp->proximo != NULL){
			temp = temp->proximo;
		}
		temp->proximo = newNode;
	} 
}

void printL(node* cabeca){
	node* temp = cabeca;
	while(temp != NULL){
		printf("");
		temp = temp->proximo;
	}
	printf("\n");
}

node* merge(node* array1, node* array){

	node* newArray = NULL;
	node* last  = NULL;

	while(array1 != NULL || array2 != NULL){
		node* newNode = createNode(0);
		if (array1 != NULL){
			newNode->valor += array1->valor;
			array1 = array1 -> proximo;
		}
		if (array2 != NULL){
			newNode->valor += array2->valor;
			array2 = array -> proximo;
		}

		if(newArray == NULL) {
			newArray = newNode;
		} else {
			last->next = newNode;
		}
		last = newNode;
	}
	
	return newArray;
}