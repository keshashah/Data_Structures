#include<stdafx.h>
#include<iostream>

using namespace std;

class AVLSearchTree
{
	public:
	struct avlnode
	{
		int data;
		avlnode *left;
		avlnode *right;
	}*root;

	AVLSearchTree()
	{
		root = NULL;
	}
	
	void insert(int key)
	{
		if(root==NULL)
		{
			root=new avlnode;
			if(root==NULL)
			{
				cout<<"Memmory Error"<<endl;
				return;
			}
			root->data = key;
			root->right = root->left = NULL;
			return;
		}
		
		avlnode* temp=root;	
		while((key< temp->data && temp->left != NULL)||(key > temp->data && temp->right != NULL))
		{
			if(key< temp->data)
				temp=temp->left;
			else
				temp=temp->right;
		}
		
		avlnode* added = new avlnode;
		added->data=key;
		added->left = added->right =NULL;
		
		if(key< temp->data)
			temp->left= added;
		else
			temp->right=added;

		balance(added);
	}

	int height(avlnode *node)
	{
		if(node == NULL)
			return -1;
		else if(node->left==NULL && node->right==NULL)
			return 0;
		else
			return 1+(max(height(node->left),height(node->right)));
	}

	int depth(avlnode* node)
	{
		int d=-1;
		while(node != NULL)
		{
			d++;
			node=parent(node);
		}
		return d;
	}


	int balancefactor(avlnode *node)
	{
		int bf=(height(node->left))-(height(node->right));
	//	cout<<"BF of "<<node->data<<"is"<<bf<<endl;
		return bf;
	}

	void balance(avlnode *temp)
	{
		while(temp != NULL)
		{
			if(balancefactor(temp)== 2 || balancefactor(temp)== -2)
			{
				int f=0;
				avlnode *paroftemp=parent(temp);
		
				if(root==temp)
					{
						f=1;
					}
					else
					{
						if(temp==paroftemp->left)
							f=2;
						else if(temp==paroftemp->right)
							f=3;
					}
					temp=rotate(temp);

					if(f==1)
					{					
						root=temp;
					}	
					else
					{
						if(f==2)
							paroftemp->left=temp;
						else if(f==3)
							paroftemp->right=temp;
					}
				}			
			temp=parent(temp);
		}
	}

	avlnode* rotate(avlnode *u)
	{
		if(balancefactor(u)== -2)
		{
			if(balancefactor(u->right)==-1)
			{
				u=leftrotate(u);
			}
			else if(balancefactor(u->right)==1)
			{
				u->right=rightrotate(u->right);
				u=leftrotate(u);
			}
		}

		if(balancefactor(u)==2)
		{
			if(balancefactor(u->left)==1)
			{
				u=rightrotate(u);
			}
			else if(balancefactor(u->left)==-1)
			{
				u->left=leftrotate(u->left);
				u=rightrotate(u);
			}
			//cout<<"rotated"<<endl;
		}

		return u;
	}

	int max(int a,int b)
	{
		if(a>b)
			return a;
		else
			return b;
	}

	avlnode *del(avlnode *temp)
	{
		avlnode *par;	
		//no child->leaf
		if(temp->left == NULL && temp->right == NULL)
		{
			par=parent(temp);
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
			par=parent(temp);
			if(temp==parent(temp)->left)
				parent(temp)->left=temp->right;
			else
				parent(temp)->right=temp->right;
		
		}
		//one child-left
		else if(temp->right ==NULL && temp->left != NULL)
		{
			par=parent(temp);
			if(temp==parent(temp)->left)
				parent(temp)->left=temp->left;
			else
				parent(temp)->right=temp->left;
		}
		//two children
		else if(temp->right && temp->left)
		{
			avlnode *succ;	
			succ=successor(temp->data);
			int t=succ->data;	
			
			del(succ);

			temp->data=t;

		}
		
	//	while(!par)
	//	{
			balance(par);
	//		par=parent(par);
	//	}

		return temp;
	}

	avlnode *del(int key)
	{
		avlnode *temp=find(key);
		return del(temp);
	}
	

	avlnode *leftrotate(avlnode *x)
	{
		if(x->right==NULL)
		{
			cout<<"Error-right of leftrotate doesnt exist"<<endl;
			return NULL;
		}
		avlnode *y=x->right;
		x->right=y->left;
		y->left=x;
		return y;
	}

	avlnode* rightrotate(avlnode *x)
	{
		if(x->left==NULL)
		{
			cout<<"Error-left of rightrotate doesnt exist"<<endl;
			return NULL;
		}
		avlnode *y;
		y=x->left;	
		x->left=y->right;
		y->right=x;
		return y;
		//cout<<"Rightrotate"<<endl;
	}
	
	avlnode *parent(avlnode *child)
	{
		if(child == root)
			return NULL;
	
		avlnode *temp=root;
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

	
	avlnode* find(int key)
	{
		int f=0;
		if(root==NULL)
		{
			cout<<"Root is NULL"<<endl;
			return NULL;
		}
		avlnode *temp=root;
		if(key== temp->data)
			return temp;
		while((key<= temp->data && temp->left != NULL)||(key >= temp->data && temp->right != NULL))
		{
			if(key<= temp->data)
			{
				temp=temp->left;
				if(key==temp->data)
				{
					f=1;
					break;
				}
			}
			else
			{
				temp=temp->right;
				if(key==temp->data)
				{
					f=1;		
					break;
				}
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
		avlnode *maxi= maximum(root);
		return maxi->data;
	}
	
	avlnode *maximum(avlnode *temp)
	{
		while(temp->right != NULL)
		{
			temp=temp->right;
		}
		return temp;
	}

	int minimum()
	{
		avlnode *min=minimum(root);
		return min->data;
	}

	avlnode *minimum(avlnode *temp)
    {
           while(temp->left != NULL)
           {
                        temp=temp->left;
           }
                
           return temp;
    }

	avlnode *successor(int key)
	{	
		avlnode *temp=find(key);
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
	
     avlnode *predecessor(int key)
     {
            avlnode *temp=find(key);
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

	void display()
	{
		inorder(root);
	}	
	
	void inorder(avlnode* x)
	{
		if(x==NULL)
			return;
		
		cout<<x->data<<endl;
		inorder(x->left);
		//cout<<x->data<<endl;
		inorder(x->right);
		//cout<<x->data<<endl;
	}
};

int main()
{
	AVLSearchTree b;
	b.insert(20);
	b.insert(10);
	b.insert(35);
	b.insert(5);
	b.insert(15);
	b.insert(25);
	b.insert(40);
	b.insert(18);
	b.insert(30);
	b.insert(38);
	b.insert(45);
	b.insert(50);
	
	b.del(20);
	b.display();


}


