#include<stdafx.h>
#include<iostream>

using namespace std;

class BinarySearchTree
{
	public:
	struct bstnode
	{
		int data;
		bstnode *left;
		bstnode *right;
	}*root;

	BinarySearchTree()
	{
		root = NULL;
	}
	
	void insert(int key)
	{
		if(root==NULL)
		{
			root=new bstnode;
			if(root==NULL)
			{
				cout<<"Memmory Error"<<endl;
				return;
			}
			root->data = key;
			root->right = root->left = NULL;
			return;
		}
		
		bstnode* temp=root;	
		while((key< temp->data && temp->left != NULL)||(key > temp->data && temp->right != NULL))
		{
			if(key< temp->data)
				temp=temp->left;
			else
				temp=temp->right;
		}
		
		bstnode* added = new bstnode;
		added->data=key;
		added->left = added->right =NULL;
		
		if(key< temp->data)
			temp->left= added;
		else
			temp->right=added;
	}
	
	bstnode* find(int key)
	{
		int f=0;
		if(root==NULL)
		{
			cout<<"Root is NULL"<<endl;
			return NULL;
		}
		bstnode *temp=root;
		if(key== temp->data)
			return temp;
		while((key<= temp->data && temp->left != NULL)||(key >= temp->data && temp->right != NULL))
		{
			if(key<= temp->data)
				temp=temp->left;
				if(key==temp->data)
				{
					f=1;
					break;
				}
			else 
				temp=temp->right;
				if(key==temp->data)
				{
					f=1;		
					break;
				}
		}
		
		if(f==0)
		{
			cout<<"Element"<< key<<" not found"<<endl;
			return NULL;
		}
		else 
		{
		//	cout<<"Element "<<key<<"Found"<<endl;
			return temp;
		}
	}
	
	int maximum()
	{
		bstnode *max= maximum(root);
		return max->data;
	}
	
	bstnode *maximum(bstnode *temp)
	{
		while(temp->right != NULL)
		{
			temp=temp->right;
		}
		return temp;
	}

	int minimum()
	{
		bstnode *min=minimum(root);
		return min->data;
	}

	bstnode *minimum(bstnode *temp)
    {
           while(temp->left != NULL)
           {
                        temp=temp->left;
           }
                
           return temp;
    }

	bstnode *successor(int key)
	{	
		bstnode *temp=find(key);
		if(temp->right != NULL)
		{
			return minimum(temp->right);
		}	
		
		else
		{
			while(temp==parent(temp)->right)
			{
				temp=parent(temp);
			}
				
			return parent(temp);
		}
	}
	
     bstnode *predecessor(int key)
     {
            bstnode *temp=find(key);
            if(temp->left != NULL)
            {
				return maximum(temp->left);
            }

            else
            {
                        while(temp==parent(temp)->left)
                        {
                                temp=parent(temp);
                        }

                        return parent(temp);
                        
                }
        }
	
	bstnode *parent(bstnode *child)
	{
		if(child == root)
			return NULL;
	
		bstnode *temp=root;
		int key=child->data;
               	while(key< temp->data || key > temp->data )
               	{
                       	if(key< temp->data)
						{
								if(key== temp-> left->data)
										break;
								else
							       		temp=temp->left;
						}	
                        else
						{
							if(key== temp-> right ->data)
									break;
							else
	                               	temp=temp->right;
						}
               	}
				return temp;
	}

	bstnode *del(bstnode *temp)
	{
	
		//no child->leaf
		if(temp->left == NULL && temp->right == NULL)
		{
			if(temp==parent(temp)->left)
				parent(temp)->left=NULL;
			else
			{
				parent(temp)->right=NULL;
			}	
		}
		//one child-right
		else if(temp->left ==NULL && temp->right !=NULL)
		{
			if(temp==parent(temp)->left)
				parent(temp)->left=temp->right;
			else
				parent(temp)->right=temp->right;
		
		}
		//one child-left
		else if(temp->right ==NULL && temp->left != NULL)
		{
			if(temp==parent(temp)->left)
				parent(temp)->left=temp->left;
			else
				parent(temp)->right=temp->left;
	
		}
		//two children
		else if(temp->right && temp->left)
		{
			bstnode *succ;	
			succ=successor(temp->data);
			int t=succ->data;	
			
			del(succ);

			temp->data=t;

		}
		
		return temp;
	}
	bstnode *del(int key)
	{
		bstnode *temp=find(key);
		return del(temp);
	}
	
	void leftrotate()
	{
		bstnode *x=root;

		if(x->right==NULL)
		{
			return;
		}
		bstnode *y=x->right;
		x->right=y->left;
		y->left=x;
		root=y;
	}

	void rightrotate()
	{
		bstnode *x=root;
		if(x->left==NULL)
		{
			return;
		}
		bstnode *y;
		y=x->left;	
		x->left=y->right;
		y->right=x;
		root=y;
	}

	void display()
	{
		inorder(root);
	}	
	
	void inorder(bstnode* x)
	{
		if(x==NULL)
			return;

		inorder(x->left);
		cout<<x->data<<endl;
		inorder(x->right);
	}
};

int main()
{
	BinarySearchTree b;
	b.insert(5);
	b.insert(4);
	b.insert(3);
	b.insert(8);
	b.insert(6);
	b.insert(7);
	b.display();
	b.find(9);
	b.insert(9);
	b.display();
	b.rightrotate();
	b.display();
	b.find(9);
	cout<<"Successor of 5 is:"<<b.successor(5)->data<<endl;
	cout<<"Successor of 7 is: "<<b.successor(7)->data<<endl;
        cout<<"predecessor of 5 is:"<<b.predecessor(5)->data<<endl;
        cout<<"predecessor of 6 is: "<<b.predecessor(6)->data<<endl;

	cout<<"Maximum : "<<b.maximum()<<endl;
	cout<<"Minimum : "<<b.minimum()<<endl;
	
	cout<<"Del6"<<endl;
	b.del(6);
	b.display();

        cout<<"Del8"<<endl;
        b.del(8);
        b.display();
}


