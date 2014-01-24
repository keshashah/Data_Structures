// heap.cpp : main project file.

#include "stdafx.h"

#include<iostream>

using namespace std;

struct heap
{
	int *array;
	int capacity;
	int count;
};

class Heap
{
	private:
	struct heap *h;

	public:
	Heap()
	{
		h=new heap;
		h->capacity=1;
		h->count=-1;
		h->array=(int*)malloc(sizeof(int) * h->capacity);
		if(h->array==NULL)
		{
			cout<<"Memory Error";
			return;
		}

	}
	
	void construct(int A[],int n)
	{
		for(int i=0;i<n;i++)
		{
			h->count++;
			if(h->count >= h->capacity)
				resize();
			h->array[i]=A[i];
		}
		
		buildheap();
		//buildheapup();
	}

	void buildheap()
	{
		for(int i=parent(h->count);i>=0;i--)	
		{
			heapify(i);
		}
	}
	
	void buildheapup()
	{
		for(int i=1;i<=h->count;i++)
		{
			int j=i;
			while(parent(j)>=0 && h->array[j] < h->array[parent(j)] )
			{
				int temp=h->array[j];
				h->array[j]=h->array[parent(j)];
				h->array[parent(j)]=temp;
				j=parent(j);
			}
		}
	}

	void insert(int data)
	{
		h->count++;
		if(h->count >= h->capacity)
		{
			resize();
		}
		h->array[h->count]=data;
		
		buildheap();
	}

	void heapify(int i)
	{
		int l,r,min;
		l=leftchild(i);
		r=rightchild(i);
	
		min=i;

		if(l != -1 && h->array[i] > h->array[l])
				min=l;
		
	
		if(r != -1 && h->array[min] > h->array[r])
				min=r;
		
		if(min != i)
		{
			int temp;
			temp=h->array[i];
			h->array[i]=h->array[min];
			h->array[min]=temp;
			heapify(min);
		}
	}

       void heapifymax(int i)
        {
                int l,r,max;
                l=leftchild(i);
                r=rightchild(i);

                max=i;

                if(l != -1 && h->array[i] < h->array[l])
                                max=l;


                if(r != -1 && h->array[max] < h->array[r])
                                max=r;

                if(max != i)
                {
                        int temp;
                        temp=h->array[i];
                        h->array[i]=h->array[max];
                        h->array[max]=temp;
                        heapify(max);
                }
        }

	   void buildheapifymax(int root)
	   {
		   for(int i=parent(h->count);i>=root;i--)
				heapifymax(i);
	   }

	   void buildheapify(int root)
	   {
		   for(int i=parent(h->count);i>=root;i--)
				heapify(i);
	   }

	void heapsort()
	{
		int c=h->count;
		for(int i=h->count;i>=0;i--)
		{
			int temp;
			temp=h->array[0];
			h->array[0]=h->array[i];
			h->array[i]=temp;
			h->count --;
			heapify(0);
		}
		h->count=c;
	}

	int getmin()
	{
		if(h->count == -1)
			return -1;
		else 
			return h->array[0];
	}

	void resize()
	{
		int *a;
		a=h->array;
		h->array=(int*)malloc(sizeof(int)*2*h->capacity);
		for(int i=0;i < h->capacity ;i++)
		{
			h->array[i]=a[i];
		}
		h->capacity=2*h->capacity;
	}	

	void keyalter(int node,int newvalue)
	{
		int oldvalue=h->array[node];
		h->array[node] = newvalue;
		if(newvalue > oldvalue)
		{
			heapify(node);
		}
		else
		{
			while(parent(node)>=0 && h->array[node] < h->array[parent(node)])
			{
				int temp;
				temp=h->array[node];
				h->array[node]=h->array[parent(node)];
				h->array[parent(node)]=temp;
				node=parent(node);
			}
		}
		
	}
	
	void alternating()
	{
		int n=1;
		int lev=1;
		buildheapifymax(0);
		for(int i=1;i<=h->count;i++)
		{
			if(lev%2==0)
			{
				buildheapifymax(i);
			}
			else
			{
				buildheapify(i);
			}
			if(n==2*lev)
			{
				lev++;
				n=0;
			}

			n++;
		}
	}

	int leftchild(int i)
	{
		int left=2*i+1;
		if(left > h->count)
		{
			return -1;
		}
		return left;
	}

	int rightchild(int i)
	{
		int right=2*i+2;
		if(right> h->count)
		{
			return -1;
		}
		return right;
	}
	
	int parent(int i)
	{
		int parent=(i-1)/2;
		if(i==0 || i>h->count)
		{
			return -1;
		}
		return parent;
	}
	
	void display()
	{
		for(int i=0;i<=h->count;i++)
			cout<<h->array[i]<<endl;
	}
};

int main()
{
	Heap he;
	int a[9]={4,8,5,6,7,2,9,1,3};
	cout<<"Buildheap"<<endl;
	he.construct(a,9);
	he.insert(0); 
	he.keyalter(9,2);
	he.keyalter(2,7);
	he.display();
	cout<<"Minimum is: "<<he.getmin()<<endl;
	cout<<"Heapsort"<<endl;
	he.heapsort();
	he.display();
	cout<<"Alternating:"<<endl;	
	he.alternating();
	he.display();
}

