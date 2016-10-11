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
	Node * nodeByInten{headByIntensity};
	Node * nodeByName{headByName};
	Node * prevByName{nullptr};
	Node * prevByInten{nullptr};

		if(headByName == nullptr){
		 	headByName = node;
		 	headByIntensity = node;
		}

		else {
			while(nodeByName){
				
				int nameComp = strcmp(node->item.getName(), nodeByName->item.getName());
				
				if(nameComp < 0){
					if(prevByName == nullptr){
						node->nextByName = headByName;
						headByName = node;
						break;
					}	
				
					else{
						node->nextByName = prevByName->nextByName;
						prevByName->nextByName = node;
						break;
					}
				}				
				
					prevByName = nodeByName;
					nodeByName = nodeByName->nextByName;
				
			}
			while(nodeByInten){
					if(node->item.getIntensity() > nodeByInten->item.getIntensity()){
						if(prevByInten == nullptr){
							node->nextByIntensity = headByIntensity;
							headByIntensity = node;
							break;
						}
						else{
							node->nextByIntensity = prevByInten->nextByIntensity;
							prevByInten->nextByIntensity = node;
							break;
						}
					}
					prevByInten = nodeByInten;
					nodeByInten = nodeByInten->nextByIntensity;
			}
			/*if(nodeByInten == nullptr){
				prevByInten->nextByIntensity = node;
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
