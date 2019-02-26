#include "twitcurl.h"
#include "json/json.h"

class TweetSearch : public twitCurl
{
public:
    TweetSearch();

    // Use query to search for number of tweets
    std::string searchTwitter(std::string query, int numTweets);
    std::string getTweetsByUser(std::string username, bool includeRetweets, int numTweets); 
private:
    std::string parseJson(Json::Value val, int numTweets);
};