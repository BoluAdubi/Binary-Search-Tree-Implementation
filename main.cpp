#include <iostream>
#include "executive.h"

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		std::cout << "Incorrect number of parameters!\n";
	}
	else
	{
		std::string inputFile = argv[1];
		executive exec(inputFile);
		exec.run();
	}
	
	return(0);
}
