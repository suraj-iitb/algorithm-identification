#include <iostream>
#include <stdio.h>

using namespace std;
int count=0;
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
	count++;
}

void BubbleSort(int a[],int n)
{
	int i,j;
	for(i=0;i<=n-1;i++)
	{
		for(j=n-1;j>=i+1;j--)
		{
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
		}
	}
} 

int main(int argc, char** argv) {
	int i,n;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	BubbleSort(a,n);
	for(i=0;i<n;i++)
	{
		if(i!=n-1)
		cout<<a[i]<<" ";
		else
		cout<<a[i]<<endl;
	}
	printf("%d\n",count);
	
	return 0;
}
