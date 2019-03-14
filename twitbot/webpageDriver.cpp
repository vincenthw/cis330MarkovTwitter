#include "twitcurlWrapper.h"
#include "markov.hpp"
#include <string>
#include <iostream>
#include <fstream>

// std::string getInputUsernames(TwitcurlWrapper twitWrapper)
// {
// 	std::string username;
// 	bool running = true;
// 	std::string combinedTweets;

// OUTER:
// 	while (running)
// 	{
// 		std::cout << "Enter a twitter username: ";
// 		std::getline(std::cin, username);

// 		std::cout << "checking valid: " << username << std::endl;
// 		if (username.empty() || !twitWrapper.isValidUsername(username))
// 		{
// 			std::cout << "Invalid username, try again." << std::endl;
// 			continue;
// 		}

// 		combinedTweets.append(twitWrapper.getTweetsByUser(username, 200, true));
// 		// std::cout << "Added " << username << "'s last 200 tweets to the markov chain generation. " << std::endl;

// 		while (running)
// 		{
// 			std::string input;
// 			std::cout << "Add another user [Y/N]? ";
// 			std::getline(std::cin, input);
// 			if (std::toupper(input[0]) == 'Y')
// 			{
// 				goto OUTER;
// 			}
// 			else if (std::toupper(input[0]) == 'N')
// 			{
// 				running = false;
// 			}
// 		}
// 	}

// 	return combinedTweets;
// }

// // Function to prompt users for search queries that will be used in markov chain
// std::string getInputSearch(TwitcurlWrapper twitWrapper)
// {
// 	std::string search = "";

// 	while (search == "")
// 	{
// 		std::cout << "Please insert a category of interest: ";
// 		std::cin >> search;
// 		if (search[0] == '#')
// 		{
// 			std::cout << "You can not enter hashtags for your search" << std::endl;
// 			std::cin.ignore(1000000, '\n');
// 			std::cin.clear();
// 			search = "";
// 		}
// 	}

// 	if (search != "")
// 	{
// 		if (search[0] != '#')
// 		{
// 			// uses twitter "search" functionality
// 			std::string searchTweets = twitWrapper.searchTwitter(search, 1);
// 			std::cout << searchTweets << std::endl;

// 		}
// 	}
// }
void tweetIt(TwitcurlWrapper twitWrapper, String sentence){
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
		 if (data.empty() || !twitWrapper.isValidUsername(data)) {
			std::cout << "Invalid username, try again." << std::endl;
		}
		while(!input.eof()){
			tweet.append(twitWrapper.getTweetsByUser(data, 100, true); 
		}
//		tweet = twitWrapper.getTweetsByUser(data, 200, true);
	}
	else if (funct == "keyword"){
		while(!input.eof){
			tweet.append(twitWrapper.searchTwitter(data, 100));
		}
	}

	else{
		std::cout << "The file was not opened or is not there" << std::endl;
	}
	
	std::cout << tweet << std::endl;

	markov::markovChain chain(tweet);
	chain.setProbabilities();
	tweetIt(twitWrapper, chain.sentenceGen());
	

	exit(0);
}
