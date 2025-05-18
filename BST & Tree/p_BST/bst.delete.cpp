#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) {
        key = k;
        left = right = NULL;
    }
};

// Utility function to insert nodes into the BST
Node* insert(Node* root, int key) {
    if (root == NULL) return new Node(key);
    if (key < root->key) root->left = insert(root->left, key);
    else if (key > root->key) root->right = insert(root->right, key);
    return root;
}

// Note that it is not a generic inorder
// successor function. It mainly works
// when the right child is not empty, which is
// the case we need in BST delete
Node* getSuccessor(Node* curr) {
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

// This function deletes a given key x from
// the given BST and returns the modified root of
// the BST (if it is modified)
Node* delNode(Node* root, int x) {
    if (root == NULL) return root;

    // If key to be searched is in a subtree
    if (root->key > x) root->left = delNode(root->left, x);
    else if (root->key < x) root->right = delNode(root->right, x);

    // If root matches with the given key
    else {
        // Cases when root has 0 children
        // or only right child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // When root has only left child
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // When both children are present
        Node* succ = getSuccessor(root);
        root->key = succ->key;
        root->right = delNode(root->right, succ->key);
    }
    return root;
}

// Utility function to do inorder traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver code
int main() {
    Node* root = NULL;
    int n, val, x;

    // Get number of nodes and their values from user
    cout << "Enter the number of elements to insert in the BST: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        root = insert(root, val);
    }

    // Get the value to delete
    cout << "Enter the value to delete from the BST: ";
    cin >> x;

    // Delete the node
    root = delNode(root, x);

    // Print the inorder traversal of the modified BST
    cout << "Inorder traversal of the modified BST:\n";
    inorder(root);

    return 0;
}

