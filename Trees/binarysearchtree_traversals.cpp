#include<stdafx.h>
#include<iostream>
using namespace std;

struct btree
{
	int key;
	struct btree *left;
	struct btree *right;
}*root;

class Stack
{
	private:
	struct node
	{
		struct btree *data;
		struct node *next;
	};
	public:
	struct node *top;
	
	Stack()
	{
		top=NULL;
	}

	void push(btree *key)
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
	
	btree* pop()
	{
		if(top==NULL)
		{
			cout<<"Underflow Error..";
			return 0;
		}
		node *temp=top;
		top=top->next;
		struct btree *n=new btree;
		n=temp->data;
		free(temp);
		return n;
	}
	
};

class Queue
{     
	public: 
	struct node
	{
		struct btree *data;
		struct node *next;
	}*head;
	
	Queue()
	{
		head=NULL;
	}

	void enqueue(btree *a)
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
	
	btree* dequeue()
	{
		struct node *temp=head;
		if(temp==NULL)
		{
			cout<<"UnderFlow Error"<<endl;
			return NULL;
		}
		
		temp=temp->next;
		btree *k=new btree;
		k=head->data;
		free(head);
		head=temp;
		return k;
	}
};


class binarysearchtree_traversals
{
	public:
	
	binarysearchtree_traversals()
	{
		root=NULL;
	}

	void add(int k)
	{
		struct btree *temp;
		temp=new btree;
		
		temp->key=k;
		temp->left=NULL;
		temp->right=NULL;

		if(root==NULL)
		{
			root=temp;
			return;
		}
		else
		{
			struct btree *track,*uptrack;
			track=root;
			while(track != NULL)
			{
				uptrack=track;
				if(k>track->key)
				{
					track=track->right;
				}
				else
				{
					track=track->left;
				}
			}
			if(k > uptrack->key)
			{
				uptrack->right =temp;
			}
			else
			{
				uptrack->left =temp;
			}
		}
		
	}
	
	void preorder()
	{
		preorder(root);
	}
	
	void preorder(struct btree *x)
	{
		if(x==NULL)
		{
			return;
		}
		
		cout<<x->key<<endl;
		preorder(x->left);
		preorder(x->right);
	}

	void inorder()
	{
		inorder(root);
	}

        void inorder(btree *x)
        {
                if(x==NULL)
                {
                 	return;
                }

                inorder(x->left);
		cout<<x->key<<endl;
                inorder(x->right);
        }
	
	void postorder()
	{
		postorder(root);
	}

        void postorder(btree *x)
        {
                if(x==NULL)
                {
                        return;
                }

                postorder(x->left);
                postorder(x->right);
				cout<<x->key<<endl;
        }

	void levelorder()
	{
		struct btree *temp=root;
		if(temp==NULL)
		{
			cout<<"empty list";
			return;
		}
		else
		{
			Queue q;
			q.enqueue(temp);
			while(q.head != NULL)
  			{
			   	struct btree *t=q.dequeue();
				if(t->left != NULL)
				{
					q.enqueue(t->left);
				}
				if(t->right != NULL)
				{
					q.enqueue(t->right);
				}
				cout<<t->key<<endl;
			}
		}
	}

	void zigzag()
	{
		Stack s1,s2;
		s1.push(root);
		int leftright=1;
		while(!(s1.top ==NULL && s2.top ==NULL))
		{
			while(s1.top != NULL)
			{
				struct btree *t=new btree;
				t=s1.pop();
			
				cout<<t->key<<endl;
	
				if(leftright==0)
				{
					if(t->left != NULL)
					{
						s2.push(t->left);
					}		
					if(t->right != NULL)
					{
						s2.push(t->right);
					}		
				}
				else
				{
					if(t->right != NULL)
                                        {
                                                s2.push(t->right);
                                        }
                                        if(t->left != NULL)
                                        {
                                                s2.push(t->left);
                                        } 
 
				}
			}
			leftright=1-leftright;
			Stack stemp;
			stemp=s1;
			s1=s2;
			s2=stemp;		
		}
	}
};



int main()
{
	binarysearchtree_traversals b;
	b.add(5);
	b.add(10);
	b.add(4);
	b.add(11);
	b.add(2);
	b.add(3);
	cout<<"preorder"<<endl;		
	b.preorder();
	cout<<"inorder"<<endl;
	b.inorder();
	cout<<"postorder"<<endl;
	b.postorder();
	cout<<"levelorder"<<endl;
	b.levelorder();
	cout<<"zigzag"<<endl;
	b.zigzag();
}
