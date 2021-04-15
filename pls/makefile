all: bst

bst: main.o BinarySearchTree.o BinaryNode.o 
	g++ main.o BinarySearchTree.o BinaryNode.o -o hw2

main.o: main.cpp
	g++ -c main.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	g++ -c BinarySearchTree.cpp

BinaryNode.o: BinaryNode.cpp
	g++ -c BinaryNode.cpp

clean: 
	rm -rf *o hw2