#include <iostream>
#include <cstdio>
#include <cstring>
#include<iostream>
#include <cstdlib>
#include<string>
using namespace std;
struct node
{
	int priority;
	string info;
	int password;
	struct node *link;
};
class Priority_Queue
{
private:
	node *front;
public:
	Priority_Queue()
	{
		front = NULL;
	}
	int count();
	
	/*
	* Insert into Priority Queue
	*/
	void insert(string item,int priority,int password);
	/*
	* Delete from Priority Queue
	*/
	void del();
	/*
	* Print Priority Queue
	*/
	void display();
	node* gettop();
	int IsEmpty();
	string  DeleteNode(string CNIC);
};
