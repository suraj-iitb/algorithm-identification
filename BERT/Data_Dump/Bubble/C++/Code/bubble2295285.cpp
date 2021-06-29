#include <iostream>
using namespace std;
void printArr(int *a,int n)
{
	for(int i=0;i<n;i++)
	{
		if(i>0) cout << " ";
		cout << a[i];
	}
	cout << "\n";
}
int bubbleSort(int *a,int n)
{
	int exchangeCount=0;
	int j,temp;
	int flag = 1;
	while(flag==1)
	{
		flag=0;
		for(j=n-1;j>=1;j--)
		{
			if(a[j]<a[j-1])
			{
				exchangeCount++;
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				flag=1;
			}
		}
	}
	return exchangeCount;
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	int count=bubbleSort(a,n);
	printArr(a,n);
	cout << count << endl;
	return 0;
}
