#include "stdafx.h"
#include<iostream>
using namespace std;

class stack_arr
{
	private:
	int ar[5];
	int top;

	public:
	stack_arr()
	{
		top=-1;
	}

	void push(int key)
	{
			if(top>=4)
			{
				cout<<"Overflow error.."<<endl;
				return;
			}
			top++;
			ar[top]=key;
	}
	
	int pop()
	{
		if(top<0)
		{
			cout<<"Underflow error..";
			return 0;
		}
		int k=ar[top];
		top--;
		return k;
		
	}

	int isempty()
	{
		if(top<0)
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
		if(top>=4)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
};

class queue_twostack:public stack_arr
{
	private:
	stack_arr s1,s2;
	
	public:
	void enqueue(int key)
	{
		s1.push(key);
	}
	
	int dequeue()
	{	
		while(!s1.isempty() )
		{
			s2.push(s1.pop());
		}
		int k=s2.pop();
		while(!s2.isempty())
		{
			s1.push(s2.pop());
		}
		return k;
	}
};


void main()
{
	queue_twostack q;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);	
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
	cout<<"Dequeued:"<<q.dequeue()<<endl;
}
