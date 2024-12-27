#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    
    int data;
    struct node * next;
} Node;

//funções de controle
Node* createNode(int valor);
void appendFim(Node **head, int data);
void appendIni(Node **head, int data);
void appendMid(Node **head, int data, int last);
void displayList(Node* head);
void freeList(Node** head);

//funções de ação(MERGE)
Node* merge(Node* array1, Node* array2);
void insertFim(Node** head, int n);
void insertIni(Node** head, int n);


int main()
{

	int tamanho1 = 0, tamanho2 = 0;
	scanf("%d %d", &tamanho1, &tamanho2);
	
	Node *list1 = NULL;
	Node *list2 = NULL;

	insertIni(&list1, tamanho1);
	insertFim(&list2, tamanho2);

	printf("lista 1: \n");
	displayList(list1);
	printf("\n");
	printf("lista 2: \n");
	displayList(list2);
	
	Node* listMerge = merge(list1, list2);

	printf("\nLista mesclada:\n");
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

//função que adicona valores no final da lista
void appendFim(Node **head, int data){
	
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

//funcao que adiciona um valor no inicio da fila
void appendIni(Node **head, int data){
	Node *newNode = createNode(data);

	if(newNode == NULL){
		return;
	}else{
		newNode->data = data;
		newNode->next = *head;
		*head = newNode;
	}	
}

//funcao que adiciona um valor no meio da fila
void appendMid(Node **head, int data, int last){
	Node *newNode = createNode(data);

	if(newNode == NULL){
		return;
	}else{
		if(*head == NULL){
			newNode->next = NULL;
			*head = newNode;
		}else{
			Node* temp = *head;

			while(temp->data != last && temp->next){
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
		}
	}
}

//mostrando a lista na tela
void displayList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d", temp->data);
        temp = temp->next;
        if(temp != NULL){
            printf(" -> ");
        }
    }
    printf("\n");
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

    while (array1 != NULL) {
        Node* newNode = createNode(array1->data);
        if (newArray == NULL) {
            newArray = newNode;
        } else {
            last->next = newNode;
        }
        last = newNode; 
        array1 = array1->next;
    }

    while (array2 != NULL) {
        Node* newNode = createNode(array2->data);
        if (newArray == NULL) {
            newArray = newNode;
        } else {
            last->next = newNode;
        }
        last = newNode;
        array2 = array2->next;
    }

    return newArray;
}

//Usuario inserir numeros no fim da fila
void insertFim(Node** head, int n)
{
	for(int i = 0; i < n; i++)
	{
		int value = 0;
		scanf("%d", &value);
		appendFim(head, value);
	}
}

//Usuario inserir numeros no inicio da fila
void insertIni(Node** head, int n)
{
	for(int i = 0; i < n; i++)
	{
		int value = 0;
		scanf("%d", &value);
		appendIni(head, value);
	}
}