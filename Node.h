/* -----------------------------------------------------------------------------
 *
 * File Name:  Node.h
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 4
 * Description:  Excercise in node, stack, and queue implementation
 * Date: 09/27/2020
 *
 ---------------------------------------------------------------------------- */

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
	private:
		T m_entry;
		Node<T>* m_right;
		Node<T>* m_left;
	
	public:
	
		/** 
		* @pre None
		* @post new node is created
		* @param entry, what the node stores
		* @throw None
		**/
		Node(T entry);
		
		/** 
		* @pre None
		* @post object in node is returned
		* @param None
		* @throw None
		**/
		T getEntry() const;
		
		/** 
		* @pre None
		* @post value in node is set
		* @param entry, value the node stores
		* @throw None
		**/
		void setEntry(T entry);
		
		/** 
		* @pre None
		* @post returns value right pointer points at
		* @param None
		* @throw None
		**/
		Node<T>* getRight() const;
		
		
		/** 
		* @pre None
		* @post returns value left pointer points at
		* @param None
		* @throw None
		**/
		Node<T>* getLeft() const;
		
		/** 
		* @pre None
		* @post assigns right pointer to next
		* @param next, value assigned to right pointer
		* @throw None
		**/
		void setRight(Node<T>* next);
		
		/** 
		* @pre None
		* @post assigns left pointer to next
		* @param next, value assigned to left pointer
		* @throw None
		**/
		void setLeft(Node<T>* next);

};

#include "Node.cpp"
#endif