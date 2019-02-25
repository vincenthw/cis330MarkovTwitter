#include "twitterTest.h"
#include <iostream>
#include "json/json.h"
#include <fstream>

int main()
{
    twitCurl twitterObj;
    std::string consumerKey("pIPeKJqCtW2bXkc5DnbFq039Z");
    std::string consumerSecret("DBahC1k4gkuGEAWlcrsglqUyce2piIPU1XRDdwSlQYTQc5gzMv");

    twitterObj.getOAuth().setConsumerKey(consumerKey);
    twitterObj.getOAuth().setConsumerSecret(consumerSecret); // Consumer keys taken from developer.twitter.com/apps

    /* This code only neccessary to run the first time to get TokenKey and TokenSecret */
    // twitterObj.setTwitterUsername("330twitbot"); // Twitter account user
    // twitterObj.setTwitterPassword("camnewt"); // Twitter account pass

    // std::string authUrl;
    // twitterObj.oAuthRequestToken(authUrl);
    // twitterObj.oAuthHandlePIN(authUrl);

    // twitterObj.oAuthAccessToken();

    // std::string oAuthTokenKey, oAuthTokenSecret;
    // twitterObj.getOAuth().getOAuthTokenKey(oAuthTokenKey);
    // twitterObj.getOAuth().getOAuthTokenSecret(oAuthTokenSecret);
    // std::cout << oAuthTokenKey << std::endl; // print the TokenKey and SecretKeys
    // std::cout << oAuthTokenSecret << std::endl << std::endl;

    twitterObj.getOAuth().setOAuthTokenKey("1098008012168417280-LSttNTRIxCV9IVqaEM0RAgOrfaHimr"); // Taken from the print statements above
    twitterObj.getOAuth().setOAuthTokenSecret("BXF0UrWC7ulUG1R6gFCdW4ifvKBusmH1B1RsFA96Txc9B");

    std::string replyMsg;
    if (twitterObj.accountVerifyCredGet()) // if account credentials are valid
    {
        twitterObj.search("nba", "10"); // Get 50 nba tweets
        twitterObj.getLastWebResponse(replyMsg); //set replyMsg to the twitCurl reponse
        printf("\ntwitterClient:: twitCurl::accountVerifyCredGet web response:\n%s\n", replyMsg.c_str());

        //Parse Json data so specific fields can be accessed
        Json::Reader reader;
        Json::Value val;
        reader.parse(replyMsg, val);

        //Create Writer to write text to tweetText.txt to be passed to Markov chain
        std::ofstream outfile("tweetText.txt");

        for(int i=0; i < 10; i++){ //Have to loop to extract from multiple tweets
            outfile << val["statuses"][i]["text"] << std::endl; //Format to access text is map, array, map
        }
        outfile.close();


    }
    else
    {
        twitterObj.getLastCurlError(replyMsg);
        printf("\ntwitterClient:: twitCurl::accountVerifyCredGet error:\n%s\n", replyMsg.c_str());
    }

    return 0;
}
