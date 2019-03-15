#include "commandLineIO.hpp"
#include <experimental/filesystem>

bool is_alphanum(string &str) {
    return (str.find_first_not_of("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos);
}

string getInputSearch(TwitcurlWrapper twitWrapper) {
    string query;
    bool running = true;
    while (running) {
        cout << "Enter a search query: ";
        getline(cin, query);

        if (!is_alphanum(query)) {
            cout << "Invalid character. Alphanumeric only." << endl;
            continue;
        } else {
            running = false;
        }
    }
    return twitWrapper.searchTwitter(query, 100);
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

string getInputTextFile(TwitcurlWrapper twitWrapper) {
    
    cout << "Select file to read from:" << endl;

    namespace fs = std::experimental::filesystem;
    
    string path = "./text_files/";
    vector<string> filePaths;
    string file;

    int i = 0;
    for (const auto & entry : fs::directory_iterator(path)) {
        file = entry.path();
        cout << "[" << i << "] -- " << file << endl;
        filePaths.push_back(entry.path());
        i++;
    }

    string result;
    while (true) {
        cout << "Make selection: ";
        string choice;
        getline(cin, choice);
        cout << endl;
        int numChoice;
        try {
            numChoice = stoi(choice);
        } catch (...) {
            continue;
        }
        if (0 <= numChoice && static_cast<unsigned int>(numChoice) < filePaths.size()) {
            return filePaths.at(numChoice);
        }
    }
}

int getNumSentences() {
    string choice;
    int numChoice;
    while (true) {
        cout << "How many sentences would you like to generate?: ";
        getline(cin, choice);
        cout << endl;
        try {
            numChoice = stoi(choice);
        } catch (...) {
            continue;
        }
        return numChoice;
    }
}