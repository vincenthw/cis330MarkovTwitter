#ifndef WORD_HPP
#define WORD_HPP
#include <cstdlib>
#include <string>
#include<vector>

#include "markov.hpp"

using namespace std;
/* data class that the unordered map will contain to indicate
	 count for the number of occurences */
namespace markov {

class markovChain;

class word {
	friend class markovChain;
	public:
		word();
		word(string);

		int getCount();
		string getKey();
		float getProbability();

		void setCount(int);
		void setKey(string);
		void setProbability(float&);

		void increment();
		bool operator == (const word& w); 
	private:
		int count;
		string key;
		float probability;
	};
}
#endif