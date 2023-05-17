#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
  int data;
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode;

typedef struct ListNode {
  int vertex;
  struct ListNode* next;
} ListNode;

TreeNode* createNode(int data) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

ListNode* createListNode(int vertex) {
  ListNode* node = (ListNode*)malloc(sizeof(ListNode));
  node->vertex = vertex;
  node->next = NULL;
  return node;
}

void addEdge(ListNode* adjList[], int src, int dest) {
  ListNode* newNode = createListNode(dest);
  newNode->next = adjList[src];
  adjList[src] = newNode;
}

TreeNode* createTreeFromList(ListNode* adjList[], int index, int parent) {
  if (index == -1)
    return NULL;

  TreeNode* root = createNode(index);

  ListNode* current = adjList[index];
  while (current != NULL) {
    if (current->vertex != parent) {
      if (root->left == NULL) {
        root->left = createTreeFromList(adjList, current->vertex, index);
      } else {
        root->right = createTreeFromList(adjList, current->vertex, index);
      }
    }
    current = current->next;
  }

  return root;
}

void printInorder(TreeNode* node) {
  if (node == NULL)
    return;

  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}

int main() {
  int numVertices = 12;

  ListNode* adjList[numVertices];
  for (int i = 0; i < numVertices; i++)
    adjList[i] = NULL;

  // Add edges to the adjacency list
  addEdge(adjList, 0, 1);
  addEdge(adjList, 0, 4);
  addEdge(adjList, 1, 2);
  addEdge(adjList, 1, 3);
  addEdge(adjList, 4, 5);
  addEdge(adjList, 4, 6);
  addEdge(adjList, 5, 8);
  addEdge(adjList, 5, 9);
  addEdge(adjList, 6, 10);
  addEdge(adjList, 6, 11);
  addEdge(adjList, 2, 7);

  TreeNode* root = createTreeFromList(adjList, 0, -1);
  printf("Inorder traversal of the tree: ");
  printInorder(root);

  return 0;
}
