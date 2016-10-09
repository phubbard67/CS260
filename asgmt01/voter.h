// make NO CHANGES to this file

#ifndef _VOTER_H_
#define _VOTER_H_

#include <ostream>

enum class Party {Republican, Democrat, Libertarian, Green};

std::ostream& operator<<(std::ostream& out, Party party);

class Voter
{
public:
	Voter(const char * const name, const Party party, const int intensity);
	virtual ~Voter(void);

	// nothing needed in the .cpp file for these functions - complete implementation is provided
	const char * const	getName() const			{ return name; };
	Party				getParty() const		{ return party; }
	int					getIntensity() const	{ return intensity; };

	// print column headings for lists of voters
	static void displayColumnHeadings(std::ostream& out);

	// print a voter
	friend std::ostream& operator<<(std::ostream& out, Voter* voter);

private:
	char*	name;
	Party	party;
	int		intensity;
};

#endif // _VOTER_H_
