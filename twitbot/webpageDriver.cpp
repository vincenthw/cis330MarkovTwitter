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
	//Variables for holding data for the tweets
	std::string tweet = "";
	std::string funct;
	std::string data;

	//Opens file written to from python to extract the data
	std::ifstream f("../os_test/hack_test.txt");

	std::getline(f,funct);
	TwitcurlWrapper twitWrapper;

	//Check to see which method of tweet generation user selected
	if(funct == "handle"){
		while(!f.eof()){ //If multiple usernames were input were inserted perform multiple times
			std::getline(f, data);
			if (!twitWrapper.isValidUsername(data)) { //Ensure the username was valid
				std::cout << "Invalid username, try again." << std::endl;
			}
			tweet.append(twitWrapper.getTweetsByUser(data, 200, true)); //concatenate tweets from all users
		}
	}
	if (funct == "keyword"){
		while(!f.eof()){ //if multiple search categories were input perform multiple times
			std::getline(f, data);
			tweet.append(twitWrapper.searchTwitter(data, 200)); //concatenate tweets from all categories
		}
	}

	else{//file was empty or open was unsuccessful
		std::cout << "The file was not opened, is not there, or was empty" << std::endl;
	}

	//Have markov chain generate tweet from the extracted tweets
	markov::markovChain chain(tweet);
	chain.setProbabilities();
	std::string ourTweet = chain.sentenceGen();

	//check if tweet is too big for a tweet if it is just tweet what is can be fit
	if(ourTweet.size() > 130){ //restrict size to be under 140 cause its an old api don't think it was updated to new tweet length
		ourTweet.substr(0, 130);
		tweetIt(twitWrapper, ourTweet);
	}
	else{
		tweetIt(twitWrapper, ourTweet);
	}

	exit(0);
}
