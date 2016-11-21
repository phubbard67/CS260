#include "date.h"

using namespace std;

Date::Date(Month month, int day, int year) :
month{month},
day{day},
year{year}
{
}

Date::Date() :
month{INVALID},
day{0},
year{0}
{
}

Date::~Date(void)
{
}

ostream& operator<<(ostream& out, const Date& d)
{
	switch(d.month){
		case Date::Month::INVALID:		out << "Invalid "  << d.day << "," << d.year  	 ; break;
		case Date::Month::JANUARY:		out << "January "  << d.day << "," << d.year 	 ; break;
		case Date::Month::FEBRUARY:		out << "February " << d.day << "," << d.year 	 ; break;
		case Date::Month::MARCH:		out << "March "	   << d.day << "," << d.year 	 ; break;
		case Date::Month::APRIL:		out << "April "	   << d.day << "," << d.year 	 ; break;
		case Date::Month::MAY:			out << "May "	   << d.day << "," << d.year 	 ; break;
		case Date::Month::JUNE:			out << "June "	   << d.day << "," << d.year 	 ; break;
		case Date::Month::JULY:			out << "July "	   << d.day << "," << d.year 	 ; break;
		case Date::Month::AUGUST:		out << "August "   << d.day << "," << d.year	 ; break;
		case Date::Month::SEPTEMBER: 	out << "September "<< d.day << "," << d.year     ; break;
		case Date::Month::OCTOBER:		out << "October "  << d.day << "," << d.year	 ; break;
		case Date::Month::NOVEMBER:		out << "November " << d.day << "," << d.year	 ; break;
		case Date::Month::DECEMBER:		out << "December " << d.day << "," << d.year     ; break;
	}
	return out; }
