#include "stdafx.h"
#include<iostream>
using namespace std;

class QueueSwap
{
	private:
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head;
	
	public:

	QueueSwap()
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
	
	int size()
	{
		struct node *temp=head;
		int c=1;
		while(temp->next!=NULL)
		{
			c++;
			temp=temp->next;
		}
		return c;
	}
	
	int isempty()
	{
		if(head==NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	void swap(int s,int d)
	{
		QueueSwap t1,t2;
		
		for(int i=1;i<s;i++)
		{
			t1.enqueue(dequeue());
		}
		
		while(!isempty())
		{
			t2.enqueue(dequeue());
		}
		
		while(!t1.isempty())
		{
			enqueue(t1.dequeue());
		}
		
		for(int i=s; i<d ;i++)
		{
			t1.enqueue(t2.dequeue());
		}
		
		enqueue(t2.dequeue());
			
		t2.enqueue(t1.dequeue());
		
		while(!t1.isempty())
		{
			enqueue(t1.dequeue());
		}

		while(t2.size() !=1)
		{
			t1.enqueue(t2.dequeue());
		}
		

		enqueue(t2.dequeue());
		
		while(!t1.isempty())
		{
			enqueue(t1.dequeue());
		}
	}
};

void main()
{
	QueueSwap q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	q.enqueue(70);

	q.swap(2,5);

	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
}