#include <iomanip>
#include <string.h>
#include <iostream>
#include "stock.h"

using namespace std;

Stock::Stock(char const * const symbol, char const * const name, int sharePrice, Date priceDate) :
	symbol{strcpy(new char[strlen(symbol) + 1], symbol)},
	name{strcpy(new char[strlen(name) + 1], name)},
	sharePrice{sharePrice},
	priceDate{priceDate}
{
}

Stock::Stock(void)  :
symbol{new char['\0']},
name{new char['\0']},
sharePrice{0},
priceDate{Date()}
{
}

Stock::~Stock(void)
{
	delete [] name;
	name = nullptr;
	delete [] symbol;
	symbol = nullptr;
}

char const * const Stock::getSymbol(void) const
{
	return symbol;	// change this to return the actual stock symbol
}


//you can choose to implement any of the next 3 items if necessary --
//if not, feel free not to implement them

/*Stock::Stock(const Stock& s)
{

}
*/
Stock& Stock::operator=(const Stock& s)
{
	char * tempSym = new char[strlen(s.symbol) + 1];
	delete [] symbol;
	symbol = tempSym;
	strcpy(symbol, s.symbol);
	char * tempNm = new char[strlen(s.name) + 1];
	delete [] name;
	name = tempNm;
	strcpy(name, s.name);
	priceDate = s.priceDate;
	sharePrice = s.sharePrice;
	return *this;
}

/*Stock& Stock::operator=(Stock const * const s)
{

}
*/

// display column headers for printout of stocks
void Stock::displayHeaders(ostream& out)
{
	// print something like this:
	//
	//  symbol  name                                      price   date
	//  ------  ----                                      -----   ----
	out << left << setw(8) << "symbol" 
				<< setw(42) << "name" 
				<< setw(8) << "price"
				<< "date" << endl
				<< setw(8) << "------" 
				<< setw(42) << "----" 
				<< setw(8) << "-----"
				<< "----" << endl;

}

// print share price as DOLLARS
// (e.g. 2483 would print out as 24.83 and 200 would print out as 2.00)
ostream& operator<<(ostream& out, const Stock& s)
{ 
	out << left << setw(8)  << s.symbol 
				<< setw(42) << s.name 
				<< right <<  setw(2) << s.sharePrice / 100  << "." << right << setw(1);
				
					if(s.sharePrice % 100 < 10){
						out << "0" << s.sharePrice % 100;
					}
					else{
						out << s.sharePrice % 100;
					}

				out << left << s.priceDate;
		return out;
}












