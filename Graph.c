#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct ListNode {
  int vertex;
  struct ListNode* next;
} ListNode;

typedef struct Graph {
  ListNode* adjList[MAX_VERTICES];
  int numVertices;
} Graph;

ListNode* createNode(int v) {
  ListNode* node = (ListNode*) malloc(sizeof(ListNode));
  node->vertex = v;
  node->next = NULL;
  return node;
}

void addEdge(Graph* g, int src, int dest) {
  ListNode* newNode = createNode(dest);
  newNode->next = g->adjList[src];
  g->adjList[src] = newNode;

  newNode = createNode(src);
  newNode->next = g->adjList[dest];
  g->adjList[dest] = newNode;
}

void printGraph(Graph* g) {
  int i;
  for (i = 0; i < g->numVertices; i++) {
    ListNode* node = g->adjList[i];
    printf("Adjacency list of vertex %d: ", i);
    while (node != NULL) {
      printf("%d ", node->vertex);
      node = node->next;
    }
    printf("\n");
  }
}

int main() {
  Graph g;
  g.numVertices = 5;

  int i;
  for (i = 0; i < g.numVertices; i++) {
    g.adjList[i] = NULL;
  }

  addEdge(&g, 0, 1);
  addEdge(&g, 0, 4);
  addEdge(&g, 1, 2);
  addEdge(&g, 1, 3);
  addEdge(&g, 1, 4);
  addEdge(&g, 2, 3);
  addEdge(&g, 3, 4);

  printGraph(&g);

  return 0;
}
