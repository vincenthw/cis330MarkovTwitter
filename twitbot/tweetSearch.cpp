#include "tweetSearch.h"
#include <iostream>
#include <fstream>
#include <string>

TweetSearch::TweetSearch() : twitCurl()
{
    std::string consumerKey("pIPeKJqCtW2bXkc5DnbFq039Z");
    std::string consumerSecret("DBahC1k4gkuGEAWlcrsglqUyce2piIPU1XRDdwSlQYTQc5gzMv");
    getOAuth().setConsumerKey(consumerKey);
    getOAuth().setConsumerSecret(consumerSecret);

    getOAuth().setOAuthTokenKey("1098008012168417280-LSttNTRIxCV9IVqaEM0RAgOrfaHimr");
    getOAuth().setOAuthTokenSecret("BXF0UrWC7ulUG1R6gFCdW4ifvKBusmH1B1RsFA96Txc9B");
}

std::string TweetSearch::parseJson(Json::Value val, int numTweets)
{
    std::string parsedString, tweetText;
    for (int i=0; i<numTweets; i++)
    {
        tweetText = val["statuses"][i]["text"].asString();
        parsedString.append(tweetText);
    }

    return parsedString;
}

std::string TweetSearch::searchTwitter(std::string query, int numTweets)
{
    std::string n = std::to_string(numTweets); // convert int to string because twitcurl argument is a string for some reason
    search(query, n);

    std::string reply;
    getLastWebResponse(reply); // store the response in reply string
    
    Json::Reader reader;
    Json::Value val;
    reader.parse(reply, val);

    return parseJson(val, numTweets);
}

std::string TweetSearch::getTweetsByUser(std::string username, bool includeRetweets, int numTweets)
{
    timelineUserGet(false, includeRetweets, numTweets, username, false);

    std::string reply;
    getLastWebResponse(reply);

    return reply;

    // Json::Reader reader;
    // Json::Value val;
    // reader.parse(reply, val);

    // return parseJson(val, numTweets);
}