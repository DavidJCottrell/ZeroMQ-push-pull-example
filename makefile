CXX = g++
CXXFLAGS = -Wall
LDFLAGS = -lzmq

all: pull push

pull: pull.cpp
	$(CXX) $(CXXFLAGS) -o pull pull.cpp $(LDFLAGS)

push: push.cpp
	$(CXX) $(CXXFLAGS) -o push push.cpp $(LDFLAGS)

clean:
	rm pull && rm push