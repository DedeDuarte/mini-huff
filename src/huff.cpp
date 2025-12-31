#include "huff.hpp"

using namespace std;

// |==========|
// |   Node   |
// |==========|
Node::Node() : c('\0'), left(nullptr), right(nullptr) {}
Node::Node(char c, Node* left, Node* right) : c(c), left(left), right(right) {}

char Node::getChar() { return this->isLetter() ? this->c : this->left->getChar(); }

Node* Node::getNext() {
    if (isLetter()) {
        cerr << "This node is the end of the tree... and is a letter" << endl;
        exit(-1);
    }

    return this->left;
}

char Node::getVal() { return this->c; }
Node* Node::getLeft() { return this->left; }
Node* Node::getRight() { return this->right; }

bool Node::isLetter() { return this->c != '\0'; }

Node::~Node() {
    delete left;
    delete right;
}



// |==========|
// | HuffTree |
// |==========|
void HuffTree::printTree_rec(Node* node, int depth) {
    if (!node) return;

    printTree_rec(node->getRight(), depth + 1);

    for (int i = 0; i < depth; ++i)
        cout << "  ";

    if (node->getLeft() == nullptr && node->getRight() == nullptr) {
        string s = string(1, node->getVal());

        if (s == " ")      s = "sp";
        else if (s == "\n") s = "\\n";
        else if (s == "\t") s = "\\t";

        cout << s << '\n';
    } else {
        cout << "@\n";
    }

    printTree_rec(node->getLeft(), depth + 1);
}

HuffTree::HuffTree() : root(nullptr), depth(0) {}

void HuffTree::newLetter(char c) {
    Node* newLetter = new Node(c, nullptr, nullptr);

    if (this->root == nullptr) {
        this->root = newLetter;
        return;
    }
    
    Node* newNode   = new Node('\0', newLetter, this->root);
    this->root = newNode;
    this->depth++;
}

void HuffTree::printTree() { printTree_rec(this->root, 0); }

HuffTree::~HuffTree() {
    delete root;
    root = nullptr;
    depth = 0;
}