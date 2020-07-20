#include<iostream>
using namespace std;
int main()
{
	int n,A[100],flag = 0;
	cin>>n;
	for(int i=0 ; i<n ; i++)
	{
		cin>>A[i];
	}
	for(int i=0 ; i<n-1  ;i++)
	{
		for(int j=n-1 ; j>i ; j--)
		{
			if(A[j]<A[j-1])
			{
				int temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
				flag++;
			}
		}
	}
	for(int i=0 ; i<n ; i++)
	{
		cout<<A[i];
		if(i != n-1)
		{
			cout<<" ";
		}
	}
	cout<<endl<<flag<<endl;
}
