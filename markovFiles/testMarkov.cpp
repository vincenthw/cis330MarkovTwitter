#include "markov.hpp"
#include <fstream>

using namespace markov;

int main() {
	fstream input;
	markovChain mark(input);
	mark.printChain();
	
}
