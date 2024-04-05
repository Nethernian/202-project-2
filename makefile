CXX = g++
CXXFLAGS = -Wall

proj2: Ship.h Pirate.o Game.o proj2.cpp
	$(CXX) $(CXXFLAGS) Pirate.o Game.o proj2.cpp -o proj2

Game.o: Ship.h Pirate.o Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

Pirate.o: Pirate.h Pirate.cpp Ship.h
	$(CXX) $(CXXFLAGS) -c Pirate.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./proj2
