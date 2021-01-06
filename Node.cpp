/* -----------------------------------------------------------------------------
 *
 * File Name:  Node.cpp
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 4
 * Description:  Excercise in node, stack, and queue implementation
 * Date: 09/27/2020
 *
 ---------------------------------------------------------------------------- */
 
template <typename T>
Node<T>::Node(T entry)
{
	m_entry = entry;
	m_right = nullptr;
	m_left = nullptr;
}

//edit
template <typename T>
T Node<T>::getEntry() const
{
	return(m_entry);
}

//edit
template <typename T>
void Node<T>::setEntry(T entry)
{
	m_entry = entry;
}

template <typename T>
Node<T>* Node<T>::getRight() const
{
	return(m_right);
}

template <typename T>
Node<T>* Node<T>::getLeft() const
{
	return(m_left);
}

template <typename T>
void Node<T>::setRight(Node<T>* next)
{
	m_right = next;
}

template <typename T>
void Node<T>::setLeft(Node<T>* next)
{
	m_left = next;
}