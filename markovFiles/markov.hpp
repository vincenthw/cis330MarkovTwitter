#ifndef MARKOV_HPP
#define MARKOV_HPP
#include <cstdlib>
#include <string>
#include <unordered_map>


using namespace std;

namespace markov {
	class word {
	public:
		word(string);
		int getCount();
		void setCount(int);
		string getKey();
		void setKey(string);
		void increment();
	private:
		int count;
		string key;
	};

	class markovChain {
	public:
		markovChain();
		void setChain(fstream &input);
		void printChain();
	private:
		unordered_map<string, vector<word>>  chain;
	};
}


#endif
