#include "twitcurl.h"

// See twitcurlWrapper.cpp for detailed function documentation
class TwitcurlWrapper : public twitCurl
{
public:
    TwitcurlWrapper();

    // Use query to search for number of tweets
    std::string searchTwitter(std::string query, int numTweets);

    // Get recent tweets by specific twitter user
    std::string getTweetsByUser(std::string username, int numTweets, bool includeRetweets); 

private:

    // remove twitter links from string
    std::string removeTwitterLinks(std::string input);
};