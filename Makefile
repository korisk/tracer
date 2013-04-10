CXXFLAGS=-std=c++11 

all: test 

test: test.cpp
	$(CXX) test.cpp  -o test
calc: calc5.cpp
	$(CXX) calc5.cpp -o calc -I../boost_explore/spirit/
clean:
	rm -f *.o test calc
