#include "bst.h"
#include <stdlib.h>

// Initialize the binary search tree
void bst_init(BST *tree) {
    tree->root = NULL;
}

// Helper function to create a new tree node
TreeNode* create_node(int value) {
    TreeNode *new_node = (TreeNode*)malloc(sizeof(TreeNode));
    if (new_node) {
        new_node->data = value;
        new_node->left = NULL;
        new_node->right = NULL;
    }
    return new_node;
}

// Insert a value into the binary search tree
TreeNode* bst_insert(BST *tree, int value) {
    TreeNode *new_node = create_node(value);
    if (!new_node) {
        return NULL; // Handle memory allocation failure
    }

    if (tree->root == NULL) {
        tree->root = new_node;
        return new_node;
    }

    TreeNode *current = tree->root;
    TreeNode *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            free(new_node); // Duplicate value, not inserting
            return current;
        }
    }

    if (value < parent->data) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    return new_node;
}

// Find a value in the binary search tree
TreeNode* bst_find(BST *tree, int value) {
    TreeNode *current = tree->root;

    while (current != NULL) {
        if (value < current->data) {
            current = current->left;
        } else if (value > current->data) {
            current = current->right;
        } else {
            return current;
        }
    }

    return NULL; // Value not found
}

// Helper function to find the minimum value node in a subtree
TreeNode* find_min(TreeNode *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Delete a value from the binary search tree
bool bst_delete(BST *tree, int value) {
    TreeNode *current = tree->root;
    TreeNode *parent = NULL;
    bool is_left_child = false;

    // Find the node to delete and its parent
    while (current != NULL && current->data != value) {
        parent = current;
        if (value < current->data) {
            is_left_child = true;
            current = current->left;
        } else {
            is_left_child = false;
            current = current->right;
        }
    }

    if (current == NULL) {
        return false; // Value not found
    }

    // Case 1: Node to be deleted has no children
    if (current->left == NULL && current->right == NULL) {
        if (current == tree->root) {
            tree->root = NULL;
        } else if (is_left_child) {
            parent->left = NULL;
        } else {
            parent->right = NULL;
        }
        free(current);
    }

    // Case 2: Node to be deleted has one child
    else if (current->left == NULL) {
        if (current == tree->root) {
            tree->root = current->right;
        } else if (is_left_child) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }
        free(current);
    } else if (current->right == NULL) {
        if (current == tree->root) {
            tree->root = current->left;
        } else if (is_left_child) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }
        free(current);
    }

    // Case 3: Node to be deleted has two children
    else {
        TreeNode *successor = find_min(current->right);
        int successor_value = successor->data;
        bst_delete(tree, successor->data); // Recursively delete successor
        current->data = successor_value;
    }

    return true;
}

// In-order traversal of the binary search tree
void bst_inorder_traversal(TreeNode *node, void (*visit)(int)) {
    if (node != NULL) {
        bst_inorder_traversal(node->left, visit);
        visit(node->data);
        bst_inorder_traversal(node->right, visit);
    }
}

// Pre-order traversal of the binary search tree
void bst_preorder_traversal(TreeNode *node, void (*visit)(int)) {
    if (node != NULL) {
        visit(node->data);
        bst_preorder_traversal(node->left, visit);
        bst_preorder_traversal(node->right, visit);
    }
}

// Post-order traversal of the binary search tree
void bst_postorder_traversal(TreeNode *node, void (*visit)(int)) {
    if (node != NULL) {
        bst_postorder_traversal(node->left, visit);
        bst_postorder_traversal(node->right, visit);
        visit(node->data);
    }
}

// Free the binary search tree
void bst_free(BST *tree) {
    while (tree->root != NULL) {
        bst_delete(tree, tree->root->data);
    }
}
