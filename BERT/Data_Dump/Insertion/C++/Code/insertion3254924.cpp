#include <iostream>
using namespace std;

int main() {
int a[100],n;
cin>>n;
for(int i=0;i<n;i++)
cin>>a[i];
for(int i=0;i<n;i++)
{
	if(i==n-1) cout<<a[i]<<endl;
	else cout<<a[i]<<" ";
}
for(int i=1;i<n;i++)
{
	int k=i;
	for(;k>0;k--)
	if(a[k-1]>a[k])
	{
		int temp=a[k];
		a[k]=a[k-1];
		a[k-1]=temp;
	}
	for(int i=0;i<n;i++)
{
	if(i==n-1) cout<<a[i]<<endl;
	else cout<<a[i]<<" ";
}
}
	return 0;
}
