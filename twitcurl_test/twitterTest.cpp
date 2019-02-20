#include "twitterTest.h"

int main()
{
    twitCurl twitterObj;
    std::string consumerKey("");
    std::string consumerSecret("");

    twitterObj.getOAuth().setConsumerKey("KT0dbqBaPOjJNFobv09bAFwro");
    twitterObj.getOAuth().setConsumerSecret("ChSGqvuccPdOxuc4N6sTTqs7nwxWJtbfrrv9DVXPfKfQuvjktj"); // Consumer keys taken from developer.twitter.com/apps

    
    /* This code only neccessary to run the first time to get TokenKey and TokenSecret */
    // twitterObj.setTwitterUsername("INSERT_USERNAME_HERE"); // Twitter account user
    // twitterObj.setTwitterPassword("INSERT_PASSWORD_HERE"); // Twitter account pass

    // std::string authUrl;
    // twitterObj.oAuthRequestToken(authUrl);
    // twitterObj.oAuthHandlePIN(authUrl);

    // twitterObj.oAuthAccessToken();

    // std::string oAuthTokenKey, oAuthTokenSecret;
    // twitterObj.getOAuth().getOAuthTokenKey(oAuthTokenKey);
    // twitterObj.getOAuth().getOAuthTokenSecret(oAuthTokenSecret);
    // std::cout << oAuthTokenKey << std::endl; // print the TokenKey and SecretKeys
    // std::cout << oAuthTokenSecret << std::endl << std::endl;

    twitterObj.getOAuth().setOAuthTokenKey("2554059522-W2hCWOugcPYjf15vCqoUfamWWlfOn1HNcE7Ehbp"); // Taken from the print statements above
    twitterObj.getOAuth().setOAuthTokenSecret("MvS8YSMuphpgVNjPRnzuJOP1cxcczJXwjY7cyc0ZDItM3");

    std::string replyMsg;
    if (twitterObj.accountVerifyCredGet()) // if account credentials are valid
    {
        twitterObj.search("nba", "50"); // Get 50 nba tweets
        twitterObj.getLastWebResponse(replyMsg); //set replyMsg to the twitCurl reponse
        printf("\ntwitterClient:: twitCurl::accountVerifyCredGet web response:\n%s\n", replyMsg.c_str());
    }
    else
    {
        twitterObj.getLastCurlError(replyMsg);
        printf("\ntwitterClient:: twitCurl::accountVerifyCredGet error:\n%s\n", replyMsg.c_str());
    }

    return 0;
}