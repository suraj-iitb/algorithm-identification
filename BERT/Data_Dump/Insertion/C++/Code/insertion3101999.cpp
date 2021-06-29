#include<iostream>
#include<algorithm>
using namespace std;
#define max 6
int A[6];
int trace(int num[],int n)
{
	for(int k=0;k<n;k++)
	{
		if(k>0)
		cout<<" ";
		cout<<A[k];
	}
	cout<<endl;
}
int insertionSort(int num[],int n)
{
	for(int i=1;i<n;i++)
	{
		int v=num[i];
		int j=i-1;
		while(j>=0&&(num[j]>v))
		{
			num[j+1]=num[j];
			num[j--]=v;
		}
		trace(num,n);
	
	}
	return 0;
}
int main()
{
	int nn;
	cin>>nn;
	for(int i=0;i<nn;i++)
	{
		cin>>A[i];
	}
	trace(A,nn);
	
	
	insertionSort(A,nn);

	return 0;
}
