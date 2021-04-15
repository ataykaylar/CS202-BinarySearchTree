/*
* Title: Binary Search Trees
* Author: Atay KAYLAR
* ID: 21703284
* Section: 2
* Assignment: 2
* Description: Header file of the Binary search tree
*/
#include "BinaryNode.h"



class BinarySearchTree
{
public:
    BinarySearchTree();
    BinarySearchTree(int item);
    ~BinarySearchTree();
    bool isEmpty();
    int getHeight();
    int getNumberOfNodes();
    bool add(const int newEntry);
    bool remove(const int anEntry);
    bool contains(const int anEntry);
    void preorderTraverse();
    void inorderTraverse();
    void postorderTraverse();
    void levelorderTraverse();
    int span(const int a, const int b);
    void mirror();
    int getMin(int a, int b);   
    int getMax(int a, int b);
    bool printLevel(BinaryNode* rootPtr, int level);
    void levelorderHelper(BinaryNode* rootPtr);
    bool addHelper(BinaryNode *node, int newEntry);
    void inorderHelper(BinaryNode *node);
    void preorderHelper(BinaryNode *node);
    void postorderHelper(BinaryNode *node);
    void destroyTree(BinaryNode *&treePtr);
    bool removeHelper(int &keyItem, BinaryNode *node);
    void deleteNode(BinaryNode *&node);
    void processLeftMost(int &keyItem, BinaryNode *&node);
    int getHeightHelper(BinaryNode* node);
    bool containsHelper(const int anEntry, BinaryNode * node);
    BinaryNode* getRoot();
    void numberOfNodesHelper(BinaryNode *subTreePtr, int &counter);
    void mirrorHelper(BinaryNode* rootPtr);
    int spanHelper(BinaryNode* rootPtr, const int a, const int b);


private:
    BinaryNode *root;

};
