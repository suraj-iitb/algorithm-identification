#include <cstdio>
#include <iostream>
using namespace std;
int n;
void print(int a[])
{
	for(int i=0;i<n-1;i++) cout<<a[i]<<' ';
	
	cout<<a[n-1]<<'\n';
}
int main()
{
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	print(a);
	for(int i=1;i<n;i++)
	{
		int f=a[i];
		int j=i-1;
		while(a[j]>f && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=f;
		print(a);
	}
	return 0;
} 
