#include "BinarySearchTree.h"


/*
* Title: Binary Search Trees
* Author: Name Surname
* ID: 21703284
* Section: 2
* Assignment: 2
* Description: Implementation of the binary search tree
*/


BinarySearchTree::BinarySearchTree(){
    root = NULL;
}

BinarySearchTree::BinarySearchTree(int item){ 
    root->item = item;
}


bool BinarySearchTree::add(const int newEntry)
{
   return addHelper(root, newEntry);
   

}


bool BinarySearchTree::addHelper(BinaryNode *node, int newEntry){
    BinaryNode *temp = new BinaryNode(newEntry, NULL, NULL);
	BinaryNode *cur = root;
	if (cur == NULL)
	{
		root = temp;
		root->count++;
		temp = NULL;
		cur = NULL;
		return true;
	}
	else
	{
		while (cur != NULL)
		{
			if (newEntry == cur->item)
			{
				cur->count++;
				delete temp;
				temp = NULL;
				cur = NULL;
				return false;
			}
			else if (newEntry<cur->item)
			{
				if (cur->leftChildPtr == NULL)
				{
					cur->leftChildPtr = temp;
					cur->leftChildPtr->count++;
					temp = NULL;
					cur = NULL;
					return true;
				}
				else
				{
					cur = cur->leftChildPtr;
				}
			}
			else if (newEntry>cur->item)
			{
				if (cur->rightChildPtr == NULL)
				{
					cur->rightChildPtr = temp;
					cur->rightChildPtr->count++;
					temp = NULL;
					cur = NULL;
					return true;
				}
				else
				{
					cur = cur->rightChildPtr;
				}
			}
		}
	}
    return false;
}

void BinarySearchTree::inorderTraverse() 
{ 
    inorderHelper(root); 
}
 
// A utility function to 
// do inorder traversal of BST
void BinarySearchTree::inorderHelper(BinaryNode *node)
{
    if (node != NULL)
    {
        inorderHelper(node->leftChildPtr);
        cout<<(node->item);
        inorderHelper(node->rightChildPtr);
    }
}



void BinarySearchTree::preorderTraverse() 
{ 
    preorderHelper(root); 
}
 
// A utility function to 
// do inorder traversal of BST
void BinarySearchTree::preorderHelper(BinaryNode *node)
{
    if (node != NULL)
    {

        cout<<(node->item)<< " ";
        preorderHelper(node->leftChildPtr);
        preorderHelper(node->rightChildPtr);
    }
}


void BinarySearchTree::postorderTraverse() 
{ 
    postorderHelper(root); 
}
 
// A utility function to 
// do inorder traversal of BST
void BinarySearchTree::postorderHelper(BinaryNode *node)
{
    if (node != NULL)
    {
        preorderHelper(node->leftChildPtr);
        preorderHelper(node->rightChildPtr);
        cout<<(node->item)<< " ";
    }
}




BinarySearchTree::~BinarySearchTree() //calls destructor helper function and passes in root
{
	destroyTree(root);
}

void BinarySearchTree::destroyTree(BinaryNode *&treePtr) //deallocates the heap space
{

	if (treePtr != NULL)
	{
		destroyTree(treePtr->leftChildPtr);
		destroyTree(treePtr->rightChildPtr);
		delete treePtr;
		treePtr = NULL;
	}
}

bool BinarySearchTree::isEmpty(){ 
    if (root) {
        return false;
    }
    return true;
}


bool BinarySearchTree::remove(int anEntry){
    removeHelper(anEntry,root);
}

bool BinarySearchTree::removeHelper(int &keyItem, BinaryNode *node){
    if (node == NULL) {
        // item not found
        return false;
    } else {
        if (node->item == keyItem) {
            // delete node
            deleteNode(node);
        } else if (keyItem < node->item){
            // search left
            removeHelper(keyItem, node->leftChildPtr);
        } else {
            // search right
            removeHelper(keyItem, node->rightChildPtr);
        }
    }
}

void BinarySearchTree::deleteNode(BinaryNode *&node){
  
    if ((node->leftChildPtr == NULL) && (node->rightChildPtr == NULL)) {
        delete node;
        node = NULL;
    } else if(node->leftChildPtr == NULL){
     
        node->item = node->rightChildPtr->item;
   
        delete node->rightChildPtr;
        node->rightChildPtr = NULL;
    } else if(node->rightChildPtr == NULL){
   
        node->item = node->leftChildPtr->item;
       
        delete node->leftChildPtr;
        node->leftChildPtr = NULL;
    }  else {

        int keyItem = -1;
        processLeftMost(keyItem, node->rightChildPtr);
        node->item = keyItem; // write back the value obtained
    }
}


void BinarySearchTree::processLeftMost(int &keyItem, BinaryNode *&node){
    if(!(node->leftChildPtr)){
        // found the in order successor
        keyItem =  node->item;
        // delete the node
        delete node;
        node = NULL; // safe-check
    } else {
        // recurse left
        processLeftMost(keyItem, node->leftChildPtr);
    }
}


int BinarySearchTree::getHeight()
{
    return getHeightHelper(root);
}


int BinarySearchTree::getHeightHelper(BinaryNode* node){
    if (node == NULL) {
        return 0;
    }
    else {
        return 1 + max(getHeightHelper(node->leftChildPtr), getHeightHelper(node->rightChildPtr));
    }
}

BinaryNode* BinarySearchTree::getRoot()
{
    return root;
}


bool BinarySearchTree::contains(const int anEntry){ 
    return containsHelper(anEntry, root);
}

bool BinarySearchTree::containsHelper(const int anEntry, BinaryNode * node){ 
    
    if(node == NULL)
    {
        return false;
    }
    else if(node->item == anEntry)
    {
        return true;
    }
    else if(node-> item > anEntry)
    {
        containsHelper( anEntry, node->rightChildPtr);
    }
    else if(node-> item < anEntry)
    {
        containsHelper( anEntry, node->leftChildPtr);
    }

}



int BinarySearchTree::getNumberOfNodes()  //passes the counter and root into helper function
{
	int counter = 0;
	numberOfNodesHelper(root, counter);
	return counter;
}

void BinarySearchTree::numberOfNodesHelper(BinaryNode *subTreePtr, int &counter) //finds out the total n-grams in the tree
{
	if (subTreePtr != NULL)
	{
		counter++;
		numberOfNodesHelper(subTreePtr->leftChildPtr, counter);
		numberOfNodesHelper(subTreePtr->rightChildPtr, counter);
	}
}


void BinarySearchTree::mirrorHelper(BinaryNode* rootPtr)
{
    if(rootPtr == NULL)
        return;
    else{
        BinaryNode* temp;
        mirrorHelper(rootPtr->leftChildPtr);
        mirrorHelper(rootPtr->rightChildPtr);
        temp = rootPtr->leftChildPtr;
        rootPtr->leftChildPtr = rootPtr->rightChildPtr;
        rootPtr->rightChildPtr = temp;
    }

}

void BinarySearchTree::mirror()
{
    mirrorHelper(root);
}

int BinarySearchTree::spanHelper(BinaryNode* rootPtr, const int a, const int b)
{
    int min = getMin(a, b);
    int max = getMax(a, b);
    if(rootPtr == NULL)
        return 0;
    if(a == b && rootPtr->item == a)
    {
        return 1;
    }
    if(rootPtr->item <= max && rootPtr->item >= min)
    {
        return 1 + spanHelper(rootPtr->leftChildPtr, a , b) + spanHelper(rootPtr->rightChildPtr, a , b);
    }
    else if(rootPtr->item < min)
    {
        return spanHelper(rootPtr->rightChildPtr, a, b);
    }
    else
        return spanHelper
        (rootPtr->leftChildPtr, a , b);
}

int BinarySearchTree::span(const int a, const int b)
{
    return spanHelper(root, a , b);
}

int BinarySearchTree::getMin(int a, int b)
{
    if(a<b)
        return a;
    else 
        return b;

}
int BinarySearchTree::getMax(int a, int b)
{
    if(a>b)
        return a;
    else 
        return b;
}

bool BinarySearchTree::printLevel(BinaryNode* rootPtr, int level)
{
    if(rootPtr == NULL)
        return false;
    if(level == 1)
    {
        cout << rootPtr->item <<endl;
        return true;
    }

    bool leftSub = printLevel(rootPtr->leftChildPtr, level - 1);
    bool rightSub = printLevel(rootPtr->rightChildPtr, level - 1);

    return leftSub || rightSub;

}

void BinarySearchTree::levelorderHelper(BinaryNode* rootPtr)
{
    int level = 1;
    while(printLevel(rootPtr, level))
        level++;
}

void BinarySearchTree::levelorderTraverse()
{
    levelorderHelper(root);
}
