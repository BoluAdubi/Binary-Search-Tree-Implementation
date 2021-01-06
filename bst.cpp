template <typename ItemType, typename KeyType>
bst<ItemType, KeyType>::bst()
{
	m_root = nullptr;
}

template <typename ItemType, typename KeyType>
ItemType bst<ItemType, KeyType>::recSearch(KeyType key, Node<ItemType>* subtree) const
{
	if(subtree == nullptr)
	{
		throw(std::runtime_error("Not found!"));
	}
	else if(subtree -> getEntry() == key)
	{
		return(subtree -> getEntry());
	}
	else if(subtree -> getEntry() > key)
	{
		return(recSearch(key, subtree -> getLeft()));
	}
	else
	{
		return(recSearch(key, subtree -> getRight()));
	}
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::recAdd(ItemType entry, Node<ItemType>* subtree)
{
	/*
	if(entry == subtree -> getEntry())// check for duplicates
	{
		throw(std::runtime_error("Duplicate Error"));
	}
	*/
	if(subtree -> getEntry() > entry)
	{
		if(subtree -> getLeft() == nullptr)
		{
			Node<ItemType>* newNode = new Node<ItemType>(entry);
			subtree -> setLeft(newNode);
		}
		else
		{
			recAdd(entry, subtree -> getLeft());
		}
	}
	else
	{
		if(subtree -> getRight() == nullptr)
		{
			Node<ItemType>* newNode = new Node<ItemType>(entry);
			subtree -> setRight(newNode);
		}
		else
		{
			recAdd(entry, subtree -> getRight());
		}
	}
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::add(ItemType entry)
{
	if(m_root == nullptr)
	{
		m_root = new Node<ItemType>(entry);
	}
	else
	{
		recAdd(entry, m_root);
	}
}

template <typename ItemType, typename KeyType>
ItemType bst<ItemType, KeyType>::search(KeyType key) const
{
	return(recSearch(key, m_root));
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::clear()
{
	clear(m_root);
	m_root = nullptr;
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::clear(Node<ItemType>* subtree)
{
	if(subtree == nullptr)
	{
		return;
	}
	else
	{
		clear(subtree->getLeft());
		clear(subtree->getRight());
		delete subtree;
	}
}

template <typename ItemType, typename KeyType>
Node<ItemType>* bst<ItemType, KeyType>::minimumKey(Node<ItemType>* curr)
{
	while(curr -> getLeft() != nullptr)
	{
		curr = curr -> getLeft();
	}
	return curr;
}

template <typename ItemType, typename KeyType>
Node<ItemType>* bst<ItemType, KeyType>::FindParent(Node<ItemType>* tree, Node<ItemType>* subtree)
{
	if(subtree == nullptr)
	{
		return(nullptr);
	}
	else if(subtree->getLeft() == nullptr && subtree->getRight() == nullptr)
	{
		return(nullptr);
	}
	else if((subtree->getRight() == tree) || (subtree->getLeft() == tree))
	{
		return(subtree);
	}
	else if(subtree->getEntry() > tree->getEntry())
	{
		return FindParent(tree,subtree->getLeft());
	}
	else if(!(subtree->getEntry() > tree->getEntry()) && !(subtree->getEntry() == tree->getEntry()))
	{
		return FindParent(tree ,subtree->getRight());
	}
	return(nullptr);
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::remove(KeyType key)
{
	remove(key, m_root);
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::remove(KeyType key, Node<ItemType>* subtree)
{
	if(subtree == nullptr)
	{
		throw(std::runtime_error("Not Found!"));
	}
	
	if(subtree -> getEntry() > key)
	{
		remove(key, subtree -> getLeft());
	}
	else if(!(subtree -> getEntry() > key) && !(subtree -> getEntry() == key))
	{
		remove(key, subtree -> getRight());
	}
	else if(subtree -> getEntry() == key)
	{
		// case 1: No children
		if((subtree -> getLeft() == nullptr) && (subtree -> getRight() == nullptr))
		{
			Node<ItemType>* temp = FindParent(subtree, m_root);
			
			if(temp -> getLeft() == subtree)
			{
				temp -> setLeft(nullptr);
			}
			else if(temp -> getRight() == subtree)
			{
				temp -> setRight(nullptr);
			}
			
			delete subtree;
		}
		// case 2: Two children
		else if((subtree -> getLeft() != nullptr) && (subtree -> getRight() != nullptr))
		{
			
			//Node<ItemType>* temp = FindParent(subtree, m_root);
			Node<ItemType>* replacement = minimumKey(subtree -> getRight()); // find leftmost node in right subtree
			
			pokemon a = replacement -> getEntry();
			int replacementKey = a.getID();
			
			remove(replacementKey);
			subtree -> setEntry(a);
		}
		// case 3: One child
		else
		{
			Node<ItemType>* temp = FindParent(subtree, m_root);
			
			if(temp -> getLeft() == subtree)
			{
				if(subtree -> getLeft() == nullptr)
				{
					temp -> setLeft(subtree -> getRight());
				}
				else if(subtree -> getRight() == nullptr)
				{
					temp -> setLeft(subtree -> getLeft());
				}
			}
			
			else if(temp -> getRight() == subtree)
			{
				if(subtree -> getLeft() == nullptr)
				{
					temp -> setRight(subtree -> getRight());
				}
				else if(subtree -> getRight() == nullptr)
				{
					temp -> setRight(subtree -> getLeft());
				}
			}
			
		}
	}
	
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::print(ItemType entry)
{
	std::cout << "\n";
	std::cout << "US Name: " << entry.getUSName() <<" | ";
	std::cout << "Japanese Name: " << entry.getJapName() << " | ";
	std::cout << "Pokedex Number: " << entry.getID() << " | ";
	std::cout << "\n";
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::preOrder (void visit(ItemType entry), Node<ItemType>* subtree) const
{
	if(subtree == nullptr)
	{
		return;
	}
	
	ItemType item = subtree -> getEntry();
	
	visit(item);
	preOrder(visit, subtree -> getLeft());
	preOrder(visit, subtree -> getRight());
}
	
template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::visitPreOrder(void visit(ItemType entry)) const
{
	preOrder(visit, m_root);
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::inOrder (void visit(ItemType entry), Node<ItemType>* subtree) const
{
	if(subtree == nullptr)
	{
		return;
	}
	ItemType item = subtree -> getEntry();
	
	inOrder(visit, subtree -> getLeft());
	visit(item);
	inOrder(visit, subtree -> getRight());
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::visitInOrder(void visit(ItemType entry)) const
{
	inOrder(visit, m_root);
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::postOrder(void visit(ItemType entry), Node<ItemType>* subtree) const
{
	if(subtree == nullptr)
	{
		return;
	}
	
	ItemType item = subtree -> getEntry();
	
	postOrder(visit, subtree -> getLeft());
	postOrder(visit, subtree -> getRight());
	visit(item);
}

template <typename ItemType, typename KeyType>
void bst<ItemType, KeyType>::visitPostOrder(void visit(ItemType entry)) const
{
	postOrder(visit, m_root);
}
