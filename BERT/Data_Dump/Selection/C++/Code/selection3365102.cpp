#include<iostream>
using namespace std;
static const int N= 105;
int Selection_Sort(int a[],int n)	//选择排序 
{
	int minj,count=0;
	for(int i=0;i<n;i++)
	{
		minj=i ;
	for(int j=i+1;j<n;j++)
	{
		if(a[j]<a[minj])
		{
			minj = j;
		}
	}
	if(i!=minj) 
	{
		swap(a[i],a[minj]);
		count++;
	}
	}
	return count; 
}
int main()
{
	int n,count;
	int a[N];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	count=Selection_Sort(a,n);
	for(int i=0;i<n;i++)
	{
		if(i<n-1)
		cout<<a[i]<<' ';
		else 
		cout<<a[i]<<endl;
	}
	cout<<count<<endl;
}
