#include <iostream>
#include <iomanip>
#include "bst.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	BST::YOUR_NAME[]{"Paul Hubbard"};

// change the value of this variable to true if you're doing the Premium version
const bool	BST::PREMIUM_VERSION{false};

BST::BST(int capacity) :
items{new Item[capacity]},
count{0}
{
}

BST::~BST()
{
	delete [] items;
	items = nullptr;
}

// insert a new item into the BST
void BST::insert(const GCS& gcs)
{
}

// retrieve item associated with key
// returns true if it finds key, false if it can't
bool BST::retrieve(const char* key, GCS const *& gcs) const
{
	return false;
}

// remove item associated with key from BST
bool BST::remove(const char* key)
{
	return false;
}

// return number of items contained in the BST
int BST::getSize(void) const
{
	return count;
}

// display items in the tree by traversing the array from beginning to end
void BST::displayArrayOrder(ostream& out) const
{
	out << "name" 	<< setw(25)
		<< "leaf?"	<< setw(7)
		<< "index"  << endl;
	out << "----"	<< setw(25)
		<< "-----"	<< setw(7)
		<< "-----"	<< endl;
}

// display items in the tree in preorder
void BST::displayPreOrder(ostream& out) const
{
	out << "name" 	<< setw(25)
		<< "leaf?"	<< setw(7)
		<< "index"  << endl;
	out << "----"	<< setw(25)
		<< "-----"	<< setw(7)
		<< "-----"	<< endl;
}

// display items in the tree in inorder
void BST::displayInOrder(ostream& out) const
{
	out << "name" 	<< setw(25)
		<< "leaf?"	<< setw(7)
		<< "index"  << endl;
	out << "----"	<< setw(25)
		<< "-----"	<< setw(7)
		<< "-----"	<< endl;
}

// display items in the tree in postorder
void BST::displayPostOrder(ostream& out) const
{
	out << "name" 	<< setw(25)
		<< "leaf?"	<< setw(7)
		<< "index"  << endl;
	out << "----"	<< setw(25)
		<< "-----"	<< setw(7)
		<< "-----"	<< endl;
}
/////////////////////////////////////////added functions
int BST::getLeftChild(int parent){
	return (2 * parent + 1);
}

int BST::getRightChild(int parent){
	return (2 * parent + 2);
}

bool BST::hasLeftChild(int parent){
	
	if(this->items[getLeftChild(parent)].gcs.getName()){
		return true;
	}
	else{
		return false;
	}
}

bool BST::hasRightChild(int parent){
	if(this->items[getRightChild(parent)].gcs.getName()){
		return true;
	}else{
		return false;
	}
}

bool BST::hasChildren(int parent){
	
	if((this->items[getLeftChild(parent)].gcs.getName()) && (this->items[getRightChild(parent)].gcs.getName())){
		return true;
	}
	else{
		return false;
	}
}
