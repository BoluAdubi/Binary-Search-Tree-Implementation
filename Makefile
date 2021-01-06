prog: main.o executive.o pokemon.o
	g++ -std=c++11 -g -Wall main.o executive.o pokemon.o -o prog

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp
	
executive.o: executive.h executive.cpp 
	g++ -std=c++11 -g -Wall -c executive.cpp
	
bst.o: bst.h bst.cpp bstInterface.h node.h node.cpp
	g++ -std=c++11 -g -wall -c bst.cpp
	
pokemon.o: pokemon.h pokemon.cpp 
	g++ -std=c++11 -g -Wall -c pokemon.cpp
	
clean:
	rm *.o prog