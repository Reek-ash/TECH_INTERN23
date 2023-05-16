#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the maximum width of the BST
int maxWidth(Node* root) {
    if (root == NULL)
        return 0;

    int maxWidth = 0;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int count = q.size();
        maxWidth = max(maxWidth, count);

        while (count--) {
            Node* temp = q.front();
            q.pop();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }

    return maxWidth;
}

int main() {
    // Create the binary search tree
    Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);

    // Calculate and display the maximum width of the tree
    cout << "Maximum width of the tree is: " << maxWidth(root) << endl;

    return 0;
}
