#include <cstring>
#include "list.h"

using namespace std;

const char	List::YOUR_NAME[] = "Paul Hubbard";

List::List() 
{
	// your code here, or in this constructor's initialization list
	headByName = nullptr;
	headByIntensity = nullptr;
}

List::~List() 
{
	// your code here
	//Node * 
	
}

/*
You will need to uncomment this constructor and write the code for it.

List::Node::Node(const Voter& voter)
	// your initialization list here
{
	// your code here
}
*/

void List::displayByName(ostream& out) const
{
	// your code here
}

void List::displayByIntensity(ostream& out) const
{
	// your code here
}

void List::insert(const Voter& voter)
{
	// your code here
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
