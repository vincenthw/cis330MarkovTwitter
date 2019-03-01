#include "markov.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace markov;

bool word::operator ==(const word& w){
			
			if(this->key == w.key)
				return true;
			return false;
		}

word::word(string key) { 
	this->key = key;
	this->count = 1;
}
int word::getCount() {
	return this->count;
}
void word::setCount(int c) {
	this->count = c;
}
string word::getKey() {
	return this->key;
}
void word::setKey(string k) {
	this->key = k;
}
void word::increment() {
	this->count++;
}

markovChain::markovChain() {

}


markovChain::markovChain(fstream &input) {
	input.open("twitter.txt");
	
	string first = "";
	string second = "";
	
	while(!input.eof()){
		input >> first;
		input >> second;

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
			vector<word> temp = this->chain.at(first); 
			word w(second);
			auto itr = find(temp.begin(), temp.end(), w);
			if(itr == temp.end()) {
				int v = 0;
			}
			

			// // else 
			// // else {
			
			// }	
		}


		
	}
}

markovChain::markovChain(string input) {


}

void markovChain::printChain() {
	for(auto itr = this->chain.begin(); itr != this->chain.end(); itr++) {
	} 
	cout << endl;
}
