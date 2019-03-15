#include "twitcurlWrapper.h"
#include "markov.hpp"
#include <string>
#include <iostream>
#include <fstream>

void tweetIt(TwitcurlWrapper twitWrapper, std::string sentence){
	twitWrapper.statusUpdate(sentence);
}


int main()
{
	std::string tweet = "";
	std::string funct;
	std::string data;
	std::ifstream f("../os_test/hack_test.txt");

	std::getline(f,funct);
//	std::getline(f,data);
	TwitcurlWrapper twitWrapper; 

	if(funct == "handle"){
		while(!f.eof()){
			std::getline(f, data);
			if (!twitWrapper.isValidUsername(data)) {
				std::cout << "Invalid username, try again." << std::endl;
			}
			std::cout << "getting data from" << data << std::endl;
			tweet.append(twitWrapper.getTweetsByUser(data, 100, true)); 
		}
	}
	else if (funct == "keyword"){
		std::cout << "searching keyword: " << std::endl;
		while(!f.eof()){
			std::getline(f, data);
			tweet.append(twitWrapper.searchTwitter(data, 2));
		}
	}

	else{
		std::cout << "The file was not opened or is not there" << std::endl;
	}
	
	std::cout << tweet << std::endl;

	markov::markovChain chain(tweet);
	chain.setProbabilities();
	std::string ourTweet = chain.sentenceGen();

	//check if tweet is too big for a tweet if it is just tweet what is can be fit
	if(ourTweet.size() > 130){
		ourTweet.substr(0, 130);
		tweetIt(twitWrapper, ourTweet);
	}
	else{
		tweetIt(twitWrapper, ourTweet);
	}

	exit(0);
}
