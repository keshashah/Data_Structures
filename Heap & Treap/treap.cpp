#include<iostream>

using namespace std;

class treap
{
	int array[4][2];//4->values;2-0-tree,1-heap
	struct btree
	{
  		int key;
   	 	struct btree *left;
   	 	struct btree *right;
	}*root;
	
	public:
	
	treap()
	{
		root=NULL;
		array[0][0]=65;
		array[0][1]=80;
                array[1][0]=70;
                array[1][1]=63;
                array[2][0]=48;
                array[2][1]=48;
                array[3][0]=67;
                array[3][1]=92;

	}
	
	void buildtreap()
	{
		sortheap();
		for(int i=0;i<4;i++)
		{
			bstinsert(array[i][0]);
		}
	}
	
	void sortheap()
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(array[j][1] > array[j+1][1] )
				{
					swap(j,j+1);
				}
			}
		}
	}
	
	void swap(int j,int k)
	{
		int temp;
		temp= array[j][0];
		array[j][0]=array[k][0];
		array[k][0]=temp;
                temp= array[j][1];
                array[j][1]=array[k][1];
                array[k][1]=temp;
	}
	
/*	void display()
	{
		for(int i=0;i<4;i++)
		{
			cout<<array[i][1]<<endl;
		}
	}
*/	
	void bstinsert(int k)
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
	
	void display()
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
};

int main()
{
	treap t;
	t.buildtreap();
	t.display();
}
