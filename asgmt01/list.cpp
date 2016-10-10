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
	Node * node{headByIntensity};

	Voter::displayColumnHeadings(out);

	while(node){
		out << &node->item << endl;
		node = node->nextByName;
	}
}

void List::insert(const Voter& voter)
{
	// your code here
	Node * node = new Node(voter);
	//Node * nodeByInten{headByIntensity};
	Node * nodeByName{headByName};
	//Node * prevByName = nullptr;
	//Node * prevByInten = nullptr;

	if(headByName == nullptr){
		 headByName = node;
		 headByIntensity = node;
		 return;
	}
		while(nodeByName){
			int nameComp = strcmp(nodeByName->item.getName(), node->item.getName());
				if(nameComp == 0){
					return;
				}
				if(nameComp > 0){
					node->nextByName = nodeByName->nextByName;
					nodeByName->nextByName = node;
				}
				/*else if(nameComp > 0){
					prevByName->nextByName = node;
					node->nextByName = nodeByName;
				}*/
				//prevByName = nodeByName;
				nodeByName = nodeByName->nextByName;
			/*while(nodeByInten){
					if(nodeByInten->item.getIntensity() <= node->item.getIntensity()){
						node->nextByIntensity = nodeByInten->nextByIntensity;
						nodeByInten->nextByIntensity = node;
						return;
					}
					//prevByInten = nodeByInten;
					nodeByInten = nodeByInten->nextByIntensity;
			}*/
		}
	return;
		

}

Voter* const List::find(const char * const name) const
{
	// your code here, return the appropriate value
	
	Node * node{headByName};
	//Voter * voterName{nullptr};
	while(node){
		if(strcmp(node->item.getName(), name) == 0){
		
			return &node->item;
		}
		node = node->nextByName;
	}

	return nullptr;
}

bool List::remove(const char * const name)
{
	// your code here, return the appropriate value
	Node * node{headByName};
	Node * prevPtr = nullptr;

	while(node){
		if(strcmp(node->item.getName(), name) == 0){
			if(prevPtr == nullptr){
				node = headByName;
				headByName = node->nextByName;
				headByIntensity = node->nextByIntensity;
				delete node;
				return true;
			}
			else{
				node = prevPtr->nextByName;
				prevPtr->nextByName = node->nextByName;
				prevPtr->nextByIntensity = node->nextByIntensity;
				delete node;
				return true;
			}
		}
		prevPtr = node;
		node = node->nextByName;
	}	
	return false;
}
