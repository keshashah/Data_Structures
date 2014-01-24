#include "stdafx.h"
#include<iostream>
using namespace std;

class queue_arr
{
	public:
	int ar[5];
	int rear;
	int front;
	
	queue_arr()
	{
		rear = -1;
		front = -1;
	}
	
	void enqueue(int key)
	{
		if(front==(rear+1)%5)
		{
			cout<<"Overflow.."<<endl;
			return;
		}
		rear=(rear+1)%5;
		ar[rear]=key;	

		if(front==-1)
		{
			front=rear;
		}
	}
	
	int dequeue()
	{
		if(front == -1)
		{
			cout<<"underflow..";
			return 0;
		}
		
		int k=ar[front];
		if(front==rear)
		{
			front=rear=-1;
		}
		else
		{
			front=(front+1)%5;
		}
		return k;
	}
	
	int isempty()
	{
		if(front==(rear+1)%5)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	int isfull()
	{
		if(front == -1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int size()
	{
		if(front==-1)
			return 0;
		else if(front==(rear+1)%5)
			return 5;
		else
			return (6+rear-front)%5;
	}
};

void main()
{
	queue_arr q;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	//cout<<"Size:"<<q.size()<<endl;
	q.enqueue(10);
	//cout<<"Size:"<<q.size()<<endl;
	q.enqueue(20);
	//cout<<"Size:"<<q.size()<<endl;
	q.enqueue(30);
	//cout<<"Size:"<<q.size()<<endl;
	q.enqueue(40);
	//cout<<"Size:"<<q.size()<<endl;
	q.enqueue(50);
	//cout<<"Size:"<<q.size()<<endl;
	//cout<<"Size:"<<q.size()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	q.enqueue(60);
	q.enqueue(70);
	cout<<q.size()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	
}