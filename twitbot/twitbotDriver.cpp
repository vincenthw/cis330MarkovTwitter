#include "twitcurlWrapper.h"

int main()
{
    TwitcurlWrapper twitWrapper;
    
    // uses twitter "search" functionality
    std::string searchTweets = twitWrapper.searchTwitter("NBAonTNT", 10);
    // std::cout << searchTweets << std::endl;

    // grabs latest tweets by @realDonaldTrump
    std::string userTweets = twitWrapper.getTweetsByUser("realDonaldTrump", 200, true);
    std::cout << userTweets << std::endl;

    exit(0);
}