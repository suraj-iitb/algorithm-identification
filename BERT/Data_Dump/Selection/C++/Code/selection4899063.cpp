#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
int count=0;
void swap(int &a,int &b)
{
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void selectionSort(int a[],int n)
{
	int i,j,minj;
	for(i=0;i<n;i++)
	{
		minj=i;
		for(j=i;j<n;j++)
		{
			if(a[j]<a[minj])
				minj=j;
		}
		if(a[i]!=a[minj])
			count+=1;
		swap(a[i],a[minj]);
	}
} 
int main(int argc, char** argv) {
	
	int i,n;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	selectionSort(a,n);
	for(i=0;i<n;i++)
	{
		if(i!=n-1)
		cout<<a[i]<<" ";
		else
		cout<<a[i]<<endl;
	}
	printf("%d",count);
	printf("\n");
	return 0;
}
