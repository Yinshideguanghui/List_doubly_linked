#include"list_doubly_linked.h"
#include"list_doubly_linked.cpp"
#include<iostream>
using namespace std;

template <class List_entry>
void print(List_entry x)
{
	cout << x;
}
int main()
{
	List<int> s;
	s.insert(0, 1); s.insert(1, 2);
	cout << "�������\n";
	s.traverse(print);
	cout << endl;
	int item;
	s.remove(0, item);
	cout << "�Ƴ����\n";
	s.traverse(print);
	cout << endl;
	return 0;
}