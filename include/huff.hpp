#ifndef HUFF_H
#define HUFF_H

#include <iostream>
#include <string>

class Node {
private:
    char c;
    Node* left;
    Node* right;

public:
    Node();
    Node(char c, Node* left, Node* right);

    char getChar();

    Node* getNext();

    char getVal();
    Node* getLeft();
    Node* getRight();

    bool isLetter();

    ~Node();
};

class HuffTree {
private:
    Node* root;
    int depth;

    void printTree_rec(Node* node, int depth);

public:
    HuffTree();

    void newLetter(char c);

    void printTree();

    ~HuffTree();
};



#endif