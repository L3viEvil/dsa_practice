#include <iostream>
#include <vector>

using namespace std;

class Node{
    public:
        int val;
        Node *left;
        Node *right;

        Node() {
            val = 0;
            left = nullptr;
            right = nullptr;
        }
        Node(int v) {
            val = v;
            left = nullptr;
            right = nullptr;
        }
        Node(int v, Node *left, Node *right) {
            val = v;
            this->left = left;
            this->right = right;
        }
};

void preOrder(Node *root) {
    if (root != nullptr) {
        cout << root->val << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

void postOrder(Node *root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}


int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    // Node *root1 = root;
    // Node *root2 = root;
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;

    return 0;
}