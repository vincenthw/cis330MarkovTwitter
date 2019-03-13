#include "twitcurlWrapper.h"
#include "markov.hpp"
#include <string>
#include <iostream>
#include <fstream>


int main()
{
	std::string tweet;
	std::string funct;
	std::string data;
	std::ifstream f("../os_test/hack_test.txt");

	std::getline(f,funct);
	std::getline(f,data);
	TwitcurlWrapper twitWrapper; 

	if(funct == "handle"){
		 if (data.empty() || !twitWrapper.isValidUsername(data)) {
			std::cout << "Invalid username, try again." << std::endl;
		}
		tweet = twitWrapper.getTweetsByUser(data, 200, true);
	}
	else if (funct == "keyword"){
		tweet = twitWrapper.searchTwitter(data, 50);
	}
	else{
		std::cout << "The file was not opened or is not there" << std::endl;
	}
	
	std::cout << tweet << std::endl;

	markov::markovChain chain(tweet);
	chain.printChain();
	chain.sentenceGen();
	

	exit(0);
}
