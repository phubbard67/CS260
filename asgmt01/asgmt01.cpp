// make NO CHANGES to this file

#include <cstring>
#include <iostream>
#include "voter.h"
#include "list.h"

using namespace std;

static List		*voters;

// Asks List to insert a voter into the doubly-threaded linked list.
// Note what this function does with memory, which has implications for
// how you will (and will not) be able to use the voter instance that's
// passed to voters->insert.
static void insertVoter(char *name, Party party, int intensity)
{
	Voter	*v;
	char	*nm{new char[strlen(name) + 1]};
	
	strcpy(nm, name);
	v = new Voter(nm, party, intensity);
	voters->insert(*v);
	delete[] nm;
	delete v;
}

// Display all voters in the list,
// first in order by name, then in order by rating.
static void displayVoters(ostream& out)
{
	out << "+++ list by name" << endl;
	voters->displayByName(out);
	out << endl << "+++ list by intensity" << endl;
	voters->displayByIntensity(out);
}

int main(int argc, char **argv)
{
	Voter	*vPtr;

    cout << "CS260 - Assignment 1 - " << List::YOUR_NAME << endl << endl;

    voters = new List();

	insertVoter("John Q. Public",	Party::Republican,		 91);
	insertVoter("Jane Q. Public",	Party::Democrat,		 43);
	insertVoter("Joe Q. Public",	Party::Libertarian,		  0);
	insertVoter("Joan Q. Public",	Party::Libertarian,		100);
	insertVoter("Jim Q. Public",	Party::Green,			 80);

	displayVoters(cout);

	cout << endl << ">>> removing Jim Q. Public" << endl <<  endl;
	voters->remove("John Q. Public");                  //change back to Jim

	displayVoters(cout);

	cout << endl << ">>> inserting Jed Q. Public" << endl << endl;
	insertVoter("Jed Q. Public", Party::Libertarian, 90);

	displayVoters(cout);

	cout << endl << ">>> search for \"Jed Q. Public\"" << endl << endl;
	vPtr = voters->find("John Q. Public");            //change back to Jed -------------------------------
	if (vPtr != 0)
		cout << vPtr;
	else
		cout << "not found" << endl;

	cout << endl << ">>> search for \"Didn't Register\"" << endl << endl;
	vPtr = voters->find("No Such");
	if (vPtr != 0)
		cout << vPtr;
	else
		cout << "not found" << endl;

	cout << endl;

	delete voters;

	return 0;
}
