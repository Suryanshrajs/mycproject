#ifndef BST_H
#define BST_H

#include <stdbool.h>
#include <stddef.h>

// Define the structure for a TreeNode
typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// Define the structure for the Binary Search Tree (BST)
typedef struct {
    TreeNode *root;
} BST;

// Function declarations
void bst_init(BST *tree);
TreeNode* bst_insert(BST *tree, int value);
TreeNode* bst_find(BST *tree, int value);
bool bst_delete(BST *tree, int value);
void bst_inorder_traversal(TreeNode *node, void (*visit)(int));
void bst_preorder_traversal(TreeNode *node, void (*visit)(int));
void bst_postorder_traversal(TreeNode *node, void (*visit)(int));
void bst_free(BST *tree);

#endif
