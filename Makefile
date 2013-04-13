CXXFLAGS=-std=gnu++11
#CXXFLAGS=-std=c++11 

all: test 

test: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp  -o test
calc: calc5.cpp
	$(CXX) $(CXXFLAGS) calc5.cpp -o calc -I../boost_explore/spirit/
clean:
	rm -f *.o test calc
