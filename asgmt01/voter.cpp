#include <iostream>
#include <string.h>
#include <iomanip>
#include "voter.h"

using namespace std;

Voter::Voter(const char * const newName, const Party party, const int intensity) :
party{party},
intensity{intensity}
{
	// your code here, or in this constructor's initialization list
	name = {new char[strlen(newName) + 1]};
	strcpy(name, newName);
}
Voter::~Voter()
{
	// your code here
	delete [] name;
	name = nullptr;
}

void Voter::displayColumnHeadings(ostream& out)
{
	// your code here
	out << left << setw(26) << "name"
				<< setw(17) << "party"
				<< setw(9)  << "intensity"
				<< endl;
	out << left << setw(26) << "----"
				<< setw(17) << "-----"
				<< setw(9)  << "---------"
				<< endl;


}

ostream& operator<<(ostream& out, Voter* voter)
{
	// your code here
	out << left << setw(26) << 	voter->name
				<< setw(17) << 	voter->party
	    << right<< setw(9)  << 	voter->intensity
				<< endl;

	return out;
}

ostream& operator<<(std::ostream& out, Party party){
	switch(party){
		case Party::Republican:   out << "Republican"; break;
		case Party::Democrat:     out << "Democrat";   break;
		case Party::Libertarian:  out << "Libertarian";break;
		case Party::Green:		  out << "Green";      break;        
	}
	return out;
}
