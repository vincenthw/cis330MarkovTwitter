#include "twitcurlWrapper.h"
#include "include/json.hpp"
#include <iostream>
#include <fstream>
#include <string>

/*
* TwitcurlWrapper::TwitcurlWrapper
* Default constructor. Initializes authentication keys, based on keys obtained for twitter acount "330twitbot"
*/
TwitcurlWrapper::TwitcurlWrapper() : twitCurl()
{
    std::string consumerKey("pIPeKJqCtW2bXkc5DnbFq039Z");
    std::string consumerSecret("DBahC1k4gkuGEAWlcrsglqUyce2piIPU1XRDdwSlQYTQc5gzMv");
    getOAuth().setConsumerKey(consumerKey);
    getOAuth().setConsumerSecret(consumerSecret);

    getOAuth().setOAuthTokenKey("1098008012168417280-LSttNTRIxCV9IVqaEM0RAgOrfaHimr");
    getOAuth().setOAuthTokenSecret("BXF0UrWC7ulUG1R6gFCdW4ifvKBusmH1B1RsFA96Txc9B");
}


/*
* TwitcurlWrapper::cleanText
* removes links of format "https://t.co/xxxxxxxxxx" from input string, replacing them with a space (" ")
*
* parameters:   input - string to remove links from
*
* output:       string with links removed
*/
std::string TwitcurlWrapper::cleanText(std::string input)
{
    // all twitter links start with this string
    std::string searchString = "https://t.co/";

    std::size_t found = input.find(searchString);

    // while searchString is found in input
    while (found != std::string::npos)
    {
        // input.erase(found, 23);

        // all twitter links have length 23
        input.replace(found, 23, " "); 
        found = input.find(searchString);
    }

    // Do the same thing, but  replace "&amp;" with "&"
    searchString = "&amp;";
    found = input.find(searchString);

    while (found != std::string::npos)
    {
        input.replace(found, 5, "&");
        found = input.find(searchString);
    }

    return input;
}


/*
* TwitcurlWrapper::searchTwitter ////// Not complete and needs improvement. See notes/documentation.txt for details.
*
* parameters:   query - search query
*               numTweets - the number of tweets to get (max 100, default 15)
*
* output:       string containing all of the tweets
*/
std::string TwitcurlWrapper::searchTwitter(std::string query, int numTweets) //int numTweets
{
    if (numTweets > 100) numTweets = 100;

    // convert int to string because twitcurl argument is a string for some reason
    std::string n = std::to_string(numTweets);
    search(query, n);

    std::string reply;

    // store the response in reply string
    getLastWebResponse(reply);

    // parse reply json
    nlohmann::json parsedReply = nlohmann::json::parse(reply)["statuses"];
    //std::cout << reply << std::endl; // output raw response json, for debugging

    std::string combinedTweets = "";
    for (nlohmann::json::iterator it = parsedReply.begin(); it != parsedReply.end(); it++)
    {
        // if tweet is a RT, JSON format is different
        if ((*it)["retweeted_status"] != nullptr)
        {
            combinedTweets.append((*it)["retweeted_status"]["text"]);
            combinedTweets.append(" ");
        }
        else
        {
            combinedTweets.append((*it)["text"]);
            combinedTweets.append(" ");
        }
    }

    combinedTweets = cleanText(combinedTweets);

    return combinedTweets;
}


/*
* TwitcurlWrapper::getTweetsByUser
*
* parameters:   username - twitter username of account to get tweets from
*               numTweets - the number of tweets to get (max 200)
*               includeRetweets - include retweets if true
*
* output:       string containing all of the tweets
*/
std::string TwitcurlWrapper::getTweetsByUser(std::string username, int numTweets, bool includeRetweets)
{
    if (numTweets > 200) numTweets = 200;

    timelineUserGet(false, includeRetweets, numTweets, username, false, true);
    
    std::string reply;

    // store the response in reply string
    getLastWebResponse(reply);
    // std::cout << reply << std::endl; // output raw response json, for debugging

    // parse reply json
    nlohmann::json parsedReply = nlohmann::json::parse(reply);

    std::string combinedTweets = "";
    for (nlohmann::json::iterator it = parsedReply.begin(); it != parsedReply.end(); it++)
    {
        // if tweet is a RT, JSON format is different
        if ((*it)["retweeted_status"] != nullptr)
        {
            combinedTweets.append((*it)["retweeted_status"]["full_text"]);
            combinedTweets.append(" ");
        } 
        else
        {
            combinedTweets.append((*it)["full_text"]);
            combinedTweets.append(" ");
        }
    }

    combinedTweets = cleanText(combinedTweets);

    std::cout << "Retrieved " << username << "'s last " << parsedReply.size() << " tweets." << std::endl;

    return combinedTweets;
    // return reply;
}


/*
* TwitcurlWrapper::isValidUsername
* Check if username is a valid twitter account
*
* parameters:   username - twitter username of account to get tweets from
*
* output:       true if valid, false otherwise
*/
bool TwitcurlWrapper::isValidUsername(std::string username)
{
    userGet(username);
    std::string reply;
    getLastWebResponse(reply);

    // parse reply json
    nlohmann::json parsedReply = nlohmann::json::parse(reply);

    // parsedReply will have an errors field if the username is invalid
    if (parsedReply["errors"] != nullptr) {return false;}
    return true;
}