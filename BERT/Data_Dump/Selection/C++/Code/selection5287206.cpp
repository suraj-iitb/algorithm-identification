#include <iostream>
using namespace std;
int n;
int selectionsort(int a[])
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			int t=a[i];
			a[i]=a[min];
			a[min]=t;
			count++;
		}
	}
	return count;
}
int main()
{
	int count=0;
	cin>>n;
	int a[100]={0};
	for(int i=0;i<n;i++)
		cin>>a[i];
	count=selectionsort(a);
	for(int i=0;i<n;i++)
	{
		if(i)cout<<" ";
		cout<<a[i];
	}
	cout<<endl<<count<<endl;
	return 0;
}
