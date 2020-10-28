CXX = g++
CXXFLAGS = -Wall -g
PROGNAME = main

main: clean main.o matrix.o
	$(CXX) $(CXXFLAGS) -o $(PROGNAME) main.o matrix.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

matrix.o: matrix.cpp
	$(CXX) $(CXXFLAGS) -c matrix.cpp

clean:
	rm -rf *.o
	rm -rf $(PROGNAME)