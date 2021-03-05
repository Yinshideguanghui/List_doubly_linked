#pragma once
#include<iostream>

template <class Node_entry>
struct Node
{
	Node_entry entry;
	Node<Node_entry>* back;
	Node<Node_entry>* next;

	Node() {}
	Node(Node_entry x, Node<Node_entry>* link_back = NULL, 
					   Node<Node_entry>* link_next = NULL)
	{
		entry = x;
		back = link_back;
		next = link_next;
	}
};

enum Error_code { success, underflow, overflow, rangeError };

template<class List_entry>
class List
{
public:
	List() { count = 0; current_position = 0; current = NULL; }
	//List(const List<List_entry>& copy);
	//void operator = (const List<List_entry>& copy);
	~List() { clear(); }

	int size()const;
	bool empty()const;
	void clear();
	void traverse(void(*visit)(List_entry&));

	//Error_code retrieve(int position, List_entry& x)const;
	//Error_code replace(int position, const List_entry& x);
	Error_code remove(int position, List_entry& x);
	Error_code insert(int position, const List_entry& x);
protected:
	int count;
	mutable int current_position;
	mutable Node<List_entry>* current;
	void set_position(int position)const;
};