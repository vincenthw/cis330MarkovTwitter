# CIS330ProjectW19


#About 
Using the Twitcurl library, the program takes 200 tweets from one or more user selected twitter accounts or a twitter search then loads them into a Markov Chain. Using the Markov Chain it then generates its own tweet based on the user or search and uses the twitcurl library to tweet to the account @330Twitbot

#Install libcurl4 

dependency: libcurl4

for Ubuntu:

`sudo apt install libcurl4-openssl-dev`

for Arch:

`pacman -Ql curl | grep /usr/lib/libcurl`

#Install libcurl

run installation script (install.sh):

`./install.sh`

Note: may need `sudo` to access `/usr/lib`

#Run CLI

`./bot.exe`