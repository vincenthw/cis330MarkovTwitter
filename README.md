# CIS330ProjectW19


#About 
Uses the Twitter API to pull tweets from one or more user selected twitter accounts or a twitter search then feeds them into a Markov Chain. The Markov Chain then generates its own tweet based the word usage/frequency of its data.

#Installation
##Install libcurl4 

dependency: libcurl4

for Ubuntu:

`sudo apt install libcurl4-openssl-dev`

for Arch:

`pacman -Ql curl | grep /usr/lib/libcurl`

##Installation script

The installation script compiles and installs the libtwitcurl library (github.com/theryangeary/twitcurl/), then compiles our code base.

`./install.sh`

Note: may need `sudo` to access `/usr/lib`

#Run Program
The program can be used in two ways:


1. command line interface (CLI)


2. python flask webserver (accessed via a web browser at localhost:5000)

##CLI
To run the CLI:

`./bot.exe`

##Web Interface
To run the flask webserver:
`python3 os_test/index.py`

Then access the webpage at:
localhost:5000

##Known Bugs
1. Due to the age of the twitcurl library for the Twitter API, the only api available for c++ we could find, there are many new features to twitter that interact poorly with it. We noted some bugs that we believe to be caused by this.


2. When using the webpage version of the program if you do a keyword category search, 90% of the time we recieved a out of bounds error the other 10% of the time it randomly works.

3. Posting the tweets, via the statusUpdate() function in the twitcurl library, is inconsistant. It worked consistantly for about 30 posts and then started returning a success indicator without ever posting the tweet to the account.