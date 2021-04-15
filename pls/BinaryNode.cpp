#include "BinaryNode.h"


/*
* Title: Binary Search Trees
* Author: Name Surname
* ID: 21703284
* Section: 2
* Assignment: 2
* Description: Header file of the Binary node
*/



BinaryNode::BinaryNode()
{
    item = 0;
    leftChildPtr = NULL;
    rightChildPtr = NULL;
    count = 0;
 }

BinaryNode::BinaryNode(const int &nodeItem, BinaryNode *left, BinaryNode *right )
{
    item = nodeItem;
    leftChildPtr = left;
    rightChildPtr = right;
    count = 0;
}

int BinaryNode::getItem()
{
    return item;
}

void BinaryNode::setItem(int newItem)
{ item = newItem;}

