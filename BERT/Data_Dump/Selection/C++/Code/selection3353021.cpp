#include <cstdio>
#include <iostream>
using namespace std;
int n,count;
void selectSort(int a[])
{
	int min;
	for(int i=0;i<n;i++)
	{
		min=i;
		for(int j=i;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		if(i!=min)
		{
			swap(a[i],a[min]);
			count++;
		}
	}
}
void print(int a [])
{
	for(int i=0;i<n;i++)
	{
		if(i>0) cout<<' ';
		cout<<a[i];
	}
	cout<<endl<<count<<endl;
}
int main()
{
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	selectSort(a);
	print(a);
	return 0;
}
