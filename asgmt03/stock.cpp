#include <iomanip>
#include <string.h>
#include <iostream>
#include "stock.h"

using namespace std;

Stock::Stock(char const * const symbol, char const * const name, int sharePrice, Date priceDate) :
	symbol{strcpy(new char[strlen(symbol) + 1], symbol)},
	name{strcpy(new char[strlen(symbol) + 1], name)},
	sharePrice{sharePrice},
	priceDate{priceDate}
{
}

Stock::Stock(void)  :
symbol{'\0'},
name{'\0'},
sharePrice{0},
priceDate{Date()}
{
}

Stock::~Stock(void)
{
	symbol = nullptr;
	name = nullptr;
	delete symbol;
	delete name;
}

char const * const Stock::getSymbol(void) const
{
	return symbol;	// change this to return the actual stock symbol
}

/*
you can choose to implement any of the next 3 items if necessary --
if not, feel free not to implement them

Stock::Stock(const Stock& s)
{
}
*/
Stock& Stock::operator=(const Stock& s)
{
	return *this;
}
/*
Stock& Stock::operator=(Stock const * const s)
{
	return (symbol = &s->symbol && name = &s->name && sharePrice = &s->sharePrice && priceDate = &s->priceDate);
}
*/

// display column headers for printout of stocks
void Stock::displayHeaders(ostream& out)
{
	// print something like this:
	//
	//  symbol  name                                      price   date
	//  ------  ----                                      -----   ----
	out << left << setw(8) << "symbol" << setw(42) << "name" << setw(8) << "price"
		<< "date" << endl
		<< setw(8) << "------" << setw(42) << "----" << setw(8) << "-----"
		<< "----" << endl;
}

// print share price as DOLLARS
// (e.g. 2483 would print out as 24.83 and 200 would print out as 2.00)
ostream& operator<<(ostream& out, const Stock& s)
{ 
	
	out << left << setw(8) << s.symbol << setw(42) << s.name 
		<< setw(8) << s.sharePrice << s.priceDate << endl;
	return out;
}












