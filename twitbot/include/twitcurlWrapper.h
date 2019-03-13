#ifndef TWITCURLWRAPPER_HPP
#define TWITCURLWRAPPER_HPP

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

    // Returns true if username is valid, false otherwise
    bool isValidUsername(std::string username);

private:

    // remove twitter links from string
    std::string cleanText(std::string input);
};

#endif