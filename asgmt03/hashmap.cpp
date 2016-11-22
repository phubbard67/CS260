#include "hashmap.h"
#include <cstring>

using namespace std;

// change the value of this variable to be your own name instead of "I. Forgot"
const char	HashMap::YOUR_NAME[] = "Paul Hubbard";

HashMap::HashMap(int capacity) :
slots{new Slot[capacity]},
capacity{capacity},
nStocks{0}
{
}

HashMap::~HashMap(void)
{
	delete [] slots;
	slots = nullptr;
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
	seqLength = 0;
	usedIndex = hashIndex;

	if(nStocks == 0 && slots[hashIndex].slotStatus == EMPTY){
		seqLength = 1;
		usedIndex = -1;
		return false;
	}

	if(slots[hashIndex].slotStatus == FULL && (strcmp(slots[hashIndex].slotStock.getSymbol(), symbol) == 0)){
		s = slots[hashIndex].slotStock;
		seqLength = 1;
		return true;
	}
	else if(slots[hashIndex].slotStatus == WAS_FULL && (strcmp(slots[hashIndex].slotStock.getSymbol(), symbol) == 0)){
		seqLength = 2;
		usedIndex = -1;
		return false;
	}		
	else{
		for(int i = hashIndex; i < capacity; i++){
			if(slots[i].slotStatus == FULL && strcmp(slots[i].slotStock.getSymbol(), symbol) == 0){
				s = slots[i].slotStock;
				seqLength += 1;
				usedIndex = i;
				return true;
			}
			seqLength++;
		}
		for(unsigned int i = 0; i <= hashIndex; i++){
			if(slots[i].slotStatus == FULL && strcmp(slots[i].slotStock.getSymbol(), symbol) == 0){
				s = slots[i].slotStock;
				seqLength += 1;
				usedIndex = i;
				return true;
			}
			seqLength++;
		}
	}
	
	usedIndex = -1;
	return false;
}

bool HashMap::put(const Stock& s,
				  unsigned int& symbolHash, unsigned int& hashIndex,
				  unsigned int& usedIndex, unsigned int& seqLength)
{
	symbolHash = hashStr(s.symbol);
	hashIndex = symbolHash % capacity;
	seqLength = 0;
	usedIndex = hashIndex;

	if(slots[hashIndex].slotStatus == EMPTY){
		slots[hashIndex].slotStock = s;
		slots[hashIndex].slotStatus = FULL;
		seqLength = 1;
		nStocks++;
		return true;
	}
	else{

		for(int i = hashIndex; i < capacity; i++){
			if(slots[i].slotStatus == FULL){
				if(strcmp(slots[i].slotStock.getSymbol(), s.symbol) == 0){
					return false;
				}
			}
			if(slots[i].slotStatus != FULL){
				slots[i].slotStock = s;
				slots[i].slotStatus = FULL;
				usedIndex = i;
				seqLength += 1;
				nStocks++;
				return true;
			}	
			seqLength++;
		}
	
	
		for(unsigned int i = 0; i < hashIndex; i++){
			if(slots[i].slotStatus == FULL){
				if(strcmp(slots[i].slotStock.getSymbol(), s.symbol) == 0){
					return false;
				}
			}
			if(slots[i].slotStatus != FULL){
				slots[i].slotStock = s;
				slots[i].slotStatus = FULL;
				usedIndex = i;
				seqLength += 1;
				nStocks++;
				return true;
			}
			seqLength++;
		}	
	}

	if(nStocks == capacity){
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
	symbolHash = hashStr(symbol);
	hashIndex = symbolHash % capacity;
	usedIndex = hashIndex;
	seqLength = 0;

	if((slots[hashIndex].slotStatus != WAS_FULL) && (strcmp(slots[hashIndex].slotStock.getSymbol(), symbol) == 0)){
		s = slots[hashIndex].slotStock;
		slots[hashIndex].slotStatus = WAS_FULL;
		seqLength += 1;
		nStocks--;
		return true;
	}
	else{
		for(int i = hashIndex; i < capacity; i++){
			if((slots[i].slotStatus != WAS_FULL)){
				if((slots[i].slotStatus != EMPTY) && (strcmp(slots[i].slotStock.getSymbol(), symbol) == 0)){
					s = slots[i].slotStock;
					slots[i].slotStatus = WAS_FULL;
					usedIndex = i;
					seqLength += 1;
					nStocks--;
					return true;
				}
			}
			seqLength++;
		}
		for(unsigned int i = 0; i <= hashIndex; i++){
			if(slots[i].slotStatus != WAS_FULL){
				if((slots[i].slotStatus != EMPTY) && (strcmp(slots[i].slotStock.getSymbol(), symbol) == 0)){
					s = slots[i].slotStock;
					slots[i].slotStatus = WAS_FULL;
					usedIndex = i;
					seqLength += 1;
					nStocks--;
					return true;
				}
			}
			seqLength++;
		}
	}

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
			if(h.slots[idx].slotStatus == 1){
				out << h.slots[idx].slotStock << endl;
			}
		}
	}
	else{
		out << "no stocks" << endl;
	}
	return out;
}
