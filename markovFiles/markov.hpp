#ifndef MARKOV_HPP
#define MARKOV_HPP
#include <cstdlib>
#include <string>
#include <unordered_map>
#include<vector>

using namespace std;

namespace markov {
	/*data class that the unordered map will contain to indicate
	 count for the number of occurences */
	class word {
	public:
		word(string);
		int getCount();
		void setCount(int);
		string getKey();
		void setKey(string);
		void increment();
		bool operator == (const word& w); 
	private:
		int count;
		string key;
	};
	
	/* Class that will contain the actual markov chain*/
	class markovChain {
	public:
		markovChain();
		markovChain(fstream &);
		markovChain(string);
		void printChain();
	private:
		unordered_map<string, vector<word>>  chain;
	};
}


#endif
