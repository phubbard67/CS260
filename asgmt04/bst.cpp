#include <iostream>
#include <iomanip>
#include <cstring>
#include "bst.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	BST::YOUR_NAME[]{"Paul Hubbard"};

// change the value of this variable to true if you're doing the Premium version
const bool	BST::PREMIUM_VERSION{true};

BST::BST(int capacity) :
items{new Item[capacity]},
count{0},
capacity{capacity},
recursCount{0}
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


recursInsert(recursCount, gcs);

	return;
}	


// retrieve item associated with key
// returns true if it finds key, false if it can't
bool BST::retrieve(const char* key, GCS const *& gcs) const
{

	recursRetrieve(key, recursCount, gcs);

	if(strcmp(gcs->getName(), key) == 0){
		return true;
	}
	else{
		return false;
	}
}

// remove item associated with key from BST
bool BST::remove(const char* key)
{
	int temp = 0;
	
	while(items[temp].gcs.getName() != nullptr && strcmp(items[temp].gcs.getName(), key) != 0) {
		if(strcmp(items[temp].gcs.getName(), key) > 0){
			temp = getLeftChild(temp);
		} 
		else{
			temp = getRightChild(temp);
		}
	}
	
	if(items[temp].gcs.getName() != nullptr){
		if(hasLeftChild(temp) == false && hasRightChild(temp) == false){
			items[temp].gcs.setName(nullptr);
			count--;
			return true;
		}
	}
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
	
	for(int i = 0; i < capacity; i++){
		if(items[i].gcs.getName() != nullptr){
			if(hasChildren(i)){
				out << items[i].gcs.getName() << setw(36 - strlen(items[i].gcs.getName()))
				    << i << endl;
			}
			else{
				out << items[i].gcs.getName() << setw(28 - strlen(items[i].gcs.getName()))
					<< "leaf"				  << setw(8)
					<< i					  
					<< right << endl;
			}
		}
	}

	out << "(items printed)" << setw(23) << "(" << count << ")" << endl;

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

	printPreOrder(recursCount);

	out << "(items printed)" << setw(23) << "(" << count << ")" << endl;
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

	printInOrder(recursCount);

	out << "(items printed)" << setw(23) << "(" << count << ")" << endl;
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

	printPostOrder(recursCount);
	
	out << "(items printed)" << setw(23) << "(" << count << ")" << endl;
}
/////////////////////////////////////////added functions
int BST::getLeftChild(int parent) const{
	return (2 * parent + 1);
}

int BST::getRightChild(int parent) const{
	return (2 * parent + 2);
}

bool BST::hasLeftChild(int parent) const{

	if(getLeftChild(parent) > capacity){
		return false;
	}
	if(this->items[getLeftChild(parent)].gcs.getName() != nullptr){
		return true;
	}
	else{
		return false;
	}
}

bool BST::hasRightChild(int parent) const{
	if(getRightChild(parent) > capacity){
		return false;
	}
	if(this->items[getRightChild(parent)].gcs.getName() == nullptr){
		return false;
	}else{
		return true;
	}
}

bool BST::hasChildren(int parent) const{
	
	if(hasRightChild(parent) || hasLeftChild(parent)){
		return true;
	}
	else{
		return false;
	}
}

void BST::growArray(int position){

	if(getLeftChild(position) > capacity || getRightChild(position) > capacity){
		Item * newItems;
		newItems = new Item[capacity * 2];


		for(int i = 0; i < capacity; i++){
			if(items[i].gcs.getName() != nullptr){
				newItems[i].gcs = items[i].gcs;
			}
		}

		delete [] items;
		capacity = capacity * 2;
		items = newItems;
		newItems = nullptr;
	}

}

void BST::recursInsert(int recursCount, const GCS& gcs){
	
	growArray(recursCount);

	if(items[recursCount].gcs.getName() == nullptr){
		items[recursCount].gcs = gcs;
		count++;
	}
	else if(strcmp(items[recursCount].gcs.getName(), gcs.getName()) > 0){
		recursInsert(getLeftChild(recursCount), gcs);
	}
	else{
		recursInsert(getRightChild(recursCount), gcs);
	}
}

void BST::recursRetrieve(const char * key, int recursCount, GCS const *& gcs) const{

	if(this->items[recursCount].gcs.getName() == nullptr){
		gcs = &items[0].gcs;
	}

	if(this->items[recursCount].gcs.getName() != nullptr && strcmp(items[recursCount].gcs.getName(), key) == 0){
		gcs = &items[recursCount].gcs;
	}
	else if(this->items[recursCount].gcs.getName() != nullptr && strcmp(items[recursCount].gcs.getName(), key) > 0){
		if(recursCount < capacity){
			recursRetrieve(key, getLeftChild(recursCount), gcs);
		}
	}
	else{
		if(recursCount < capacity && this->items[recursCount].gcs.getName() != nullptr){
			recursRetrieve(key, getRightChild(recursCount), gcs);
		}
	}
	
}

void BST::printInOrder(int position) const{
	if(hasLeftChild(position)){
		printInOrder(getLeftChild(position));
	}
		if(hasChildren(position)){
				cout << items[position].gcs.getName() << setw(36 - strlen(items[position].gcs.getName()))
				     << position << endl;
			}
			else{
				cout << items[position].gcs.getName() << setw(28 - strlen(items[position].gcs.getName()))
					<< "leaf"				  << setw(8)
					<< position					  
					<< right << endl;
			}

	if(hasRightChild(position)){
		printInOrder(getRightChild(position));
	}
}

void BST::printPreOrder(int position) const{

	if(hasChildren(position)){
			cout << items[position].gcs.getName() << setw(36 - strlen(items[position].gcs.getName()))
			     << position << endl;
		}
	else{
		cout << items[position].gcs.getName() << setw(28 - strlen(items[position].gcs.getName()))
			<< "leaf"				  << setw(8)
			<< position					  
			<< right << endl;
	}

	if(hasLeftChild(position)){
		printPreOrder(getLeftChild(position));
	}
	if(hasRightChild(position)){
		printPreOrder(getRightChild(position));
	}

}

void BST::printPostOrder(int position) const{

	if(hasLeftChild(position)){
		printPostOrder(getLeftChild(position));
	}
	if(hasRightChild(position)){
		printPostOrder(getRightChild(position));
	}

	if(hasChildren(position)){
			cout << items[position].gcs.getName() << setw(36 - strlen(items[position].gcs.getName()))
			     << position << endl;
		}
	else{
		cout << items[position].gcs.getName() << setw(28 - strlen(items[position].gcs.getName()))
			<< "leaf"				  << setw(8)
			<< position					  
			<< right << endl;
	}

}
