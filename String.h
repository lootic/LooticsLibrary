/* This String class is my String class, there are many like it but this String 
* class is mine.
*
* Every function returning a String& is destructive, we return a String& to
* support function-chaining for complicated tasks.
*
* Inspiration is one part Automata-Theory, one part Python and Rubys strings and
* one part language technology, these three ways to think of strings seems to be
* playing nice together:
* http://en.wikipedia.org/wiki/Comparison_of_programming_languages_%28string_functions%29#split
* http://en.wikipedia.org/wiki/String_operations
*/
#include "Algorithm.h"

class String {
	int mLength;
	char* mString; //let it be mutable
public:
	String(const char* string): mString(const_cast<char*>(string)), mLength(Algorithm::length(string)) {} //init length in construction!
	/** Comparison 
	* Lexicographic comparison operators to help checking*/
	bool operator<=(String& other);
	bool operator<(String& other);
	bool operator>=(String& other);
	bool operator>(String& other);
	bool operator==(String& other);
	bool operator!=(String& other);
	int compare(String& other);
	bool contains(String& other);
	int matches(String& other);
	
	//concatenation and substrings
	String operator+(String& other);
	String operator+=(String& other);
	
	/** Access */
	char operator[](unsigned int index);
	int find_first(String& search);
	int find_last(String& search);
	int* find_all(String& search);
	
	/** Reordering */
	/* Lexicographic increment and decrement */
	String& operator++();
	String& operator++(int postfix);
	String& operator--();
	String& operator--(int postfix);
	
	String& reverse();
	String& scramble();
	
	/** Formatting */
	/** Whitespace */
	String& trim();
	String& center_allign(int space);
	String& center_allign(String& wrap, int space);
	String& left_allign(int space);
	String& left_allign(String& wrap, int length);
	String& right_allign(int length);
	String& right_allign(String& wrap, int length);
	
	/** Case */
	String& upper_case();
	String& upper_case(int pos);
	String& upper_case(String& match);
	String& lower_case();
	String& lower_case(int pos);
	String& lower_case(String& match);
	String& swap_case();
	
	/** Manipulation */
	String& replace(String& search, String& replace);
	String& join(String* strings, String& separator);
	//String& join(String&... strings, String& separator); c++11 variadic templates
	String& substring(int start_index, int end_index);
	String& insert(String&, int pos)
	 
	String& remove_first(String& other);
	String& remove_last(String& other);
	String& remove_all(String& other);
	
	/** Metrics 				   http://en.wikipedia.org/wiki/String_metric */
	int length();
	int overlap(String& other);
	int levenshtein_distance(String& other);
};

bool String::operator<=(String& other) {
	for(int i=0; i < this->length() < other.length() ?
		this->length() : other.length(); ++i) {
		if((*this)[i] < other[i]) {
			return true;
		} else if((*this)[i] > other[i]) {
			return false;
		}
	}
	return this->length() <= other.length();
}

bool String::operator<(String& other) {
	for(int i=0; i < this->length() < other.length() ?
		this->length() : other.length(); ++i) {
		if((*this)[i] < other[i]) {
			return true;
		} else if((*this)[i] > other[i]) {
			return false;
		}
	}
	return this->length() < other.length();
}

bool String::operator>=(String& other) {
	for(int i=0; i < this->length() < other.length() ?
		this->length() : other.length(); ++i) {
		if((*this)[i] > other[i]) {
			return true;
		} else if((*this)[i] < other[i]) {
			return false;
		}
	}
	return this->length() >= other.length();
}

bool String::operator>(String& other) {
	for(int i=0; i < this->length() < other.length() ?
		this->length() : other.length(); ++i) {
		if((*this)[i] > other[i]) {
			return true;
		} else if((*this)[i] < other[i]) {
			return false;
		}
	}
	return this->length() > other.length();
}

bool String::operator==(String& other) {
	if(this->length() != other.length()) {
		return false;
	}
	for(int i=0; i < this->length(); ++i) {
		if((*this)[i] != other[i]) {
			return false;
		}
	}
	return true;
}

bool String::operator!=(String& other) {
	if(this->length() != other.length()) {
		return true;
	}
	for(int i=0; i < this->length(); ++i) {
		if((*this)[i] != other[i]) {
			return true;
		}
	}
	return false;
}

String& String::operator++() {
	int i;
	int j;
	
	for(i=this->length()-2; i > -1 && s[i] > s[i+1]; --i);
	if(i > -1) {
		for(j=i+1; j < this->length();
	}
	++i;
	j = this->length()-1;
	//finish this later 
}

int String::length() {
	return mLength;
}