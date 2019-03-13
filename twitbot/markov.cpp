#include "markov.hpp"
#include <algorithm>
#include <ctime>
#include <fstream>
#include <iterator>
#include <random>
#include <sstream>
#include <vector>

using namespace markov;

vector<word> markovChain::getChain(string key) {
    return this->chain[key];
}

/* Constructor that makes the chain using a text file as the 
   input */
markovChain::markovChain(fstream& input) {
    input.open("twitter.txt");

    string first = "";
    string second = "";
    input >> first;
    input >> second;

    while (!input.eof()) {
        /*if there is no key first, create a pair using the first
		  word as they key and the second word to instantiate a word
		  class into the vector */

        if (this->chain.count(first) == 0) {
            word w(second);
            chain.emplace(first, vector<word>());
            chain.at(first).push_back(w);
        }

        else if (this->chain.count(first) > 0) {
            /*if the second word is already added to the vector, 
			  increment its count */
            word w(second);

            auto itr = find(this->chain.at(first).begin(),
                            this->chain.at(first).end(), w);

            if (itr == this->chain.at(first).end()) {
                this->chain.at(first).push_back(w);
            } else {
                itr->increment();
            }

            // // else
            // // else {

            // }
        }

        first = second;
        input >> second;
    }
    input.close();

    // for(auto itr = this->chain.begin(); itr != this->chain.end(); itr++) {
    // 	for(auto it = this->chain.at((*itr).first).begin(); it != this->chain.at((*itr).first).end(); it++ ) {
    // 		(*it).setProbability(this->chain);
    // 	}
    // }
}

/* Constructor that makes the chain using a string as the 
   input */
markovChain::markovChain(string input) {
    //Copy the string into a vector word by word (whitespace delimted)
    istringstream iss(input);
    vector<string> in;
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(in));

    string first = "";
    string second = "";

    // Iterate through the vector
    for (auto iterator = in.begin(); iterator != in.end() - 1; iterator++) {
        first = *iterator;
        second = *(iterator + 1);

        /*if there is no key first, create a pair using the first
		  word as they key and the second word to instantiate a word
		  class into the vector */
        if (this->chain.count(first) == 0) {
            word w(second);
            chain.emplace(first, vector<word>());
            chain.at(first).push_back(w);
        }

        else if (this->chain.count(first) > 0) {
            /*if the second word is already added to the vector, 
			  increment its count */
            word w(second);

            auto itr = find(this->chain.at(first).begin(),
                            this->chain.at(first).end(), w);

            if (itr == this->chain.at(first).end()) {
                this->chain.at(first).push_back(w);
            } else {
                itr->increment();
            }
        }

        /* Check if word is uppercase, if it is, 
        consider it a sentence starter.*/
        if (isupper(first[0])) {
            startingWords.push_back(first);
        }
    }
}

/* Function to print the chain's key value pairs */
void markovChain::printChain() {
    for (auto itr = this->chain.begin(); itr != this->chain.end(); itr++) {
        cout << (*itr).first << " : "
             << "{ ";
        for (auto it = (*itr).second.begin(); it != (*itr).second.end(); it++) {
            if ((*it).getKey() != "") {
                cout << (*it).getKey() << " (" << (*it).getProbability() << ") ";
            }
        }
        cout << " }" << endl;
    }
}
/* Function that sets the weights for each word in the markov chain */
void markovChain::setProbabilities() {
    float sum = 0;   //number of words that occur
    float prob = 0;  //probability

    /* Loops through the chain, setting the probabilities of each 
 	   word in each vector corresponding to a key */
    for (auto iter = this->chain.begin(); iter != this->chain.end(); iter++) {
        for (auto itr = (*iter).second.begin(); itr != (*iter).second.end(); itr++) {
            sum += (*itr).getCount();
        }
        for (auto itr = (*iter).second.begin(); itr != (*iter).second.end(); itr++) {
            if ((*itr).getKey() != "") {
                prob = (*itr).getCount() / sum;
                (*itr).setProbability(prob);
            }
        }
        sum = 0;
    }
}

/* Function that returns one of the top three highest probability 
   words in a vector of words (which is assocaited with a key in 
   the markov chain) */
string markovChain::highProb(vector<word>& w) {
    int random = rand() % 3 + 1;
    word highest;
    sort(w.begin(), w.end(), word::compare);
    if (w.size() > random) {
        highest = w.at(random);
    } else {
        highest = w.at(0);
    }
    return highest.getKey();
}

string markovChain::highProb2(vector<word>& w) {
    int sum = 0;
    
}

/* Function that returns a vector of strings that are "start words"
   in the input file, these are used to determine a word to start with 
   for sentence generation */
vector<string> markovChain::startWords() {
    fstream input;
    input.open("twitter.txt");
    string first = "";
    string second = "";
    input >> first;
    input >> second;
    vector<string> startWords;

    while (!input.eof()) {
        char end = first.back();
        if (end == '.') {
            startWords.push_back(second);
        }
        input >> first;
        input >> second;
    }

    input.close();
    return startWords;
}

/* Function that checks & changes punctuation of the generated sentence.
   Removes certain punctation marks, changes case accordingly, adds a
   period at the end */
void markovChain::punc(string& s) {
    s.erase(remove(s.begin(), s.end(), '.'), s.end());
    s.erase(remove(s.begin(), s.end(), '"'), s.end());
    s[0] = toupper(s[0]);
    s.append(".");
    for (int i = 1; i < s.length(); i++) {
        if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        }
    }
}

/* Generates a sentence using weights of the markov chain and 
   returns the sentence as a string */
string markovChain::sentenceGen() {
    string sentence = "";
    string newWord = "";
    srand(time(NULL));
    // vector<string> start = startWords();
    // int index = rand() % start.size();

    auto random_it = next(begin(this->chain), rand() % this->chain.size());

    newWord = highProb((*random_it).second);
    sentence.append(newWord);
    vector<word> words = this->chain[highProb((*random_it).second)];

    for (int i = 0; i < 40; i++) {
        // cout << newWord << endl;
        sentence.append(" ");
        newWord = highProb(words);
        sentence.append(newWord);
        words = this->chain[newWord];
    }
    punc(sentence);
    return sentence;
}

string  markovChain::sentenceGen2() {
    string result = "";
    string newWord;
    vector<word> words;
    
    for (int i = 0; i < 5; i++) {
        auto it = startingWords.begin();
        int randomIndex = rand() % startingWords.size();
        advance(it, randomIndex);
        result.append(*it);
        result.append(" ");
        words = chain[(*it)];
        while (true) {
            newWord = highProb(words);
            result.append(newWord);
            result.append(" ");
            words = chain[newWord];
            if (newWord.back() == '.' || newWord.back() == '!' || newWord.back() == '?') {
                break;
            }
        }
    }

    return result;
}
