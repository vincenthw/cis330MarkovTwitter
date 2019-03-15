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
    ..* command line interface (CLI)
    ..* python flask webserver (accessed via a web browser at localhost:5000)

##CLI
To run the CLI:

`./bot.exe`

##Web Interface
To run the flask webserver:
`python3 os_test/index.py`

Then access the webpage at:
localhost:5000