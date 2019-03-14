#include "twitcurlWrapper.h"
#include "markov.hpp"
#include "commandLineIO.hpp"
#include <string>
#include <iostream>


int main()
{


	TwitcurlWrapper twitWrapper;


	/* std::string s = getInputUsernames(twitWrapper);
	markov::markovChain mark(s);
	mark.setProbabilities();
	// mark.printChain();
	std::string x = mark.sentenceGen2(); */

	// std::cout << x << std::endl;

        cout << "How would you like to use TwitBot?" << endl;
        cout << "[0] -- Generate tweet from Twitter user(s)" << endl;
        cout << "[1] -- Generate tweet from Twitter search" << endl;
		cout << "[2] -- Generate tweet from Text file" << endl;

        bool repeat;
		string result;
        do {
			repeat =  false;
            cout << "Make selection: ";
            string choice;
            getline(cin, choice);
            cout << endl;

            switch (choice[0]) {
                case '0': {
					result = getInputUsernames(twitWrapper);
                    markov::markovChain mark(result);
					mark.setProbabilities();
					result = mark.sentenceGen2();
                    break;
				}

                case '1': {
					result = getInputSearch(twitWrapper);
                    markov::markovChain mark(result);
                    mark.setProbabilities();
                    result = mark.sentenceGen2();
                    break;
				}
				
				case '2': {
					result = getInputTextFile(twitWrapper); // result is path to text file
					fstream input;
					markov::markovChain mark(input, result);
					mark.setProbabilities();
					result = mark.sentenceGen();
					break;
				}

                default: {
					repeat = true;
                    break;
				}
            }
        } while (repeat);

		cout << result << endl;

        exit(0);
}
