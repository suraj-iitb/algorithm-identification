#include<iostream> 
using namespace std;
static const int N = 105;

int Bubble_Sort(int a[],int n)  //冒泡排序 升序 
{
	int count=0,temp;
	for(int i=1;i<n;i++)
	for(int j=0;j<n-i;j++)
	{
		if(a[j]>a[j+1])
		{
			count++;
			temp = a[j];
			a[j] = a[j+1];
			a[j+1]= temp;
		 } 
	}
	return count;
}

int main()
{
	int n,count;
	int a[N];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	count=Bubble_Sort(a,n);
	for(int i=0;i<n;i++)
	{
		if(i<n-1)
		cout<<a[i]<<' ';
		else
		cout<<a[i]<<endl;
	}
	cout<<count<<endl;
}
