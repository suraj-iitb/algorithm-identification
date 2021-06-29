#include <iostream>
using namespace std;
int n;
int bubblesort(int a[])
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
				count++;
			}
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
	count=bubblesort(a);
	for(int i=0;i<n;i++)
	{
		if(i)cout<<" ";
		cout<<a[i];
	}
	cout<<endl<<count<<endl;
	return 0;
}
