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

void main()
{
	stack_arr s;
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
