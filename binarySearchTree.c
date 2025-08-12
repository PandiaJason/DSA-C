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
    node->l = node->r = NULL;
    if (r == NULL){
        r = node;
        return;
    }
    Node* c = r;
    Node* p = NULL;
    while(c != NULL){
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
        p->l=node;
    }
    else{
        p->r=node;
    }
}

void inorder(Node* node){
    if(node != NULL){
        inorder(node->l);
        printf("%d->", node->k);
        inorder(node->r);
    }
}

void levelorder(Node* node){
    Node* queue[1024];
    int f, b = 0;
    queue[b++] = node;
    while(f<b){
        Node* c = queue[f++];
        printf("%d->",c->k);
        if(c->l) queue[b++] = c->l;
        if(c->r) queue[b++] = c->r;
    }
}

void postorder(Node* node){
    if (!node) return;
    postorder(node->l);
    postorder(node->r);
    printf("%d->", node->k);
}

void main(){
    insert(50);
    insert(30);
    insert(70);
    insert(20);
    insert(40);
    insert(60);
    insert(80);
    inorder(r);
    printf("NULL\n");
    levelorder(r);
    printf("NULL\n");
    postorder(r);
    printf("NULL\n");
}
