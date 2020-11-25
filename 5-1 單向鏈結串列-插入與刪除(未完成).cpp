#include <iostream>
using namespace std;
class LinkedList;

typedef struct data {
	int number;
	struct data* next;
}Data;

class ListNode
{
public:
	ListNode(int a) { data = a; link = 0; }
private:
	int data;
	ListNode* link;
	friend class LinkedList;
};

class LinkedList
{
public:
	ListNode* first;
	ListNode* last;
	LinkedList(){
		first = 0;
		last = 0;
	};
	void InsertFirst(int x);
	void InsertLast(int x);
	int DeleteFirst();
	int DeleteLast();
	void PrintList();
};

void LinkedList::InsertFirst(int x)
{
	ListNode* newNode = new ListNode(x);
	newNode->link = first;
	first = newNode;
}

void LinkedList::InsertLast(int x)
{
	ListNode* newNode = new ListNode(x);

	if (last== 0)
	{
		last = newNode;
		return;
	}

	ListNode* current = last;
	while (current->link != 0)
	{
		current = current->link;
	}
	current->link = newNode;
}

int LinkedList::DeleteFirst()
{
	ListNode* current = first,
		* previous = 0;
	
	if (current == first) {
		first = current->link;
		delete current;
		current = 0;               
	}
	return 0;
}

int LinkedList::DeleteLast()
{
	ListNode* current = first,
		* previous = 0;
	if (current != first) {
		previous->link = current->link;
		delete current;
		current = 0;
	}
	return 0;
}

void LinkedList::PrintList()
{
	ListNode* current1 = first;
	while (current1 != 0)
	{
		cout << current1->data << " ";
		current1 = current1->link;
	}
	ListNode* current2 = last;
	while (current2 != 0)
	{
		cout << current2->data << " ";
		current2 = current2->link;
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	LinkedList list;
	int times, input;
	for (cin >> times; times > 0; times--) { cin >> input; list.InsertFirst(input); }
	for (cin >> times; times > 0; times--) list.DeleteFirst();
	for (cin >> times; times > 0; times--) { cin >> input; list.InsertLast(input); }
	for (cin >> times; times > 0; times--) list.DeleteLast();
	list.PrintList();
}
