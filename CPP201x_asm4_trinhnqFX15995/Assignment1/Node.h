#ifndef NODE_H_
#define NODE_H_
#include "Car.h"
#include <iostream>

class Node { // class node gồm nhánh trái, phải, giá trị là Car
public:
	Car data;
	Node* left;
	Node* right;
	Node(Car car) {
		data = car;
		left = NULL;
		right = NULL;
	}
};





#endif // NODE_H_*/

