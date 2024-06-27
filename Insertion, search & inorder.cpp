#include <iostream>
using namespace std;

// NAMA : ADJI SETYAWAN SAPUTRA
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

bool search(Node* root, int data) {
    if (root == nullptr) {
        return false;
    }

    if (root->data == data) {
        return true;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

    int initialValues[] = {50, 30, 20, 40, 70, 60, 80};
    for (int val : initialValues) {
        root = insert(root, val);
    }

    int choice, value;

    while (true) {
    	cout << "\n======== Program binary search tree ========\n\n";
    	cout << "Nilai Binary search tree :\n";
    	cout << "50, 30, 20, 40, 70, 60, 80\n";
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display Inorder\n";
        cout << "4. Exit\n";
        cout << "\nMasukkan pilihan mu: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value)) {
                    cout << value << " found in the BST.\n";
                } else {
                    cout << value << " not found in the BST.\n";
                }
                break;
            case 3:
                cout << "Inorder Traversal: ";
                inorderTraversal(root);
                cout << endl;
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }
    return 0;
}
