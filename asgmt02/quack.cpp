// add code to these functions to make Quack do something useful

#include "quack.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	Quack::YOUR_NAME[]{"Paul Hubbard"};

// change the value of this variable to true if you're doing the Premium version
const bool	Quack::PREMIUM_VERSION{true};

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
		if(counter + 1 == capacity){
			int newCapacity = capacity + growBy;
			char * newItems = new char[newCapacity];
			for(int i = 0; i < capacity; i++){
				newItems[i] = '\0';
			}
			
			for(int i = 0; i < capacity; i++){
				items[i] = newItems[i];
			}

			items = newItems;
			capacity = newCapacity;
			
			frontIndex = frontIndex - 1;
			items[frontIndex] = ch;
			counter++;
			
			delete newItems;
			return true;
		}

	}

	return false;
}

// items are pushed to successively HIGHER slots in the circular array
// (except for when the end of the array "wraps around" to the beginning)
bool Quack::pushBack(const char ch)
{	
	if(counter == 0){
		items[backIndex] = ch;
		counter += 1;
		return true;
	}
	else{
		backIndex = (backIndex  == (capacity - 1) ? 0 : backIndex + 1);
			items[backIndex] = ch;
			counter += 1;
			return true;
	}

		if(counter + 1 == capacity){
			int newCapacity = capacity + growBy;
			char * newItems = new char[newCapacity];
			for(int i = 0; i < capacity; i++){
				newItems[i] = '\0';
			}
			
			for(int i = 0; i < capacity; i++){
				items[i] = newItems[i];
			}

			items = newItems;
			capacity = newCapacity;
			
			backIndex = (backIndex  == (capacity - 1) ? 0 : backIndex + 1);
			items[backIndex] = ch;
			counter += 1;
			
			delete newItems;
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
			counter = counter - 1;
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
	char ch;
		if(r > 0){
			for(int i = 0; i< r; i++)
			{	
				ch = items[frontIndex];
		
				if(frontIndex == capacity - 1){
					frontIndex = 0;
					counter = counter - 1;
				}else{
					frontIndex = frontIndex + 1;
					counter = counter - 1;
				}
				
				if(counter == 0){
					items[backIndex] = ch;
					counter += 1;
				}
				else{
					backIndex = (backIndex  == (capacity - 1) ? 0 : backIndex + 1);
					items[backIndex] = ch;
					counter += 1;
				}

			}
		}else if(r < 0){
			for(int i = r; i < 0; i++){
				
				ch = items[backIndex];

				if(backIndex == (0)){
					backIndex = capacity - 1;
					counter = counter - 1;
				}else{
					backIndex = backIndex - 1;
					counter = counter - 1;
				}
		
				if(counter == 0){
					items[0] = ch;
					counter++;
				}
				else{
					if(frontIndex == 0){ 
						frontIndex = capacity - 1;
						items[frontIndex] = ch;
						counter++;
					}
					else{
						frontIndex = frontIndex - 1;
						items[frontIndex] = ch;
						counter++;
					}
			}
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
