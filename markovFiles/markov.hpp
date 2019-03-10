#ifndef MARKOV_HPP
#define MARKOV_HPP
#include <cstdlib>
#include <string>
#include <unordered_map>
#include<vector>
#include <fstream>
#include <iostream>
#include <sstream>

#include "word.hpp"

using namespace std;

namespace markov {

	class word;
	
	/* Class that will contain the actual markov chain*/
	class markovChain {

		friend class word;
	public:
		markovChain();
		markovChain(fstream &);
		markovChain(string);
		void printChain();
		vector<word> getChain(string key);
		void setProbabilities();
		void sentenceGen();
		string highProb(vector<word>&);

	private:
		unordered_map<string, vector<word>>  chain;
	};

}


#endif
