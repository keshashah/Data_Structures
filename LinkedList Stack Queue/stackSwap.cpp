#include "stdafx.h"
#include<iostream>
using namespace std;

class stackSwap
{
	private:
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *top;
	
	public:
	stackSwap()
	{
		top=NULL;
	}

	void push(int key)
	{
		node *added=new node;
		if(added==NULL)
		{
			cout<<"Overflow"<<endl;
			return;
		}

		added->data=key;
		added->next=top;
		top=added;	
	}
	
	int pop()
	{
		if(top==NULL)
		{
			cout<<"Underflow";
			return 0;
		}
		node *temp=top;
		top=top->next;
		int n=temp->data;
		free(temp);
		return n;
	}
	
	int isempty()
	{
		if(top==NULL)
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
		stackSwap t1,t2;
		for(int i=1;i<=s;i++)
		{
			t1.push(pop());
		}
		
		for(int i=s+1;i<=d;i++)
		{
			t2.push(pop());
		}
		push(t1.pop());
		t1.push(t2.pop());
		
		while(!t2.isempty())
		{
			push(t2.pop());
		}
		
		while(!t1.isempty())
		{
			push(t1.pop());
		}
	}
	
};	

void main()
{
	stackSwap s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	s.push(70);
	
	s.swap(2,5);

	cout<<"Poped:"<<s.pop()<<endl;
	cout<<"Poped:"<<s.pop()<<endl;
	cout<<"Poped:"<<s.pop()<<endl;
	cout<<"Poped:"<<s.pop()<<endl;
	cout<<"Poped:"<<s.pop()<<endl;
	cout<<"Poped:"<<s.pop()<<endl;
	cout<<"Poped:"<<s.pop()<<endl;
	cout<<"Poped:"<<s.pop()<<endl;
}