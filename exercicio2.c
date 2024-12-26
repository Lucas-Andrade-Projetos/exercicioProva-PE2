#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    
    int data;
    struct node * next;
} Node;

//funções de controle
Node* createNode(int valor);
void displayList(Node* head);
void append(Node **head, int data);
void freeList(Node** head);

//funções de ação(MERGE)
Node* merge(Node* array1, Node* array2);

int main()
{
    Node *list1 = NULL;
	Node *list2 = NULL;

	//adicionando valores na lista
	append(&list1, 10);
	append(&list1, 20);
	append(&list1, 30);
	append(&list1, 40);
	append(&list1, 50);

	//adicionando valores na lista 2
	append(&list2, 60);
	append(&list2, 70);
	append(&list2, 80);
	append(&list2, 90);
	append(&list2, 100);
	
	printf("lista 1: \n");
	displayList(list1);
	printf("\n");
	printf("lista 2: \n");
	displayList(list2);
	
	Node* listMerge = merge(list1, list2);

	printf("lista 3: \n");
	displayList(listMerge);

	freeList(&list1);
	freeList(&list2);
	freeList(&listMerge);

    return 0;
}

//Criação do nó
Node* createNode(int valor){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode != NULL)
    {
        newNode->data = valor;
        newNode->next = NULL;
    }

    return newNode;
}

//mostrando a lista na tela
void displayList(Node* head){

	Node* temp = head;

	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp ->next;
	}
}

//função que adicona valores na lista
void append(Node **head, int data){
	
	Node *newNode = createNode(data);

	if(newNode == NULL){
		return;
	}

	if(*head == NULL){
		*head = newNode;
	}else
	{
		Node* temp = *head;

		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}

}

//Liberando dados 
void freeList(Node** head){
	
	Node* temp;

	while(*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

//essa função recebe duas listas encadeadas e junta as duas
Node* merge(Node* array1, Node* array2){

	Node* newArray = NULL;
	Node* last = NULL;

	while(array1 != NULL || array2 != NULL){
		Node* newNode = createNode(0);
		if(array1 != NULL)
		{
			newNode->data += array1->data;
			array1 = array1->next;
		}
		if(array2 != NULL){
			newNode->data += array2->data;
			array2 = array2->next;
		}

		if(newArray == NULL){
			newArray = newNode;
		}else{
			last->next = newNode;
		}
		last = newNode;
	}

	return newArray;
}