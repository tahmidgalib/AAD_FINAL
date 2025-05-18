#include <iostream>

// Node structure
struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Insert a new key into the BST
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return new Node(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Search for a key in the BST
Node* search(Node* root, int key) {
    if (root == nullptr || root->key == key) {
        return root;
    }

    if (key < root->key) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Find the node with the minimum key in the BST
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Delete a key from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// In-order traversal of the BST
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        std::cout << root->key << " ";
        inOrder(root->right);
    }
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    std::cout << "In-order traversal: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Deleting 20\n";
    root = deleteNode(root, 20);
    std::cout << "In-order traversal: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Deleting 30\n";
    root = deleteNode(root, 30);
    std::cout << "In-order traversal: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Deleting 50\n";
    root = deleteNode(root, 50);
    std::cout << "In-order traversal: ";
    inOrder(root);
    std::cout << std::endl;

    Node* result = search(root, 60);
    if (result != nullptr) {
        std::cout << "Found 60 in the BST\n";
    } else {
        std::cout << "60 not found in the BST\n";
    }

    return 0;
}
