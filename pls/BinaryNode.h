/*
* Title: Binary Search Trees
* Author: Atay KAYLAR
* ID: 21703284
* Section: 2
* Assignment: 2
* Description: Header file of the Binary node
*/


#include <iostream>
using namespace std;

class BinaryNode
{ // node in the tree

public:
    BinaryNode();
    BinaryNode(const int &nodeItem, BinaryNode *left = NULL, BinaryNode *right = NULL);
    void setItem(int newItem);
    int getItem();
    int item; // data portion
    int count;
    BinaryNode *leftChildPtr;  // pointer to left child
    BinaryNode *rightChildPtr; // pointer to right child


};