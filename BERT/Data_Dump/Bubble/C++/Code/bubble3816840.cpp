#include<iostream>
using namespace std;
void PrintArray(int* a,int n)
{
	for(int i=1;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[n]<<endl;
}
int BullleSort(int* a,int n)
{
	int flag=1;
	int num=0;
	for(int i=1;flag;i++) 
	{
		flag=0;		//若下列循环不发生交换则已经有序，交换过则令flag=1 
		for(int j=n;j>i;j--)
		{
			if(a[j]<a[j-1])
			{
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				flag=1;
				num++; 
			}
		 } 
	}
	return num;
}
int main()
{
	int a[101];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	int num=BullleSort(a,n);
	PrintArray(a,n);
	cout<<num<<endl;
	return 0;
}
