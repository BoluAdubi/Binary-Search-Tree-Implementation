#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class pokemon
{
	private:
		std::string m_usName;
		std::string m_japName;
		int m_ID; // key
	
	public:
		/** 
		* @pre None
		* @post new pokemon object is created
		* @param None
		* @throw None
		**/
		pokemon();
	
		/** 
		* @pre None
		* @post returns pokemon USName
		* @param None
		* @throw None
		**/
		std::string getUSName() const;
		
		/** 
		* @pre None
		* @post 
		* @param name, string USName is set to
		* @throw None
		**/
		void setUSName(std::string name);
		
		/** 
		* @pre None
		* @post returns pokemon JapName
		* @param None
		* @throw None
		**/
		std::string getJapName() const;
		
		/** 
		* @pre None
		* @post 
		* @param name, string JapName is set to
		* @throw None
		**/
		void setJapName(std::string name);
		
		/** 
		* @pre None
		* @post returns pokemon ID
		* @param None
		* @throw None
		**/
		int getID() const;
		
		/** 
		* @pre None
		* @post 
		* @param ID, int m_ID is set to
		* @throw None
		**/
		void setID(int ID);
		
		// operator overloading
		// search
		bool operator==(int rhsID) const;
		bool operator>(int rhsID) const;
		// add
		bool operator==(const pokemon& rhs) const;
		bool operator>(const pokemon& rhs) const;
};
#endif