#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int key;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert a node into the BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key); // If the tree is empty, create a new node
    }

    if (key < root->key) {
        root->left = insert(root->left, key); // Insert into the left subtree
    } else {
        root->right = insert(root->right, key); // Insert into the right subtree
    }

    return root;
}

// Search for a node in the BST
Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key)
        return root; // Return the node if found or null if not found

    if (key < root->key)
        return search(root->left, key); // Search in the left subtree

    return search(root->right, key); // Search in the right subtree
}

// Find the minimum node in the BST
Node* findMinimum(Node* root) {
    while (root->left != nullptr) // Keep moving to the leftmost node
        root = root->left;
    return root;
}

// Find the maximum node in the BST
Node* findMaximum(Node* root) {
    while (root->right != nullptr) // Keep moving to the rightmost node
        root = root->right;
    return root;
}

// In-order traversal of the BST
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " "; // Print the node in sorted order
        inOrder(root->right);
    }
}

// Delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key); // Find the node in the left subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key); // Find the node in the right subtree
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the in-order successor
        Node* temp = findMinimum(root->right);

        root->key = temp->key; // Copy the successor's key to this node

        root->right = deleteNode(root->right, temp->key); // Delete the successor
    }
    return root;
}

int main() {
    Node* root = nullptr;

    // Insert elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Print in-order traversal (sorted order)
    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    // Delete a node and print the tree again
    cout << "Deleting 20...\n";
    root = deleteNode(root, 20);
    cout << "In-order traversal after deletion: ";
    inOrder(root);
    cout << endl;

    return 0;
}

