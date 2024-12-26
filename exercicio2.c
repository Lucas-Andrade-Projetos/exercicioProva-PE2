#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    
    int data;
    struct node * next;
} Node;

Node* createNode(int valor);

int main()
{
    
    return 0;
}

Node* createNode(int valor){

    Node *newNode = (Node*)malloc(sizeof(Node));

    if(newNode != NULL)
    {
        newNode->data = value;
        newNode->next = NULL;
    }

    return newNode;
}
