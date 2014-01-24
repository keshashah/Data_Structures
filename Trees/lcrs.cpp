#include "stdafx.h"
#include<iostream>

using namespace std;

struct atree
{
	int akey;
	atree *c[3];
	int childindex;
	atree *parent;
}*aroot;
	
struct btree
{
	int bkey;
	btree *left;
	btree *right;
	btree *parent;
}*broot;

class Queue
{     
	public: 
	struct node
	{
		struct atree *data;
		struct node *next;
	}*head;
	
	Queue()
	{
		head=NULL;
	}

	void enqueue(atree *a)
	{
		node *added=new node;
		
		if(added==NULL)
		{
			cout<<"Overflow"<<endl;
			return;
		}
		added->data=a;
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
	
	atree* dequeue()
	{
		struct node *temp=head;
		if(temp==NULL)
		{
			cout<<"UnderFlow Error"<<endl;
			return NULL;
		}
		
		temp=temp->next;
		atree *k=new atree;
		k=head->data;
		free(head);
		head=temp;
		return k;
	}
};

void encode(atree *ar)
{
		Queue q;
		atree *temp;
		btree *btemp;
		temp=ar;
		broot=new btree;
		q.enqueue(ar);
		while(q.head)
		{
			temp=q.dequeue();
			for(int i=0;i<3;i++)
			{
				
				if(temp->c[i])
					q.enqueue(temp->c[i]);
			}
			if(temp->akey==aroot->akey) //A'= A if root
			{
				broot->bkey=aroot->akey;
				broot->left->bkey=aroot->c[0]->akey;
				broot->right=NULL;
				broot->parent=NULL;
			}
			
			else
			{
				btree *b=new btree;
				int r=temp->childindex;
				b->bkey = temp->akey;
				b->left->bkey=temp->c[0]->akey;
				b->right->bkey= temp->parent->c[r+1]->akey;
				
				if(r==0)
				{
					b->parent->bkey=temp->parent->akey;
				}
				else
				{
					b->parent->bkey=temp->parent->c[r-1]->akey;
				}
			}
		}
		
		
		
}

void display(btree *x)
{
	if(x==NULL)
	{
		return;
	}

	cout<<x->bkey<<endl;
	display(x->left);
	display(x->right);
}

	
int main()
{
/*
	//making a hardcore arbitary tree
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"Enter Key(0 for no child) for node in level"<<i;
			cin>>arbitarytree[i][j];
			
			if(i==0)
				break;
				
			if(arbitarytree[i][j]==0)
				break;
		}
		
	}
	//----------------------------------
	binarytree *b=new binarytree;
	b.encode();
	b.display();
*/

	int k,cr,cc;
	atree *a;
	cout<<"Enter key for root:";
	cin>>k;
	
	aroot=new atree;
	aroot->akey=k;
	aroot->parent=NULL;
	aroot->childindex=0;
	
	cout<<"Enter no of children of root:";
	cin>>cr;
	
	for(int i=0;i<cr;i++)
	{
		cout<<"Enter the key:";
		cin>>k;
		
		a=new atree;
		a->akey=k;
		a->parent=aroot;
		aroot->c[i]=new atree;
		aroot->c[i]=a;
	}
	
	for(int i=0;i<cr;i++)
	{
		cout<<"Enter no of children for child no"<<i;
		cin>>cc;
		
		if(cc==0)
			break;
			
		for(int j=0;j<cc;j++)
		{
			cout<<"Enter key for child";
			cin>>k;
			
			a->akey=k;
			a->parent=aroot->c[i];
			aroot->c[i]->c[j] = new atree;
			aroot->c[i]->c[j] = a;
		}
	}
	
	encode(aroot);
}