#include "markov.hpp"
#include <fstream>
#include <iostream>

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



markovChain::markovChain() {

}

void markovChain::setChain(fstream &input) {
	input.open("twitter.txt");
	if(this->chain.count("twitter") == 0) {
		word w("twitter");
		chain.insert(make_pair("twitter", w));
	}
	for(auto i : chain)
		cout << i.first << endl;
}
