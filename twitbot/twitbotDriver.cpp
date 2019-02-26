#include "tweetSearch.h"

int main()
{
    TweetSearch twitObj;
    
    // std::string searchTweets = twitObj.searchTwitter("Trump", 10);
    // std::cout << searchTweets << std::endl;

    std::string userTweets = twitObj.getTweetsByUser("realDonaldTrump", true, 15);
    std::cout << userTweets << std::endl;

    exit(0);
}