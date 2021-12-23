#include"PriortyQueue.h"
void Priority_Queue::insert(string item, int priority,int password)
{
	node *tmp, *q;
	tmp = new node;
	tmp->info = item;
	tmp->priority = priority;
	tmp->password = password;
	if (front == NULL || priority < front->priority)
	{
		tmp->link = front;
		front = tmp;
	}
	else
	{
		q = front;
		while (q->link != NULL && q->link->priority <= priority)
			q = q->link;
		tmp->link = q->link;
		q->link = tmp;
	}
}
void Priority_Queue::del()
{
	node *tmp;
	if (front == NULL)
		cout << "Queue Underflow\n";
	else
	{
		tmp = front;
		cout << "Deleted item is: " << tmp->info << endl;
		front = front->link;
		free(tmp);
	}
}
void Priority_Queue::display()
{
	node *ptr;
	ptr = front;
	if (front == NULL)
		cout << "Queue is empty\n";
	else
	{
		cout << "Queue is :\n";
		cout << "Priority       Item\n";
		while (ptr != NULL)
		{
			cout << ptr->priority << "     " << ptr->info << endl;
			ptr = ptr->link;
		}
	}
}
string Priority_Queue:: DeleteNode(string CNIC)
{
	if (front == NULL)
	{
		cout << "Queue is Empty" << endl;
		return "";
	}
	node* prevNode	=	NULL;
	node* currNode	=	front;
	int currIndex	=	1;
	while (currNode && currNode->info != CNIC) {
		prevNode	=	currNode;
		currNode	=	currNode->link;
		currIndex++;
	}
	if (currNode) {
		if (prevNode) {
			prevNode->link	=	currNode->link;
			delete currNode;
		}
		else {
			front		=	currNode->link;
			delete currNode;
		}
		return CNIC;
	}
	return "";
}

int Priority_Queue::count()
{
	node*curr = front;
	int c = 0;
	if (front == NULL)
	{
		cout << "There Is No customer" << endl;
		return 0;
	}
	while (curr != NULL)
	{
		c++;
		curr = curr->link;
	}
	cout << "Number Of Customer Are :>" << endl;
	return c;
}
node* Priority_Queue::gettop()
{
	if (front == NULL)
	{
		cout << "Queue is Empty" << endl;
	}
	else
	{
		return front;
	}
}
int Priority_Queue::IsEmpty()
{
	if (front == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
