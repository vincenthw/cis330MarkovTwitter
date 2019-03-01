#include "markov.hpp"
#include <sstream>
#include <fstream>
#include <vector>

using namespace markov;



//Overloaded equality operator for words
bool word::operator ==(const word& w){
			
			if(this->key == w.key)
				return true;
			return false;
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

//Word setters
void word::setCount(int c) {
	this->count = c;
}
void word::setKey(string k) {
	this->key = k;
}

//Word increment
void word::increment() {
	this->count++;
}


/* Constructor that makes the chain using a text file as the 
   input */
markovChain::markovChain(fstream &input) {
	input.open("twitter.txt");
	
	string first = "";
	string second = "";
	input >> first;
	input >> second;

	while(!input.eof()){

		/*if there is no key first, create a pair using the first
		  word as they key and the second word to instantiate a word
		  class into the vector */

		if(this->chain.count(first) == 0) {
			word w(second);
			chain.emplace(first, vector<word>());
			chain.at(first).push_back(w);
		} 


		else if(this->chain.count(first) > 0) {
			/*if the second word is already added to the vector, 
			  increment its count */
			word w(second);

			auto itr = find(this->chain.at(first).begin(), 
							this->chain.at(first).end(), w);

			if(itr == this->chain.at(first).end()) {
				this->chain.at(first).push_back(w);
			} else {
				itr->increment();
			}
			

			// // else 
			// // else {
			
			// }	
		}


		first = second;
		input >> second;
	}
	input.close();
}

/* Constructor that makes the chain using a string as the 
   input */
markovChain::markovChain(string input) {	
	//Copy the string into a vector word by word (whitespace delimted)
	istringstream iss(input);
	vector<string> in;
	copy(istream_iterator<string>(iss), 
		 istream_iterator<string>(),
		 back_inserter(in));

	string first = "";
	string second = "";


	// Iterate through the vector 
	for(auto iterator = in.begin(); iterator != in.end(); iterator++){
		first = *iterator;
		second = *(iterator+1);

		/*if there is no key first, create a pair using the first
		  word as they key and the second word to instantiate a word
		  class into the vector */
		if(this->chain.count(first) == 0) {
			word w(second);
			chain.emplace(first, vector<word>());
			chain.at(first).push_back(w);
		} 


		else if(this->chain.count(first) > 0) {
			/*if the second word is already added to the vector, 
			  increment its count */
			word w(second);

			auto itr = find(this->chain.at(first).begin(), 
							this->chain.at(first).end(), w);

			if(itr == this->chain.at(first).end()) {
				this->chain.at(first).push_back(w);
			} else {
				itr->increment();
			}
			
		}

	}


}

/* Function to print the chain's key value pairs */
void markovChain::printChain() {
	for(auto itr = this->chain.begin(); itr != this->chain.end(); itr++) {
		cout << (*itr).first << " : " << "{ ";
		for(auto it = (*itr).second.begin(); it != (*itr).second.end(); it++) {
			cout  << (*it).getKey() << " (" << (*it).getCount() << ") ";
		}
		cout << " }" << endl;
	}
}











