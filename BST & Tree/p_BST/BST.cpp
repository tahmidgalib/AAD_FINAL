#include <iostream>
using namespace std;

class Node {
    public:
    int key;
    Node* left;
    Node* right;
    Node(int value) {
        key = value;
        left = right = NULL;
    }
};

void insert(Node*& root, int value) {
    if (root == NULL) {  
        root = new Node(value);
        return;
    } else if (value <= root->key) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

void inorder(Node* root) {
    Node* temp = root;
    if (temp == NULL) {
        return;
    }
    inorder(temp->left);
    cout << temp->key << " ";
    inorder(temp->right);
}

void search(Node* root, int value) {
    Node* temp = root;
    if (temp == NULL) {
        return;
    } else if (temp->key == value) {
        cout << "\nvalue is found\n";
        return;
    } else if (value < temp->key) {
        search(temp->left, value);
    } else {
        search(temp->right, value);
    }
}

Node* findMin(Node* root) {
    Node* temp = root;
    if (temp == NULL) {
        return NULL;
    }
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}

void Delete(Node*& root, int value) {
    if (root == NULL) {
        return;
    }
    if (value < root->key) {
        Delete(root->left, value);
    } else if (value > root->key) {
        Delete(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        } else {
            Node* min = findMin(root->right);
            root->key = min->key;
            Delete(root->right, min->key);
        }
    }
}

void successor(Node* root, int value) {
    Node* temp = root;
    int store = -1;  // Initialize store with a default value

    while (temp != NULL && temp->key != value) {
        if (temp->key > value) {
            
            temp = temp->left;
        } else {
            store = temp->key;
            temp = temp->right;

        }
    }


    if (temp->right != NULL) {
        Node* min = findMin(temp->right);
        cout << "Successor is " << min->key << " ";
    } else if (store != -1) {
        cout << "Successor is " << store << " ";
    } else {
        cout << "No successor found ";
    }
}

int main() {
    Node* root = NULL;
    insert(root, 10);
    insert(root, 5);
    insert(root, 20);
    insert(root, 3);
    insert(root, 6);
    insert(root, 18);
    insert(root, 25);
    
    cout << "Inorder traversal: ";
    inorder(root);
    
    search(root, 18);
    
    Node* min = findMin(root);
    cout << "\nmin is " << min->key << endl;
    
    Delete(root, 5);
    cout << "Inorder traversal after deleting 5: ";
    inorder(root);
    
    successor(root, 5);
    
    return 0;
}
