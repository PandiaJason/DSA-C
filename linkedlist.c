#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;
Node* head = NULL;
void insert(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL){
        head = newNode;
    }
    else{
        Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(){
    Node* current = head;
    while(current!= NULL){
    printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL\n");
}


void main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    display();
}
