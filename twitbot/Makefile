CC = g++
INCLUDE = -Iinclude
LIBS = -Lbin -lcurl -ltwitcurl
CFLAGS = -Wall -g -std=c++14
SRC = $(wildcard *.cpp)


# all: $(SRC)
# 	$(CC) $(SRC) $(CFLAGS) $(LIBS) $(INCLUDE) -o bot.exe

main: twitcurlWrapper.cpp twitbotDriver.cpp markov.cpp
	$(CC) twitcurlWrapper.cpp twitbotDriver.cpp markov.cpp $(CFLAGS) $(LIBS) $(INCLUDE) -o bot.exe

web: twitcurlWrapper.cpp wepage_driver.cpp markov.cpp
	$(CC) twitcurlWrapper.cpp wepage_driver.cpp markov.cpp $(CFLAGS) $(LIBS) $(INCLUDE) -o webbot.exe


testMarkov.exe: testMarkov.cpp markov.cpp
	$(CC) markov.cpp testMarkov.cpp $(CFLAGS) $(INCLUDE) -o testMarkov.exe