#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* findMin(Node* root) {
    while (root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (!root) return root;

    if (val < root->data) {
        root->left = deleteNode(root->left, val);
    } else if (val > root->data) {
        root->right = deleteNode(root->right, val);
    } else {
        
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void preOrder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    int values[] = { 50, 30, 20, 40, 70, 60, 80 };

    for (int val : values) {
        root = insert(root, val);
    }
    cout << "======== Program binary search tree ========\n\n";
    cout << "Pre-order traversal : ";
    preOrder(root);
    cout << endl;

    cout << "\nPost-order traversal : ";
    postOrder(root);
    cout << endl;

    int deleteVal = 50;
    root = deleteNode(root, deleteVal);
    cout << "\n========> Misal ingin menghapus nilai 50 <======== \n";
    cout << "\nPre-order traversal setelah deletion : \n";
    preOrder(root);
    cout << endl;

    cout << "\nPost-order traversal setelah deletion : \n";
    postOrder(root);
    cout << endl;

    return 0;
}
