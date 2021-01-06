#include "pokemon.h"

pokemon::pokemon()
{
	m_usName = " ";
	m_japName = " ";
	m_ID = 0;
}

std::string pokemon::getUSName() const
{
	return(m_usName);
}

void pokemon::setUSName(std::string name)
{
	m_usName = name;
}

std::string pokemon::getJapName() const
{
	return(m_japName);
}

void pokemon::setJapName(std::string name)
{
	m_japName = name;
}

int pokemon::getID() const
{
	return(m_ID);
}

void pokemon::setID(int ID)
{
	m_ID = ID;
}

//operator overloading
bool pokemon::operator==(int rhsID) const
{
	if(m_ID == rhsID) 
	{
		return(true);
	}
	else 
	{
		return(false);
	}
}
bool pokemon::operator>(int rhsID) const
{
	if(m_ID > rhsID)
	{
		return(true);
	}
	else 
	{
		return(false);
	}
}
bool pokemon::operator==(const pokemon& rhs) const
{
	if(m_ID == rhs.m_ID)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}
bool pokemon::operator>(const pokemon& rhs) const
{
	if(m_ID > rhs.m_ID)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}