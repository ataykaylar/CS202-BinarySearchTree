#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree tree;
    tree.add(10);
    tree.add(6);
    tree.add(7);
    tree.add(8);

    tree.preorderTraverse();
    tree.mirror();
    tree.preorderTraverse();

    return 0;
}