
#include<stdafx.h>
#include<iostream>

using namespace std;


void display(int A[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<endl;
	}
}

void BubbleSort(int A[],int n)
{
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<i-1;j++)
		{
			if(A[i]>A[i+1])
			{
				int temp= A[i];
				A[i]=A[i+1];
				A[i+1]=temp;
			}
		}
	}
	display(A,5);
}

void InsertionSort(int A[],int n)
{
	int j,v;
	for(int i=1;i<=n-1;i++)
	{
		v=A[i];
		j=i;
		while(A[j-1] > v && j>=1)
		{
			A[j]=A[j-1];
			j--;
		}
		A[j]=v;
	}
	display(A,5);
}

void SelectionSort(int A[],int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			min=i;
			if(A[j]<A[min])
			{
				min=j;
			}
		}
		
		int temp=A[min];
		A[min]=A[i];
		A[i]=temp;
	}
	display(A,5);
}

void Merge(int A[],int temp[],int left,int mid,int right)
{
	int i,left_end,size,temp_pos;
	left_end=mid-1;
	temp_pos=left;
	size=right-left+1;
	
	while(left<=left_end && mid<=right)
	{
		if(A[left] <=A[mid])
		{
			temp[temp_pos++]=A[left++];
		}
		else
		{
			temp[temp_pos ++] =A[mid ++];
		}
	}
	
	while(left<=left_end)
	{
		temp[temp_pos++]=A[left++];
	}
	
	while(mid<=right)
	{
		temp[temp_pos ++]= A[mid ++];
	}
	
	for(i=0;i<=size;i++)
	{
		A[right--]=temp[right--];
	}
}

void MergeSort(int A[],int temp[],int left,int right)
{
	int mid;
	if(right > left)
	{
		mid=(right+left)/2;
		MergeSort(A,temp,left,mid);
		MergeSort(A,temp,mid+1,right);
		Merge(A,temp,left,mid+1,right);
	}
}

int Partition(int A[],int low,int high)
{
	int left=low;
	int right=high;
	int pivot_item=A[low];

	while(left<right)
	{
		while(A[left] <= pivot_item)
				left++;
		while(A[right] > pivot_item)
				right--;

		if(left<right)
		{
			int temp=A[left];
			A[left]=A[right];
			A[right]=temp;
		}
	}

	A[low]=A[right];
	A[right]=pivot_item;
	return right;
}

void QuickSort(int A[],int low,int high)
{
	int pivot;
	if(high >low)
	{
		pivot=Partition(A,low,high);
		QuickSort(A,low,pivot-1);
		QuickSort(A,pivot+1,high);
	}
}


void main()
{
	int A[5]={5,4,3,2,1};
	int temp[5];
	cout<<"Insertion"<<endl;
	InsertionSort(A,5);
	cout<<"Selection"<<endl;
	SelectionSort(A,5);
	cout<<"Bubble"<<endl;
	BubbleSort(A,5);
	cout<<"Quick"<<endl;
	QuickSort(A,0,5);
	cout<<"Merge"<<endl;
	MergeSort(A,temp,0,5);
}