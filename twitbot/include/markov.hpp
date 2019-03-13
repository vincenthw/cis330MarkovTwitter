#ifndef MARKOV_HPP
#define MARKOV_HPP
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

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
    string sentenceGen();
    string sentenceGen2();
    void punc(string &);
    string highProb(vector<word> &);
    string highProb2(vector<word> &);
    vector<string> startWords();

   private:
    unordered_map<string, vector<word>> chain;
    vector<string> startingWords;
};

}  // namespace markov

#endif
