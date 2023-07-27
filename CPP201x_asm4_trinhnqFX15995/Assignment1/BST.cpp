#include "BST.h"

extern list<Car> listCar3;
extern vector<Car> vectorCar;
BST::BST() {
	root = NULL;
}

void BST::insert(Car data, Node* aNode) {
	if (data.getPersonalKey() < aNode->data.getPersonalKey()) { // sang trái
		if (aNode->left != NULL) { 
			insert(data, aNode->left);
		}
		else {
			aNode->left = new Node(data);
			aNode->left->left = NULL;
			aNode->left->right = NULL;

		}
	}

	else if (data.getPersonalKey() >= aNode->data.getPersonalKey()) {
		if (aNode->right != NULL) {
			insert(data, aNode->right);
		}
		else {
			aNode->right = new Node(data);
			aNode->right->left = NULL;
			aNode->right->right = NULL;
		}
	}
}

void BST::insert(Car data) {
	if (root != NULL) {
		insert(data, root);
	}
	else {
		root = new Node(data);
		root->left = NULL;
		root->right = NULL;
	}
	++index;
}

Node* BST::search(string data, Node* aNode) {
	if (aNode != NULL) {
		if (data == aNode->data.getPersonalKey()) {
			return aNode;
		}
		if (data < aNode->data.getPersonalKey()) {
			return search(data, aNode->left);
		}
		else {
			return search(data, aNode->right);
		}
	}
	else {
		return NULL;
	}
}
void BST::searchNodeByName(string data, Node* aNode) {
	if (aNode != NULL) {
		searchNodeByName( data, aNode->left);
		if (aNode->data.getCarName() == data) {
			cout << setw(20) << aNode->data.getCarName()
				<< setw(25) << aNode->data.getEmail()
				<< setw(10) << aNode->data.getPersonalKey()
				<< setw(10) << aNode->data.getODO()
				<< setw(10) << aNode->data.getServiceRemind()
				<< setw(10) << aNode->data.getDisplay()->get_light_level()
				<< setw(10) << aNode->data.getDisplay()->get_taplo_light_level()
				<< setw(10) << aNode->data.getDisplay()->get_screen_light_level()
				<< setw(30) << aNode->data.getGeneral()->get_timeZone()
				<< setw(20) << aNode->data.getGeneral()->get_language()
				<< setw(10) << aNode->data.getSound()->get_media_level()
				<< setw(10) << aNode->data.getSound()->get_call_level()
				<< setw(10) << aNode->data.getSound()->get_navi_level()
				<< setw(10) << aNode->data.getSound()->get_notification_level()
				<< endl;
		}
		searchNodeByName(data, aNode->right);
	}
}
void BST::searchNodeByName(string data) {
	searchNodeByName(data, root);
}

void BST::searchNodeByKey(string data, Node* aNode) {
	if (aNode != NULL) {
		searchNodeByKey(data, aNode->left);
		if (aNode->data.getPersonalKey() == data) {
			cout << setw(20) << aNode->data.getCarName()
				<< setw(25) << aNode->data.getEmail()
				<< setw(10) << aNode->data.getPersonalKey()
				<< setw(10) << aNode->data.getODO()
				<< setw(10) << aNode->data.getServiceRemind()
				<< setw(10) << aNode->data.getDisplay()->get_light_level()
				<< setw(10) << aNode->data.getDisplay()->get_taplo_light_level()
				<< setw(10) << aNode->data.getDisplay()->get_screen_light_level()
				<< setw(30) << aNode->data.getGeneral()->get_timeZone()
				<< setw(20) << aNode->data.getGeneral()->get_language()
				<< setw(10) << aNode->data.getSound()->get_media_level()
				<< setw(10) << aNode->data.getSound()->get_call_level()
				<< setw(10) << aNode->data.getSound()->get_navi_level()
				<< setw(10) << aNode->data.getSound()->get_notification_level()
				<< endl;
		}
		searchNodeByKey(data, aNode->right);
	}
}
void BST::searchNodeByKey(string data) {
	searchNodeByKey(data, root);
}

Node* BST::search(string data) {
	return search(data, root);
}
void BST::leftNodeRight(int choice) {
	leftNodeRight(root,choice);
}
void BST::leftNodeRight(Node* aNode, int choice) {
	if (aNode != NULL) {
		if (choice == 2) { // print sound data
			leftNodeRight(aNode->left,2);
			cout << setw(20) << aNode->data.getCarName()
				<< setw(25) << aNode->data.getEmail()
				<< setw(10) << aNode->data.getPersonalKey()
				<< setw(10) << aNode->data.getODO()
				<< setw(10) << aNode->data.getServiceRemind()
				<< setw(10) << aNode->data.getSound()->get_media_level()
				<< setw(10) << aNode->data.getSound()->get_call_level()
				<< setw(10) << aNode->data.getSound()->get_navi_level()
				<< setw(10) << aNode->data.getSound()->get_notification_level()
				<< endl;
			leftNodeRight(aNode->right,2);
		}	
		else if (choice == 1) { // print display data
			leftNodeRight(aNode->left, 1);
			cout << setw(20) << aNode->data.getCarName()
				<< setw(25) << aNode->data.getEmail()
				<< setw(10) << aNode->data.getPersonalKey()
				<< setw(10) << aNode->data.getODO()
				<< setw(10) << aNode->data.getServiceRemind()
				<< setw(10) << aNode->data.getDisplay()->get_light_level()
				<< setw(10) << aNode->data.getDisplay()->get_taplo_light_level()
				<< setw(10) << aNode->data.getDisplay()->get_screen_light_level()
				<< endl;
			leftNodeRight(aNode->right, 1);
		}
		else { // print general data
			leftNodeRight(aNode->left, 3);
			cout << setw(20) << aNode->data.getCarName()
				<< setw(25) << aNode->data.getEmail()
				<< setw(10) << aNode->data.getPersonalKey()
				<< setw(10) << aNode->data.getODO()
				<< setw(10) << aNode->data.getServiceRemind()
				<< setw(10) << aNode->data.getGeneral()->get_timeZone()
				<< setw(10) << aNode->data.getGeneral()->get_language()
				<< endl;
			leftNodeRight(aNode->right, 3);
		}
	}
}

void BST::addElementToSave(Node* aNode) {
	if (aNode != NULL) {
		addElementToSave(aNode->left);
		listCar3.push_back(aNode->data);
		addElementToSave(aNode->right);
	}
}

void BST::addElementToSave() {
	addElementToSave(root);
}


/*cout << setw(20) << iter->getCarName()
<< setw(25) << iter->getEmail()
<< setw(10) << iter->getPersonalKey()
<< setw(10) << iter->getODO()
<< setw(10) << iter->getServiceRemind()
<< setw(10) << iter->getSound()->get_media_level()
<< setw(10) << iter->getSound()->get_call_level()
<< setw(10) << iter->getSound()->get_navi_level()
<< setw(10) << iter->getSound()->get_notification_level()
<< endl;*/


