#ifndef BST_H
#define BST_H

#include "BinarySearchTreeInterface.h"
#include "Node.h"
#include "pokemon.h"
#include <stdexcept>
#include <iostream>

template <typename ItemType, typename KeyType>
class bst : public BinarySearchTreeInterface <ItemType, KeyType>
{
	private:
		Node<ItemType>* m_root;
		ItemType recSearch(KeyType key, Node<ItemType>* subtree) const;
		void recAdd(ItemType entry, Node<ItemType>* subtree);
	
	public:
	
		/** 
		* @pre None
		* @post binary search tree is constructed
		* @param None
		* @throw None
		**/
		bst();
		
		/** 
		* @pre None
		* @post entry is added to binary search tree
		* @param entry
		* @throw std::runtime_error if duplicate added
		**/
		void add(ItemType entry); //throws std::runtime_error if duplicate added
		
		/** 
		* @pre None
		* @post returns pokemon object with key
		* @param key, unique number used to find pokemon
		* @throw std::runtime_error if not in tree
		**/
		ItemType search(KeyType key) const; //throws std::runtime_error if not in tree
		
		/** 
		* @pre None
		* @post deletes entire binary search tree
		* @param None
		* @throw None
		**/
		void clear(); //Empties the tree
		
		/** 
		* @pre None
		* @post recursively clears tree
		* @param subtree, subtree passed into function
		* @throw None
		**/
		void clear(Node<ItemType>* subtree);
		
		/** 
		* @pre None
		* @post finds minimum value in subtree passed in
		* @param curr, node passed in
		* @throw None
		**/
		Node<ItemType>* minimumKey(Node<ItemType>* curr); // finds minimum value in a subtree
		
		/** 
		* @pre None
		* @post finds parent of curr
		* @param tree, node whose parent needs to be found
		* @param subtree, recursively assigned to different nodes until parent is found
		* @throw None
		**/
		Node<ItemType>* FindParent(Node<ItemType>* tree, Node<ItemType>* subtree);
		
		/** 
		* @pre None
		* @post removes node with key
		* @param key, unique number used to find pokemon
		* @throw std::runtime_error if not in tree
		**/
		void remove(KeyType key); //throws std::runtime_error if not in tree
		
		/** 
		* @pre None
		* @post removes node with key
		* @param key, unique number used to find pokemon
		* @param subtree, recursively assigned to different nodes until parent is found
		* @throw None
		**/
		void remove(KeyType key, Node<ItemType>* subtree);
		
		/** 
		* @pre None
		* @post prints contents of entry
		* @param entry, node passed in
		* @throw None
		**/
		static void print(ItemType entry);
		
		//For the following methods, each method will take a function as a parameter
		//These function then call the provided function on every entry in the tree in the appropriate order (i.e. pre, in, post)
		//The function you pass in will need to a static method
		
		/** 
		* @pre None
		* @post visits nodes in binary tree in pre order
		* @param visit, function to be performed at every node
		* @throw None
		**/
		void visitPreOrder(void visit(ItemType entry)) const; //Visits each node in pre order
		
		/** 
		* @pre None
		* @post visits nodes in binary tree in in order
		* @param visit, function to be performed at every node
		* @throw None
		**/
		void visitInOrder(void visit(ItemType entry)) const; //Visits each node in in order
		
		/** 
		* @pre None
		* @post visits nodes in binary tree in post order
		* @param visit, function to be performed at every node
		* @throw None
		**/
		void visitPostOrder(void visit(ItemType entry)) const; //Visits each node in post order
		
		/** 
		* @pre None
		* @post visits nodes in binary tree in pre order
		* @param visit, function to be performed at every node
		* @param subtree, recursively assigned to different nodes until parent is found
		* @throw None
		**/
		void preOrder (void visit(ItemType entry), Node<ItemType>* subtree) const;
		
		/** 
		* @pre None
		* @post visits nodes in binary tree in in order
		* @param visit, function to be performed at every node
		* @param subtree, recursively assigned to different nodes until parent is found
		* @throw None
		**/
		void inOrder (void visit(ItemType entry), Node<ItemType>* subtree) const;
		
		/** 
		* @pre None
		* @post visits nodes in binary tree in post order
		* @param visit, function to be performed at every node
		* @param subtree, recursively assigned to different nodes until parent is found
		* @throw None
		**/
		void postOrder(void visit(ItemType entry), Node<ItemType>* subtree) const;
};
#include "bst.cpp"
#endif