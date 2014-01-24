#include<iostream>

using namespace std;

class karyheap
{
	int k;
	
	public:
	karyheap(int kary)
	{
		k=kary;
	}

	int parent(int i)
	{
		if(i==0)
			return -1;
		else
			return (i-1)/k;
	}
	
	int child(int i)
	{
		if(i<0)
			return -1;
		else
		{
			for(int c=1;c<=k;c++)
			{
				cout<<"Child"<<c<<" is:"<<k*i+c<<endl;
			}
		}
	}
};

int main()
{
	int k;
	cout<<"Enter k:";
	cin>>k;
	karyheap kary(k);
	cout<<"Parent of 4:"<<kary.parent(4)<<endl;
	cout<<"children of 2:"<<endl;
	kary.child(2);
	
}
