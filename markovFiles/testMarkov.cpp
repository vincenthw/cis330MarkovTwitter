#include "markov.hpp"
#include <fstream>

using namespace markov;

/* Program to test the markov chain and word classes */
int main() {
	fstream input;
	markovChain mark("this is this is this is this is this is repetition");


	markovChain mark2(input);
	cout << "Mark" << endl;
	mark.printChain();
	cout << "Mark2" << endl;
	mark2.printChain();
}
	
