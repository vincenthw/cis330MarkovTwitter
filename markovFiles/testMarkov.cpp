#include "markov.hpp"
#include <fstream>

using namespace markov;

/* Program to test the markov chain and word classes */
int main() {
	fstream input;
	markovChain mark(input);

	mark.setProbabilities();

	string twit = mark.sentenceGen();

	cout << twit << endl;
}	
	
