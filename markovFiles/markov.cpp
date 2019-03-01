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

markovChain::markovChain(string input) {


}

void markovChain::printChain() {
	for(auto itr = this->chain.begin(); itr != this->chain.end(); itr++) {
		cout << (*itr).first << " : " << "{ ";
		for(auto it = (*itr).second.begin(); it != (*itr).second.end(); it++) {
			cout  << (*it).getKey() << " (" << (*it).getCount() << ") ";
		}
		cout << " }" << endl;
	}
}











