// add code to these functions to make Quack do something useful

#include "quack.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	Quack::YOUR_NAME[]{"Paul Hubbard"};

// change the value of this variable to true if you're doing the Premium version
const bool	Quack::PREMIUM_VERSION{false};

Quack::Quack(int capacity, int growBy) :
	// replace these initializations with the ones you actually need
	items{new char[capacity + growBy]},
	capacity{capacity + growBy},
	frontIndex{items[0]},
	backIndex{items[capacity]}
{
	initArray();	// you are required to call this function here, and
					// it must be the first thing in the constructor body
}

Quack::~Quack(void)
{
	delete[] items;
}

// items are pushed to successively LOWER slots in the circular array
// (except for when the beginning of the array "wraps around" to the end)
bool Quack::pushFront(const char ch)
{	
	if(frontIndex == 0){
		items[0] = ch;
		backIndex = frontIndex;
		frontIndex = capacity - 1;
		return true;
	}
	else{
		items[frontIndex] = ch;
		frontIndex = frontIndex - 1;
		return true;
	}

	return false;
}

// items are pushed to successively HIGHER slots in the circular array
// (except for when the end of the array "wraps around" to the beginning)
bool Quack::pushBack(const char ch)
{
	if(items[backIndex]){
		items[backIndex + 1] = ch;
		backIndex = backIndex + 1;
		return true;
	}
	return false;
}

bool Quack::popFront(char& ch)
{
	return false;
}

bool Quack::popBack(char& ch)
{
	return false;
}

void Quack::rotate(int r)
{
}

void Quack::reverse(void)
{
}

int	Quack::itemCount(void)
{
	return 0;
}

ostream& operator<<(ostream& out, Quack *q)
{
	int index = q->frontIndex;
	out << "quack: ";
		while(index != q->backIndex){
			out << q->items[index];
			if(index == (q->capacity - 1)){
				index = 0;
			}	
			else{
				index = index + 1;
			}
		}
		out << q->items[index];
	
	out << endl << endl;
	// returning out is ALWAYS required for an operator<< overload
	return out;
}
