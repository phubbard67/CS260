// make NO CHANGES to this file

#ifndef _LIST_H_
#define _LIST_H_

#include <ostream>
#include "voter.h"

class List
{
public:
	static const char	YOUR_NAME[];	// used for printing out programmer's name

	List(void);				// constructor
	virtual ~List(void);	// destructor

	// Print out the voters in alphabetical order by name,
	// by calling Voters's operator<< for each voter.
	void displayByName(std::ostream& out) const;

	// Print out the voters from highest to lowest rating,
	// by calling Voter's operator<< for each voter.
	void displayByIntensity(std::ostream& out) const;

	// Insert a voter into both the names and intensities threads.
	// The names thread should be in alphabetical order by name.
	// The intensity thread should be in order from highest to
	// lowest value.
	void insert(const Voter& voter);

	// Return a const pointer to the voter instance it finds in
	// the list, or nullptr if it didn't find a voter with that name.
	// Because the pointer is declared const, there is no danger
	// that find's caller will be able to use the returned pointer
	// to change the instance of voter.
	Voter* const find(const char * const name) const;

	// Remove the voter with the specified name from both the name
	// thread and the intensity thread. Returns true if it found and
	// removed the voter, false if it did not find the voter.
	bool remove(const char * const name);

private:
	struct Node
	{
		Node(const Voter& voter);		// constructor
		Voter item;						// an instance of Voter
										// (NOT a pointer to an instance)
		Node *nextByName;				// next node in the name thread
		Node *nextByIntensity;			// next node in the intensity thread
	};

	Node *headByName;					// first node in the name thread
	Node *headByIntensity;				// first node in the intensity thread
};

#endif // _LIST_H_
