#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include "Node.h"
#include "bst.h"
#include "pokemon.h"
#include <iostream>
#include <fstream>

class executive
{
	private:
		std::string m_fileName;
	
	public:
		/** 
       * @pre None
       * @post Executive object is created
       * @param Input file name
       * @throw None
       **/
		executive(std::string file);
		
		/** 
       * @pre User must have provided a file
       * @post filename is returned
       * @param None
       * @throw None
       **/
		std::string getFileName();
		
		/** 
       * @pre User must have provided a file
       * @post returns true if file is open and false if it isnt
       * @param None
       * @throw std::runtime error if no file has been provided
       **/
		bool isFileOpen();
		
		/** 
       * @pre None
       * @post Menu is displayed
       * @param None
       * @throw None
       **/		
		void printMenu();
		
		/** 
       * @pre None
       * @post executive is run
       * @param None
       * @throw None
       **/
		void run();
};
#endif