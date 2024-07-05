#include <iostream>
using namespace std;
#include <cstring>
class BinaryTree {
    int data;
    BinaryTree* left, * right;
public:
    BinaryTree() {
        data = 0;
        left = right = NULL;
    }
    ~BinaryTree() {}
    BinaryTree(int n);
    BinaryTree* insert(BinaryTree*, int);
    bool nodeFinder(BinaryTree*, int) const;
    void inOrder(BinaryTree*) const;
    void preOrder(BinaryTree*) const;
};
BinaryTree::BinaryTree(int n) {
    data = n;
    left = NULL; right = NULL;
}
BinaryTree* BinaryTree::insert(BinaryTree* root, int value) {
    if (!root) {
        return new BinaryTree(value);
    }
    if (value > root->data) {
        root->right = insert(root->right, value);
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    }
    return root;
}
bool BinaryTree::nodeFinder(BinaryTree* tree, int key) const {
    if (!tree) return false;
    if (tree->data == key) return true;
    if (key < tree->data) return nodeFinder(tree->left, key);
    return nodeFinder(tree->right, key);
}
void BinaryTree::inOrder(BinaryTree* tree) const {
    if (!tree) return;
    inOrder(tree->left);
    cout << " " << tree->data;
    inOrder(tree->right);
}
void BinaryTree::preOrder(BinaryTree* tree) const {
    if (!tree) return;
    cout << " " << tree->data;
    preOrder(tree->left);
    preOrder(tree->right);
}
int main() {
    BinaryTree tree, * root = NULL;
    char op_name[13]; int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> op_name;
        if (strcmp(op_name, "print") == 0) {
            tree.inOrder(root);
            std::cout << "\n";
            tree.preOrder(root);
            std::cout << "\n";
        }
        else if (strcmp(op_name, "find") == 0) {
            int val;
            std::cin >> val;
            std::cout << (tree.nodeFinder(root,val) ? "yes" : "no") << endl;
        }
        else {
            int val;
            std::cin >> val;
            root = tree.insert(root, val);
        }
    }
    return 0;
}
