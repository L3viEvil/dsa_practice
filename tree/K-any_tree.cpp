#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Node{
    public:
        int val;
        vector<Node*> children;

        Node() {
            val = 0;
        }

        Node(int val) {
            this->val = val;
        }

        Node(int val, vector<Node*> children) {
            this->val = val;
            this->children = children;
        }
};

void preOrder(Node* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    int nums = root->children.size();
    for (int i = 0 ; i < nums; i++) {
        preOrder(root->children[i]);
    }
}

void inOrder(Node* root) {
    if (root == nullptr) return;
    int nums = root->children.size();
    for (int i = 0; i < nums-1; i++) {
        inOrder(root->children[i]);
    }
    cout << root->val << " ";
    if (nums > 1) {
        inOrder(root->children[nums-1]);
    }
}

void postOrder(Node* root) {
    if (root == nullptr) return;
    int nums = root->children.size();
    for (int i = 0 ; i < nums; i++) {
        postOrder(root->children[i]);
    }
    cout << root->val << " ";
}

void levelOrder(Node *root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* top = q.front();
        cout << top->val << " ";
        int n = top->children.size();
        for (int i = 0; i < n; i++) q.push(top->children[i]);
        q.pop();
    }
}

void DeepFirst(Node *root) {
    if (root == nullptr) return;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        Node *top = s.top();
        s.pop();
        cout << top->val << " ";
        int n = top->children.size();
        for (int i = n-1 ; i >= 0; i--) s.push(top->children[i]);
    }
}


int main() {
    Node *root = new Node(1);
    vector<Node*> c1;
    for (int i = 2; i < 5; i++) c1.push_back(new Node(i));
    root->children = c1;
    vector<Node*> c2;
    for (int i = 5; i < 7; i++) c2.push_back(new Node(i));
    root->children[0]->children = c2;
    vector<Node*> c3;
    for (int i = 8; i < 10; i++) c3.push_back(new Node(i));
    root->children[1]->children = c3;
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    levelOrder(root);
    cout << endl;
    DeepFirst(root);
    cout << endl;

    return 0;
}
