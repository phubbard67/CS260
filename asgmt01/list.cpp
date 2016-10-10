#include <cstring>
#include "list.h"

using namespace std;

const char	List::YOUR_NAME[] = "Paul Hubbard";

List::List() :
	headByName{nullptr},
	headByIntensity{nullptr}
{
	// your code here, or in this constructor's initialization list
}

List::~List() 
{
	// your code here
	Node * nodeName{headByName};
	Node * nextName;

	while(nodeName){
		nextName = nodeName->nextByName;
		delete nodeName;
		nodeName = nextName;
	}
	
}


//You will need to uncomment this constructor and write the code for it.

List::Node::Node(const Voter& voter) :
	// your initialization list here
	item{voter.getName(), voter.getParty(), voter.getIntensity()},
	nextByName{nullptr},
	nextByIntensity{nullptr}
{
	// your code here
}


void List::displayByName(ostream& out) const
{
	// your code here
	Node * node{headByName};

	Voter::displayColumnHeadings(out);

	while(node){
		out << &node->item << endl;
		node = node->nextByName;
	}
}

void List::displayByIntensity(ostream& out) const
{
	// your code here
}

void List::insert(const Voter& voter)
{
	// your code here
	Node * node = new Node(voter);
//	Node * nodeByInten{headByIntensity};
//	Node * nextName;
//	Node * nextByIntensity;

	if(headByName == nullptr){
		 headByName = node;
		 headByIntensity = node;
	}

		

}

Voter* const List::find(const char * const name) const
{
	// your code here, return the appropriate value

	return nullptr;
}

bool List::remove(const char * const name)
{
	// your code here, return the appropriate value
	
	return false;
}
