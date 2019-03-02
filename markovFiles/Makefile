CXX = g++
CXXFLAGS = -g -std=c++14


%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

all: testMarkov.exe

testMarkov.exe: testMarkov.o markov.o word.o
	$(CXX) -o $@ $^

clean: 
	$(RM) *.o *.exe
