CC = g++
INCLUDE = -Iinclude
LIBS = -Lbin -lcurl -ltwitcurl -lstdc++fs
CFLAGS = -Wall -g -std=c++14
SRC = $(wildcard *.cpp)

all: main web

main: twitcurlWrapper.cpp twitbotDriver.cpp markov.cpp word.cpp commandLineIO.cpp
	$(CC) twitcurlWrapper.cpp twitbotDriver.cpp markov.cpp word.cpp commandLineIO.cpp $(CFLAGS) $(LIBS) $(INCLUDE) -o ../bot.exe

web: twitcurlWrapper.cpp webpageDriver.cpp markov.cpp word.cpp
	$(CC) twitcurlWrapper.cpp webpageDriver.cpp markov.cpp word.cpp $(CFLAGS) $(LIBS) $(INCLUDE) -o web_bot.exe
