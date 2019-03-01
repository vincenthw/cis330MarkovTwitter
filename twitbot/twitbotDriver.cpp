#include "twitcurlWrapper.h"
#include <string>
#include <iostream>

int main()
{
	std::string search= "";

	while(search == ""){
		std::cout << "Please insert a category of interest: ";
		std::cin >> search;
		if(search[0] == '#'){
			std::cout << "You can not enter hashtags for your search" << std::endl;
			std::cin.ignore(1000000, '\n');
			std::cin.clear();
			search = "";
		}
	}

	if(search != ""){
		if(search[0] != '#'){
	    	TwitcurlWrapper twitWrapper;
    
		    // uses twitter "search" functionality
		    std::string searchTweets = twitWrapper.searchTwitter(search, 4);
		    std::cout << searchTweets << std::endl;

		    // grabs latest tweets by @realDonaldTrump
		    std::string userTweets = twitWrapper.getTweetsByUser("realDonaldTrump", 200, true);
		    //std::cout << userTweets << std::endl;
		}
	}

    // TwitcurlWrapper twitWrapper;
    
    // // uses twitter "search" functionality
    // std::string searchTweets = twitWrapper.searchTwitter(search, 10);
    // // std::cout << searchTweets << std::endl;

    // // grabs latest tweets by @realDonaldTrump
    // std::string userTweets = twitWrapper.getTweetsByUser("realDonaldTrump", 200, true);
    // std::cout << userTweets << std::endl;

    exit(0);
}