//hardcoded version

#include "stdafx.h"
#include<iostream>

using namespace std;

class binaryheap
{	
	public:
	
	int ar[10];
	binaryheap()
	{
		ar[0]=10;
		ar[1]=20;
		ar[2]=30;
		ar[3]=40;
		ar[4]=50;
		ar[5]=80;
		ar[6]=70;
		ar[7]=60;
	}

	int parent(int nodeindex)
	{
			return (nodeindex-1)/2;
	}

	int leftchild(int nodeindex)
	{
			int lc=2*nodeindex+1;
			if(ar[lc] != 0)
					return lc;
			else 
					return -1;
	}
	
	int rightchild(int nodeindex)
	{
			int rc=2*nodeindex+2;
			if(ar[rc] != 0)
					return rc;
			else
					return -1;
	}
};

void main()
{
	binaryheap b;
	cout<<"parent of 2nd node is "<<b.ar[b.parent(2)]<<endl;
	
	cout<<"leftchild of 2nd node is "<<b.ar[b.leftchild(2)]<<endl;
	
	cout<<"rightchild of 2nd node is "<<b.ar[b.rightchild(2)]<<endl;

}