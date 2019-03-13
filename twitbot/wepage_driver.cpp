#include "twitcurlWrapper.h"
#include "markov.hpp"
#include <string>
#include <iostream>
#include <fstream>
/*
// Function to prompt user for twitter usernames that will be used in markov chain
std::string getInputUsernames(TwitcurlWrapper twitWrapper)
{
	std::string username;
	bool running = true;
	std::string combinedTweets;

OUTER:
	while (running)
	{
		std::cout << "Enter a twitter username: ";
		std::getline(std::cin, username);

		std::cout << "checking valid: " << username << std::endl;
		if (username.empty() || !twitWrapper.isValidUsername(username))
		{
			std::cout << "Invalid username, try again." << std::endl;
			continue;
		}

		combinedTweets.append(twitWrapper.getTweetsByUser(username, 200, true));
		std::cout << "Added " << username << "'s last 200 tweets to the markov chain generation. " << std::endl;

		while (running)
		{
			std::string input;
			std::cout << "Add another user [Y/N]? ";
			std::getline(std::cin, input);
			if (std::toupper(input[0]) == 'Y')
			{
				goto OUTER;
			}
			else if (std::toupper(input[0]) == 'N')
			{
				running = false;
			}
		}
	}

	return combinedTweets;
}

// Function to prompt users for search queries that will be used in markov chain
std::string getInputSearch(TwitcurlWrapper twitWrapper)
{
	std::string search = "";

	while (search == "")
	{
		std::cout << "Please insert a category of interest: ";
		std::cin >> search;
		if (search[0] == '#')
		{
			std::cout << "You can not enter hashtags for your search" << std::endl;
			std::cin.ignore(1000000, '\n');
			std::cin.clear();
			search = "";
		}
	}

	if (search != "")
	{
		if (search[0] != '#')
		{
			// uses twitter "search" functionality
			std::string searchTweets = twitWrapper.searchTwitter(search, 1);
			std::cout << searchTweets << std::endl;

		}
	}
}
*/
int main()
{
	std::string tweet;
	std::string funct;
	std::string data;
	std::ifstream f("hack_test.txt");

	std::getline(f,funct)
	std::getline(f,data)
	TwitcurlWrapper twitWrapper; 

	if(funct == "handle"){
		 if (data.empty() || !twitWrapper.isValidUsername(data)) {
			std::cout << "Invalid username, try again." << std::endl;	
			continue;
		}
		std::string tweet = twitWrapper.getTweetsByUser(data, 50, true)
		}
	else if (funct == "keyword"){
		std::string tweet = twitWrapper.searchTwitter(data, 50);
	}
	else{
		std::cout << "The file was not opened or is not there" << std::endl;
	}
	
//	TwitcurlWrapper twitWrapper;

	/* It works!!!!! 
		Asks users for twitter usernames, 
		generates markov chain frequencies, 
		prints frequencies. 
	 */
//	std::string s = getInputUsernames(twitWrapper);
	std::cout << tweet << std::endl;
	markov::markovChain chain(tweet);
	chain.printChain();
	chain.genSentence();
	
	/* 
	Code here to ask what user wants to do:
		0 use tweets from search
		1 use tweets from specific users
	
	Then call the appropriate function:
		string combinedTweets;

		if (0) { combinedTweets = getInputSearch(twitWrapper); }
		if (1) { combinedTweets = getInputUsernames(twitWrapper); }

	Then use the markov chain somehow:

		markovChain chain(combinedTweets);
		chain.printChain();

	 */

	exit(0);
}
