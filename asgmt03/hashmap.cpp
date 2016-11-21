#include "hashmap.h"

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	HashMap::YOUR_NAME[] = "Paul Hubbard";

HashMap::HashMap(int capacity) :
slots{new Slot[capacity]},
capacity{capacity},
nStocks{0}
{
	for(int i = 0; i <= capacity; i++){
		slots[i].full = false;
		slots[i].wasFull = false;
	} 
}

HashMap::~HashMap(void)
{
}

bool HashMap::get(char const * const symbol, Stock& s,
				  unsigned int& symbolHash, unsigned int& hashIndex,
				  unsigned int& usedIndex, unsigned int& seqLength)
	 const
{
	// If the symbol is not found, this function is required
	// to set usedIndex to -1 before it returns false.
	symbolHash = hashStr(symbol);
	hashIndex = symbolHash % capacity;
	seqLength = 1;
	usedIndex = 0;

	if(slots[hashIndex].full == true){
		usedIndex = hashIndex;
		return true;
	}
	else{
		usedIndex = -1;
		return false;
	}


	return false;
}

bool HashMap::put(const Stock& s,
				  unsigned int& symbolHash, unsigned int& hashIndex,
				  unsigned int& usedIndex, unsigned int& seqLength)
{
	symbolHash = hashStr(s.symbol);
	hashIndex = symbolHash % capacity;
	seqLength = 1;
	usedIndex = 0;

	if(slots[hashIndex].full == false){
		slots[hashIndex].slotStock = s;
		slots[hashIndex].full = true;
		usedIndex = hashIndex;
		nStocks++;
		return true;
	}
	else if(this->slots[hashIndex].slotStock.symbol != s.symbol){

		for(int i = hashIndex; i < capacity; i++){
			if(slots[i].full == false){
				slots[i].slotStock = s;
				slots[i].full = true;
				usedIndex = i;
				seqLength += i - hashIndex;
				nStocks++;
				return true;
			}
		} 
		for(unsigned int i = 0; i <= hashIndex; i++){
			if(slots[i].full == false){
				slots[i].slotStock = s;
				slots[i].full = true;
				usedIndex = i;
				seqLength = (capacity - hashIndex) + i;
				nStocks++;
				return true;
			}
		}
	}
	else if(nStocks == capacity){
		return false;
	}
	else{
		return false;
	}
	return false;
}

bool HashMap::remove(char const * const symbol, Stock& s,
					 unsigned int& symbolHash, unsigned int& hashIndex,
					 unsigned int& usedIndex, unsigned int& seqLength)
{
	return false;
}

unsigned int HashMap::hashStr(char const * const s)
{
	// Hash C string argument using the formula in java.lang.String.hashCode():
	//
	//   s[0]*(31^(n-1)) + s[1]*(31^(n-2)) + ... + s[n-1]
	//
	// s is the array of characters, n is the number of characters in the string,
	// and 31^n means 31 to the nth power.
	//
	// This function is declared static because its result depends
	// only on the characters in the string. You will need to apply
	// the modulo operator to the result of this function to generate
	// the required table index. The place to do this is in the functions
	// that call this function.
	//
	// You can and should do this computation entirely with integers. In other
	// words, there is no need to use floating point values. In particular, you
	// should not use the pow() function from <math.h> in this lab.
	
	int sInt = s[0];
	int i = 1;

	while(s[i]){
		sInt =  (sInt * 31) + s[i];
		i++;
	}			
	
	return sInt;
}

ostream& operator<<(ostream& out, const HashMap &h)
{

	if(h.nStocks != 0){
	 Stock::displayHeaders(out);
	 for(int idx = 0; idx < h.capacity; idx++){
			if(h.slots[idx].full == true){
				out << h.slots[idx].slotStock << endl;
			}
		}
	}
	else{
		out << "no stocks" << endl;
	}
	return out;
}
