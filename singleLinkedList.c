#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
void insert(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    }else{
        struct Node* current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newNode;
    }
}

void display(){
    struct Node* current = head;
    while(current != NULL){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void rem(int data){
    struct Node* current = head;
    struct Node* prev = NULL;
    while(current != NULL){
        if(data == current->data){
            if(prev == NULL){
                head = current->next;
                return;
            } else{
                prev->next = current->next;
            }
        }
        prev = current;
        current = current->next;
    }
}


void main(){
    insert(10);
    insert(20);
    insert(30);
    display();
    rem(20);
    display();
}
