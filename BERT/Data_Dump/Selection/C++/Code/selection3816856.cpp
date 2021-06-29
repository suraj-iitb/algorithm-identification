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
int SelectSort(int* a,int n)
{
	int num=0;
	for(int i=1;i<=n;i++)
	{
		int mini=i;	//假设a[i]是最小的
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]<a[mini])mini=j;
		}
		if(mini!=i){
			int temp=a[i];
			a[i]=a[mini];
			a[mini]=temp;
			num++;
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
	int num=SelectSort(a,n);
	PrintArray(a,n);
	cout<<num<<endl;
	return 0;
}
