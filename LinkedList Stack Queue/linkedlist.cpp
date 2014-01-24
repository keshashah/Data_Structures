#include "stdafx.h"
#include<iostream>
using namespace std;

public class linkedList
{
	private:
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head;
	
	public:
	linkedList(int key)
	{											
		head=(struct node*)malloc(sizeof(struct node));
		head->data= key;
		head->next=NULL;
	}
	
	void add(int key)
	{
		struct node *added=(struct node*)malloc(sizeof(struct node));
		
		if(added==NULL)
		{
			cout<<"Overflow"<<endl;
			return;
		}
		
		struct node *temp=head;
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		added->data=key;
		added->next=NULL;
		temp->next=added;
		
	}
	
	void del(int dkey)
	{
		struct node *temp=head,*prev=NULL;
		
		if(temp->data ==dkey)
		{
			delfirst();
		}
		
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
			if(temp->data == dkey)
			{
				prev->next=temp->next;
				free(temp);
				temp=prev->next;
			}
		}
		
	}
	
	void delfirst()
	{
			struct node *temp=head;

			if(head==NULL)
			{
				cout<<"UnderFlow Error"<<endl;
				return;
			}
			temp=head->next;
			free(head);
			head=temp;
	}
	
	void dellast()
	{
		struct node *temp=head,*prev=NULL;

		if(head==NULL)
		{
			cout<<"UnderFlow Error"<<endl;
			return;
		}
		prev=temp;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		
		prev->next=NULL;
		free(temp);
	}
	
	void search(int skey)
	{
		struct node *temp=head;
		while(temp->next != NULL)
		{
			if(skey==temp->data)
			{
				cout<<"Search found"<<endl;
				return;
			}
			temp=temp->next;
		}
		if(skey==temp->data)
		{
			cout<<"Search found"<<endl;
			return;
		}
		
		cout<<"Search not found.."<<endl;
	}
	
	void reverse()
	{
		struct node *temp=NULL,*nextnode=NULL;
		while(head->next)
		{
			nextnode=head->next;
			head->next=temp;
			temp=head;
			head=nextnode;
		}
		head->next =temp;
	}
	
	void display()
	{
		cout<<"displaying:"<<endl;
		struct node *temp=head;

		if(head==NULL)
		{	
			cout<<"Empty List.."<<endl;
			return;
		}

		while(temp->next != NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
		cout<<temp->data<<endl;
	}
	
};

void main()
{
	linkedList l1(10);
	l1.add(20);
	l1.add(30);
	l1.add(20);
	l1.add(40);

	l1.search(50);
	l1.search(20);

	l1.display();
	l1.del(20);

	l1.display();
	l1.reverse();
	l1.display();
	l1.dellast();
	l1.display();
	l1.delfirst();
	l1.display();
	l1.delfirst();
	l1.display();
	l1.dellast();
}