#ifndef _BST_H_
#define _BST_H_

// do not change this file except within the private section of the BST class,
// where you can declare variables and/or functions

#include "gcs.h"

class BST								// a Binary Search Tree (BST)
{
public:
	static const char	YOUR_NAME[];		// used for printing out programmer's name
	static const bool	PREMIUM_VERSION;	// used to designate Regular vs. Premium

	BST(int capacity = 5);				// constructor (default if no argument supplied)
	~BST();								// destructor

	void insert(const GCS& gcs);		// insert a new item into BST
	bool remove(const char* key);		// remove item associated with key from BST
	bool retrieve(const char* key, GCS const *& gcs) const;	// retrieve item associated with key, if any
	int getSize(void) const;			// return number of items contained in the BST

	// see comments in bst.cpp for what these member functions do
	void displayArrayOrder(std::ostream& out) const;
	void displayPreOrder(std::ostream& out) const;
	void displayInOrder(std::ostream& out) const;
	void displayPostOrder(std::ostream& out) const;

private:
	// specify what is stored at each position in the array
	// (you can add additional items to this struct)
	struct Item
	{
		GCS		gcs;		// the GCS instance must be specified this way, NOT as a pointer
	};

	// pointer to the array
	Item*	items;
///////////////////////////////////////////Added var and func
	
	int 	count;
	int		capacity;
	int		recursCount;

	//get the index of the children
	int getRightChild(int parent) const;
	int getLeftChild(int parent) const;

	//find if the parent has children
	bool hasLeftChild(int parent) const;
	bool hasRightChild(int parent) const;
	bool hasChildren(int parent) const;
	bool hasBothChildren(int parent) const;
	
	//grow array
	void growArray(int position);

	//recursive insert
	void recursInsert(int recursCount, const GCS& gcs);

	//recursive retrieve 
	void recursRetrieve(const char * key,  int recursCount, GCS const *& gcs) const;

	//print in order
	void printInOrder(int position) const;

	//print post order
	void printPostOrder(int position) const;
	
	//print pre order
	void printPreOrder(int position) const;

	//find inorder
	int inOrder(int position) const;

	//find the in order preorder 
	//for removing parents with 
	//left child only
	int preOrderInOrder(int position) const;

};

#endif
