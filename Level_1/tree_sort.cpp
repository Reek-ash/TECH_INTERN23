#include <iostream>

// Binary Search Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        std::cout << "Memory error!\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node into BST
Node* insertNode(Node* root, int data) {
    // If the tree is empty, assign a new node address to the root
    if (root == nullptr) {
        root = createNode(data);
        return root;
    }

    // Else, do recursive insertion in the left subtree or right subtree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // Return the unchanged root pointer
    return root;
}

// Function to do inorder traversal of BST (to retrieve sorted sequence)
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

// Function to perform tree sort
void treeSort(int arr[], int n) {
    Node* root = nullptr;

    // Construct the BST
    root = insertNode(root, arr[0]);
    for (int i = 1; i < n; i++) {
        insertNode(root, arr[i]);
    }

    // Perform inorder traversal to get the sorted sequence
    inorder(root);
}

int main() {
    int arr[] = {4, 2, 6, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\nSorted array: ";
    treeSort(arr, n);

    return 0;
}
