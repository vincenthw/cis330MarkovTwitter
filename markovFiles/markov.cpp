#include "markov.hpp"
#include <fstream>
#include <iostream>
#include <vector>

using namespace markov;

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

}


markovChain::markovChain() {

}
bool isPresent(const markovChain& markov, word w, string key) {
	
}

void markovChain::printChain() {
	for(auto itr = this->chain.begin(); itr != this->chain.end(); itr++) {
	} 
	cout << endl;
}
void markovChain::setChain(fstream &input) {
	input.open("twitter.txt");
	
	string first = "";
	string second = "";
	
	while(!input.eof()){
		input >> first;
		input >> second;
		cout << first << endl;
		cout << second << endl;
		if(this->chain.count(first) == 0) {
			word w(second);
			chain.emplace(first, vector<word>());
			chain.at(first).push_back(w);
		} else {
			word w(second);
			(chain[first].data())->increment();
		}
	}
}
