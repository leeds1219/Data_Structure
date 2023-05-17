#include <stdio.h>
#include <stdlib.h>

#define SIZE 12

typedef struct TreeNode {
  int data;
  struct TreeNode* left;
  struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

TreeNode* createTreeFromMatrix(int matrix[SIZE][SIZE], int rootIndex) {
  TreeNode* root = createNode(rootIndex);
  int i;
  for (i = 0; i < SIZE; i++) {
    if (matrix[rootIndex][i] == 1) {
      if (root->left == NULL) {
        root->left = createTreeFromMatrix(matrix, i);
      } else {
        root->right = createTreeFromMatrix(matrix, i);
      }
    }
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
  int adjacencyMatrix[SIZE][SIZE] = {
      {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  };

  TreeNode* root = createTreeFromMatrix(adjacencyMatrix, 0);
  printf("Inorder traversal of the tree: ");
  printInorder(root);

  return 0;
}
