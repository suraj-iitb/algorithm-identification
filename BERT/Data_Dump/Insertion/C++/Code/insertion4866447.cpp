#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,a[110];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	cout<<a[0];
	for(int i=1;i<n;i++)
		cout<<" "<<a[i];
	cout<<endl;
		
	int i,j; 
	for(i=1;i<n;i++)
	{
		int temp=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>temp)
				a[j+1]=a[j];
			else
				break;
		}
		a[j+1]=temp;
		cout<<a[0];
		for(int k=1;k<n;k++)
		{
			cout<<" "<<a[k];
		}
		cout<<endl;
	}

	return 0;
}
