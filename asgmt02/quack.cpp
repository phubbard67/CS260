// add code to these functions to make Quack do something useful

#include "quack.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	Quack::YOUR_NAME[]{"Paul Hubbard"};

// change the value of this variable to true if you're doing the Premium version
const bool	Quack::PREMIUM_VERSION{false};

Quack::Quack(int capacity, int growBy) :
	// replace these initializations with the ones you actually need
	items{new char[capacity]},
	capacity{capacity},
	frontIndex{items[0]},
	growBy{growBy},
	backIndex{items[0]},
	counter{0}
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
	if(counter == 0){
		items[0] = ch;
		counter++;
		return true;
	}
	else{
		if(frontIndex == 0){ 
				frontIndex = capacity - 1;
				items[frontIndex] = ch;
				counter++;
				return true;
		}
		else{
			frontIndex = frontIndex - 1;
			items[frontIndex] = ch;
			counter++;
			return true;
		}

	}

	return false;
}

// items are pushed to successively HIGHER slots in the circular array
// (except for when the end of the array "wraps around" to the beginning)
bool Quack::pushBack(const char ch)
{	
	
	if(items[backIndex]){
		backIndex = backIndex + 1;
		items[backIndex] = ch;

		//items[backIndex + 1] = ch;
		//backIndex = backIndex + 1;
		counter += 1;
		return true;
	}
	else if(counter == 0){
		items[backIndex] = ch;
		counter += 1;
		return true;
	}
	return false;
}

bool Quack::popFront(char& ch)
{	
	if(counter == 0){
		return false;
	}else{
		ch = items[frontIndex];
		
		if(frontIndex == capacity - 1){
			frontIndex = 0;
			return true;
		}else{
			frontIndex = frontIndex + 1;
			counter = counter - 1;
			return true;
		}
	}
	return false;
}

bool Quack::popBack(char& ch)
{
	if(counter == 0){
		return false;
	}else{
		ch = items[backIndex];
		if(backIndex == (0)){
			backIndex = capacity - 1;
			counter = counter - 1;
			return true;
		}else{
			backIndex = backIndex - 1;
			counter = counter - 1;
			return true;
		}
	}
	return false;
}

void Quack::rotate(int r)
{
	if(counter != capacity){
		if(r > 0){
			int index = frontIndex;

			items[backIndex + 1] = items[frontIndex];
			for(int i = 0; i < capacity - counter; i++){
				items[index] = items[index + 1];
				index = index + 1;
			}
			frontIndex = frontIndex + r;
			backIndex = backIndex + r;
			if(frontIndex >= capacity){
				frontIndex = frontIndex - capacity;
			}
		}else if(r < 0){
			
		}
	}
}

void Quack::reverse(void)
{
}

int	Quack::itemCount(void)
{
	return counter;
}

ostream& operator<<(ostream& out, Quack *q)
{
	int index = q->frontIndex;
	out << "quack: ";
	if(q->counter != 0){
		while(index != q->backIndex){
			
			//if the array @ space index has 
			//a null char, output a blank space
			//else out the contents and a comma
			(q->items[index] == '\0' ? out << "" : out << q->items[index] << ", ");
			
			if(index == (q->capacity - 1)){
				index = 0;
			}	
			else{
				index = index + 1;
			}
		}
		out << q->items[index];
	
	}
	else{
		out << "empty ";
	}

	out << endl << endl;
	// returning out is ALWAYS required for an operator<< overload
	return out;
}
