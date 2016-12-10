#include <iostream>
#include <iomanip>
#include <cstring>
#include "bst.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	BST::YOUR_NAME[]{"Paul Hubbard"};

// change the value of this variable to true if you're doing the Premium version
const bool	BST::PREMIUM_VERSION{false};

BST::BST(int capacity) :
items{new Item[capacity]},
count{0},
capacity{capacity}
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

	if(this->items[0].gcs.getName() == nullptr){
		this->items[0].gcs = gcs;
		count++;
		return;
	}
	
	for(int i = 0; i < this->capacity; i++){
		if(this->items[i].gcs.getName() != nullptr){
			int nameCmp = strcmp(this->items[i].gcs.getName(), gcs.getName());
		

			if(nameCmp > 0 && hasLeftChild(i) == false){
				this->items[getLeftChild(i)].gcs = gcs;
				count++;
				return;
			}
			else if(nameCmp < 0 && hasRightChild(i) == false){
				this->items[getRightChild(i)].gcs = gcs;
				count++;
				return;
			}
		}
	}
	
	return;
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
	
	for(int i = 0; i < capacity; i++){
		if(items[i].gcs.getName() != nullptr){
			if(hasChildren(i)){
				out << items[i].gcs.getName() << setw(32 - strlen(items[i].gcs.getName()))
				    << i << endl;
			}
			else{
				out << items[i].gcs.getName() << setw(28 - strlen(items[i].gcs.getName()))
					<< "leaf"				  << setw(4)
					<< i					  
					<< right << endl;
			}
		}
	}

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
