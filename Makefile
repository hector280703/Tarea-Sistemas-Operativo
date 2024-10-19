CXX = g++
CXXFLAGS = -std=c++11 -pthread

all: carrera

carrera: carrera.o
	$(CXX) $(CXXFLAGS) -o carrera carrera.o

carrera.o: carrera.cpp
	$(CXX) $(CXXFLAGS) -c carrera.cpp

clean:
	rm -f *.o carrera
