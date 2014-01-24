#include "stdafx.h"
#include<iostream>
using namespace std;

class Stack
{
	private:
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *top;
	
	public:
	Stack()
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
			cout<<"Underflow Error..";
			return 0;
		}
		node *temp=top;
		top=top->next;
		int n=temp->data;
		free(temp);
		return n;
	}
	
};

void main()
{
	Stack s;
	s.push(10);	
	s.push(20);
	s.push(30);
	cout<<"Popped:"<<s.pop()<<endl;	
	cout<<"Popped:"<<s.pop()<<endl;
	cout<<"Popped:"<<s.pop()<<endl;
	cout<<"Popped:"<<s.pop()<<endl;
}
	

