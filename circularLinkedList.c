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
    newNode->next = head;
        if(head == NULL){
        head = newNode;
        newNode->next = head;
    }else{
        struct Node* current = head;
        while(current->next != head){
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;
    }
}

void display(){
    struct Node* current = head;
    while(current->next != head){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("%d->",current->data);
    current = current->next;
    printf("%d\n",current->data);
}

void rem(int data){
    struct Node* current = head;
    struct Node* prev = NULL;
    while(current->next != head){
        if(data == current->data){
            if(prev == NULL){
            struct Node* last = head;
                while(last->next != head){
                    last = last->next;
                }
                    head = current->next;
                    last->next = head;
            } else{
                prev->next = current->next;
            }
        }
        prev = current;
        current = current->next;
    }
    if (current->data == data){
        prev->next = head;
    }
}


void main(){
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    display();
    rem(10);
    rem(30);
    display();
}
