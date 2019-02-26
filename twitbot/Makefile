CC = g++
INCLUDE = -Iinclude
LIBS = -lcurl -ltwitcurl
CFLAGS = -Wall -Lbin
SRC = $(wildcard *.cpp)


all: $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LIBS) $(INCLUDE) -o bot.exe

main: jsoncpp.cpp tweetSearch.cpp twitbotDriver.cpp
	$(CC) jsoncpp.cpp tweetSearch.cpp twitbotDriver.cpp $(CFLAGS) $(LIBS) $(INCLUDE) -o bot.exe