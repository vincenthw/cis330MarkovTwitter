#include "markov.hpp"
#include <vector>
#include <iterator>
#include <algorithm>

#include "word.hpp"

using namespace markov;

//Overloaded equality operator for words
bool word::operator ==(const word& w){
			
			if(this->key == w.key)
				return true;
			return false;
}



word::word() {
	this->key = "";
	this->count = 0;
	this->probability = 0.0;
}
//Word constructor with string as parameter
word::word(string key) { 
	this->key = key;
	this->count = 1;
}

//Word getters
int word::getCount() {
	return this->count;
}
string word::getKey() {
	return this->key;
}
float word::getProbability()  const {
	return this->probability;
}

//Word setters
void word::setCount(int c) {
	this->count = c;
}
void word::setKey(string k) {
	this->key = k;
}

void word::setProbability(float &p) {
	this->probability = p;
}

//Word increment
void word::increment() {
	this->count++;
}

bool word::compare(const word& l, const word& r) {
	return l.getProbability() < r.getProbability();
}


