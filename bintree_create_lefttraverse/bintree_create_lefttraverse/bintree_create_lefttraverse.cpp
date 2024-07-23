#include <fstream>
#include <string>

struct Node {
    Node* left;
    Node* right;
    int key;
};


Node* insert(Node* node, int value) {
    
    if (node == NULL) {
        Node* newnode = new Node;
        newnode->key = value;
        newnode->left = newnode->right = NULL;
        return newnode;
    }
    if (value == node->key) {
        return node;
    }
    if (value < node->key)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);

    return node;
}

void leftorderTraverse(Node* r, std::ofstream& out) {
    if (r == NULL)
        return;
    out << r->key << std::endl;
    leftorderTraverse(r->left, out);
    leftorderTraverse(r->right, out);
}

Node* deletion(Node* root, int value) {

    if (root == nullptr) {
        return root;
    }
    if (value < root->key)
        root->left = deletion(root->left, value);
    else if (value > root->key)
        root->right = deletion(root->right, value);
    else {
        if (root->left == NULL && root->right == NULL) {
            delete root; 
            root = nullptr;
        }
        else if (root->left == NULL) {
            Node* temp = root->right;
            delete root; 
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* minNode = root->right;
            while (minNode->left != NULL) {
                minNode = minNode->left;
            }
            root->key = minNode->key;
            root->right = deletion(root->right, minNode->key);
        }
    }
    return root;
}

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("input.txt");
    fout.open("output.txt");


    int del;
    fin >> del;
    std::string emptyLine;
    std::getline(fin, emptyLine); 
    Node* root = NULL;
    int n;
    while (!fin.eof()) {
        fin >> n;
        root = insert(root, n);
    }
    root = deletion(root, del);
    leftorderTraverse(root, fout);
}
