#include"list_doubly_linked.h"
#include<iostream>
using namespace std;

template <class List_entry>				//定位
void List<List_entry>::set_position(int position)const
{
	if (current_position <= position)
		for (; current_position != position; current_position++)
			current = current->next;
	else
		for (; current_position != position; current_position--)
			current = current->back;
}

//List<List_entry>::List(const List<List_entry>& copy)
//void operator = (const List<List_entry>& copy);

template <class List_entry>				//当前大小
int List<List_entry>::size()const
{
	return count;
}

template <class List_entry>				//是否为空
bool List<List_entry>::empty()const
{
	return count == 0;
}

template <class List_entry>				//清除
void List<List_entry>::clear()
{
	List_entry temp;
	while (!empty()) remove(0,temp);
}

template <class List_entry>				//函数指针遍历
void List<List_entry>::traverse(void(*visit)(List_entry&))
{
	for (int i = 0; i < count; i++)
	{
		set_position(i);
		(*visit)(current->entry);
	}
}

//Error_code retrieve(int position, List_entry& x)const
//Error_code replace(int position, const List_entry& x)

template <class List_entry>				//移出
Error_code List<List_entry>::remove(int position, List_entry& x)
{
	if (position < 0 || position >= count)return rangeError;
	if (count == 0) return underflow;
	Node<List_entry>* preceding, * following;
	set_position(position);
	preceding = current->back;
	following = current;
	x = following->entry;	//记录原先位置值
	if (preceding != NULL)preceding->next = following->next;
	if (following->next != NULL)following->next->back = preceding;
	//删表头，current变为新表头，current_position不变
	if (position == 0)current = following->next;
	//删表尾，定位到新表尾
	else if (position == count - 1)set_position(position - 1);
	delete following;
	count--;
}

template <class List_entry>				//插入
Error_code List<List_entry>::insert(int position, const List_entry& x)
{
	if (position < 0 || position > count)return rangeError;
	Node<List_entry>* new_node, * preceding, * following;
	if (position == 0)
	{
		if (count == 0)following = NULL;
		else
		{
			set_position(0);
			following = current;
		}
		preceding = NULL;
	}
	else
	{
		set_position(position - 1);
		preceding = current;
		following = preceding->next;
	}
	new_node = new Node<List_entry>(x, preceding, following);
	if (new_node == NULL) return overflow;
	if (preceding != NULL)preceding->next = new_node;
	if (following != NULL)following->back = new_node;
	current = new_node;
	current_position = position;
	count++;
	return success;
}