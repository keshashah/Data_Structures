#include "stdafx.h"
#include<iostream>
using namespace std;

class Queue
{
	private:
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head;
	
	public:

	Queue()
	{
		head=NULL;
	}

	void enqueue(int key)
	{
		node *added=new node;
		
		if(added==NULL)
		{
			cout<<"Overflow"<<endl;
			return;
		}
		added->data=key;
		added->next=NULL;
		
		struct node *temp=head;
		if(head==NULL)
		{
			head=added;
			return;
		}

		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		temp->next=added;
	}
	
	int dequeue()
	{
		struct node *temp=head;
		if(temp==NULL)
		{
			cout<<"UnderFlow Error"<<endl;
			return NULL;
		}
		
		temp=temp->next;
		int k=head->data;
		free(head);
		head=temp;
		return k;
	}
};

void main()
{
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
}