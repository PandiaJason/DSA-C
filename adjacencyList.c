#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int v;
    struct Node* next;
}Node;

Node* adj[100];
int n = 0;

Node* newNode(int v){
    Node* node = (Node*) malloc(sizeof(Node));
    node->v = v;
    node->next = NULL;
    return node;
}

void addVertex(int v) {
    adj[v] = NULL;
    if (v >= n) n = v + 1;
}

void addEdge(int src, int dest){
    Node* node = newNode(dest);
    node->next = adj[src];
    adj[src] = node;
    node = newNode(src);
    node->next = adj[dest];
    adj[dest] = node;
}

void printGraph() {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = adj[i];
        while (temp) {
            printf(" %d", temp->v);
            temp = temp->next;
        }
        printf("\n");
    }
}
void main() {
    addVertex(0);
    addVertex(1);
    addVertex(2);
    addVertex(3);
    addVertex(4);

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    printf("Adjacency List:\n");
    printGraph();
}

