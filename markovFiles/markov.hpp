#ifndef MARKOV_HPP
#define MARKOV_HPP
#include <cstdlib>
#include <string>
#include <unordered_map>

using namespace std;

namespace markov {

	class word {
	public:
		word();
		int getCount();
		void setCount(int);
		string getKey();
		void setKey(string);
	private:
		int count;
		string key;
	};

	class markovChain {
	public:
		markovChain();
		void setChain(fstream &input);
	private:
		unordered_map<string, word>  chain;
		int wordCount;
	};
}


#endif