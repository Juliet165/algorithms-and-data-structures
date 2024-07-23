#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

struct Node {
    Node* left;
    Node* right;
    int key;
    int height;
    int children;
};

void PostOrderTraversal(Node *r) {
    if (r == NULL)
        return;
    PostOrderTraversal(r->left);
    PostOrderTraversal(r->right);
    if (r->left == NULL && r->right == NULL) {
        r->height = 0;
        r->children = 1;
    }
    else if (r->left == NULL) {
        r->height = (r->right)->height + 1;
        r->children = 1 + (r->right)->children;
    }
    else if (r->right == NULL) {
        
        r->height = (r->left)->height + 1;
        r->children = 1 + (r->left)->children ;
    }
    else {
        r->height = std::max((r->left)->height, (r->right)->height) + 1;
        r->children = 1 + (r->left)->children + (r->right)->children;
    }
    
}


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

std::vector<Node*> find(Node* root, int h, int current) {
    std::vector<Node*> result;
    if (root == nullptr) {
        return result;
    }
    if (current == h) {
        result.push_back(root);
    }
    else {
        std::vector<Node*> leftResult = find(root->left, h, current + 1);
        std::vector<Node*> rightResult = find(root->right, h, current + 1);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.insert(result.end(), rightResult.begin(), rightResult.end());
    }

    return result;
}
bool comp(Node* first, Node* second)
{
    return first->key < second->key;
}

int main()
{
    std::ifstream fin;
    std::ofstream fout;
    fin.open("in.txt");
    fout.open("out.txt");

    Node* root = NULL;
    int n;
    while (!fin.eof()) {
        fin >> n;
        root = insert(root, n);
    }
    PostOrderTraversal(root);
    int h = root->height;
    int hei = h/2; 
    h = h - hei;

    std::vector<Node*> nodes = find(root, h, 0);
    
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes[i]->left == nullptr && nodes[i]->right == nullptr) {
            nodes.erase(nodes.begin() + i); i--;
        }
        else if (nodes[i]->left == nullptr && nodes[i]->right != nullptr) {
            nodes.erase(nodes.begin() + i); i--;
        }
        else if (nodes[i]->left != nullptr && nodes[i]->right != nullptr) {
            if ((nodes[i]->left)->children <= (nodes[i]->right)->children) {
                nodes.erase(nodes.begin() + i); i--;
            }
        }
    }
    
    std::sort(nodes.begin(), nodes.end(), comp);
   
    if (nodes.size() != NULL) {
        if (nodes.size() % 2 == 1) {
            Node* del = nodes[nodes.size() / 2];
            root = deletion(root, del->key);
        }
    }
    leftorderTraverse(root, fout);
}
