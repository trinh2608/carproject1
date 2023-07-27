#ifndef BST_H_
#define BST_H_
#include <iostream>
#include <vector>
#include "Node.h"
#include "Car.h"
#include <list>
#include <fstream>
#include <exception>
class BST { // tree 
private:
	Node* root; // gốc
	void insert(Car data, Node* aNode); // hàm insert
	Node* search(string data, Node* aNode);// hàm search nodebykey
	void searchNodeByName(string data, Node* aNode); // hàm search node by name
	void leftNodeRight(Node* aNode, int choice); // sắp xếp lnr
	void searchNodeByKey(string data, Node* aNode);
	void addElementToSave(Node* aNode); // add để save file
public:
	BST();
	int index = 0; // index đếm car dùng cho hiển thị ở hàm main
	void insert(Car data); // hàm insert 
	void searchNodeByName(string data); // hàm search node by name
	void searchNodeByKey(string data);
	Node* search(string data); // hàm search nodebykey
	void leftNodeRight(int choice); // sắp xếp lnr
	void addElementToSave();

	
};
#endif // BST_H_
