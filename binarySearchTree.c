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

void preorder(Node* node) {
    if (node) {
        printf("%d->", node->k);
        preorder(node->l);
        preorder(node->r);
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

int height(Node* node) {
    if (!node) return -1;
    int lh = height(node->l);
    int rh = height(node->r);
    return (lh > rh ? lh : rh) + 1;
}
Node* findMin(Node* node) {
    while (node && node->l) node = node->l;
    return node;
}
Node* findMax(Node* node) {
    while (node && node->r) node = node->r;
    return node;
}
Node* search(Node* node, int k) {
    if (!node || node->k == k) return node;
    if (k < node->k) return search(node->l, k);
    return search(node->r, k);
}

Node* deleteNode(Node* node, int key) {
    if (!node) return node;

    if (key < node->k) {
        node->l = deleteNode(node->l, key);
    }
    else if (key > node->k) {
        node->r = deleteNode(node->r, key);
    }
    else {
        // Node found
        // Case 1: No child
        if (!node->l && !node->r) {
            free(node);
            return NULL;
        }
        // Case 2: One child
        else if (!node->l) {
            Node* temp = node->r;
            free(node);
            return temp;
        }
        else if (!node->r) {
            Node* temp = node->l;
            free(node);
            return temp;
        }
        // Case 3: Two children
        Node* temp = findMin(node->r);
        node->k = temp->k;
        node->r = deleteNode(node->r, temp->k);
    }
    return node;
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
