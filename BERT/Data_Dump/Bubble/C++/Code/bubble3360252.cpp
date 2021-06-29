#include<iostream>
#include<cmath>
using namespace std;
int a[100],n,t=0;
void mpsort(int n)
{
	int i,j;
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				t++;
			}
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	mpsort(n);
	for(int i=0;i<n-1;i++)
	cout<<a[i]<<" ";
	cout<<a[n-1]<<endl;
	cout<<t<<endl;
	return 0;
 } 
