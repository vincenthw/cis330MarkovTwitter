CXX = g++
CFLAGS = -g -std=c++14


%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

all: testMarkov.exe

testMarkov.exe: testMarkov.o markov.o
	$(CXX) -o $@ $^

clean: 
	$(RM) *.o *.exe