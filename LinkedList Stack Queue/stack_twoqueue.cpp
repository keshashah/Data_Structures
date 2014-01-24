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
		if(front==-1)
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
		if(front == (rear+1)%5)
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

	int lastelement()
	{
		return ar[rear];
	}
};

class stack_twoqueue: public queue_arr
{
	private:
	queue_arr q1,q2;

	public:
	
	void push(int key)
	{
		q1.enqueue(key);
	}

	int pop()
	{
		if(q1.isempty() ==1)
		{
			cout<<"Underflow error :("<<endl;	
			return -1;
		}
	
		while(q1.size() != 1)
		{
			q2.enqueue(q1.dequeue());
		}
		int d=q1.dequeue();
		while(q2.size() != 0)
		{
			q1.enqueue(q2.dequeue());
		}

		return d;
	}

};

void main()
{
	stack_twoqueue s;
	s.push(5);
	s.push(10);
	s.push(15);
	s.push(20);
	s.push(25);
	s.push(30);
	cout<<"poped:"<<s.pop()<<endl;
	cout<<"poped:"<<s.pop()<<endl;
	cout<<"poped:"<<s.pop()<<endl;
	cout<<"poped:"<<s.pop()<<endl;
	cout<<"poped:"<<s.pop()<<endl;
	cout<<"poped:"<<s.pop()<<endl;
}