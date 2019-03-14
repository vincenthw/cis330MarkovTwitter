#include "commandLineIO.hpp"

// Function to prompt users for search queries that will be used in markov chain
string getInputSearch(TwitcurlWrapper twitWrapper) {
    string search = "";

    while (search == "") {
        cout << "Please insert a category of interest: ";
        cin >> search;
        if (search[0] == '#') {
            cout << "You can not enter hashtags for your search" << endl;
            cin.ignore(1000000, '\n');
            cin.clear();
            search = "";
        }
    }

    if (search != "") {
        if (search[0] != '#') {
            // uses twitter "search" functionality
            string searchTweets = twitWrapper.searchTwitter(search, 1);
            cout << searchTweets << endl;
        }
    }
}

// Function to prompt user for twitter usernames that will be used in markov chain
string getInputUsernames(TwitcurlWrapper twitWrapper) {
    string username;
    bool running = true;
    string combinedTweets;

OUTER:

    while (running) {
        cout << "Enter a twitter username: ";
        getline(cin, username);

        cout << "checking valid: " << username << endl;

        if (username.empty() || !twitWrapper.isValidUsername(username)) {
            cout << "Invalid username, try again." << endl;
            continue;
        }

        combinedTweets.append(twitWrapper.getTweetsByUser(username, 200, true));
        // cout << "Added " << username << "'s last 200 tweets to the markov chain generation. " << endl;

        while (running) {
            string input;

            cout << "Add another user [Y/n]? ";
            getline(cin, input);

            if (toupper(input[0]) == 'Y') {
                goto OUTER;

            } else if (toupper(input[0]) == 'N') {
                running = false;
            }
        }
    }

    return combinedTweets;
}