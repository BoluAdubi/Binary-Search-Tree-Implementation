#include "executive.h"

executive::executive(std::string file)
{
	m_fileName = file;
}

std::string executive::getFileName()
{
	return(m_fileName);
}

bool executive::isFileOpen()
{
	std::string file = getFileName();
	
	std::ifstream myInFile;
	myInFile.open(file);
	
	if (myInFile.is_open())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void executive::printMenu()
{
	std::cout << "\n";
	std::cout << "Menu Options\n";
	std::cout << "1) Search\n";
	std::cout << "2) Add\n";
	std::cout << "3) Copy\n";
	std::cout << "4) Remove\n";
	std::cout << "5) Print\n";
	std::cout << "6) Quit\n";
	std::cout << "Number selection: ";
}

void executive::run()
{
	std::ifstream myInFile;
	myInFile.open(m_fileName);
	
	bool fileStatus = isFileOpen();
	
	std::string userChoice = " ";
	std::string tempUS;
	int tempID;
	std::string tempJP;
	
	bst<pokemon, int> pokemonTree;
	
	// create pokemon binary search tree
	if(fileStatus == true)
	{		
		pokemon temp;
		while(myInFile >> tempUS >> tempID >> tempJP)
		{
			temp.setUSName(tempUS);
			temp.setID(tempID);
			temp.setJapName(tempJP);
			
			pokemonTree.add(temp);
		}
		
		// user stuff
	do
		{
			printMenu();
			std::cin >> userChoice;
			
			if(userChoice == "1")
			{
				int pokemonKey = 0;
				
				std::cout << "what Pokedex number would you like to search for: ";
				std::cin >> pokemonKey;
				
				pokemon searchResult;
				try
				{
					searchResult = pokemonTree.search(pokemonKey);
					
					// output
					std::cout << "\nID: " << searchResult.getID() << "\n";
					std::cout << "US Name: " << searchResult.getUSName() << "\n";
					std::cout << "Japanese Name: " << searchResult.getJapName() << "\n\n";
				}
				catch(std::runtime_error &rte)
				{
					std::cout << rte.what() << "\n";
				}
			}
			else if(userChoice == "2")
			{
				pokemon newPoke;
				std::string usName;
				std::string japName;
				int id;
				
				
				std::cout << "Enter Pokemon name (US): ";
				std::cin >> usName;
				std::cout << "Enter Pokemon name (Japanese): ";
				std::cin >> japName;
				std::cout << "Enter Pokedex number: ";
				std::cin >> id;
				
				newPoke.setUSName(usName);
				newPoke.setID(id);
				newPoke.setJapName(japName);
				
				try
				{
					pokemonTree.add(newPoke);
				}
				catch(std::runtime_error &rte)
				{
					std::cout << rte.what() << "\n";
				}
			}
			else if(userChoice == "3")
			{
				
			}
			else if(userChoice == "4")
			{
				int pokemonKey = 0;
				
				std::cout << "what Pokedex number would you like to remove: ";
				std::cin >> pokemonKey;
				
				try
				{
					pokemonTree.remove(pokemonKey);
				}
				catch(std::runtime_error &rte)
				{
					std::cout << rte.what() << "\n";
				}
			}
			else if(userChoice == "5")
			{
				std::string traversalOrder;
				std::cout << "1) Pre Order\n";
				std::cout << "2) In Order\n";
				std::cout << "3) Post Order\n";
				std::cout << "what order would you like to print the pokedex: ";
				std::cin >> traversalOrder;
				
				if(traversalOrder == "1")
				{
					pokemonTree.visitPreOrder(bst<pokemon, int>::print);
				}
				else if(traversalOrder == "2")
				{
					pokemonTree.visitInOrder(bst<pokemon, int>::print);
				}
				else if(traversalOrder == "3")
				{
					pokemonTree.visitPostOrder(bst<pokemon, int>::print);
				}
			}
			
		}while(userChoice != "6");
	}
	else
	{
		std::cout << "Invalid file given \n";
	}	
}