#include "markov.hpp"
#include <fstream>

using namespace markov;

word::word() { }
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
	this->wordCount = 0;
}
void markovChain::setChain(fstream &input) {

}