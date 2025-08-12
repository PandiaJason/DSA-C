  GNU nano 5.4                                                                                                                      bst.c                                                                                                                               
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int k;
    struct Node* l;
    struct Node* r;
}Node;
Node* r = NULL;
void insert(int k){
    Node* node = (Node*) malloc(sizeof(Node));
    node->k = k;
    node->r = node->l = NULL;
    if(r == NULL){
        r = node;
        return;
    }
    Node* c = r;
    Node* p  =NULL;
    while(c !=NULL){
        p = c;
        if(k < c->k){
            c = c->l;
        }
        else if(k > c->k){
            c = c->r;
        }
        else{
            free(node);
            return;
        }
    }
    if(k<p->k){
        p->l = node;
    }
    else{
        p->r = node;
    }
}

void inorder(Node* node){
if(node){
        inorder(node->l);
        printf("%d->", node->k);
        inorder(node->r);
    }
}

void levelorder(Node* node){
    Node* queue[1024];
    int f, b = 0;
    queue[b++] = r;
    while(f < b){
        Node* c = queue[f++];
        printf("%d->", c->k);
        if(c->l) queue[b++] = c->l;
        if(c->r) queue[b++] = c ->r;
    }
}


void main(){
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);
    levelorder(r);
    printf("\n");
}
