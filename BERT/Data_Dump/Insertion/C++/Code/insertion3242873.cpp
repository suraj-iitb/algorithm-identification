#include<iostream>
using namespace std;
int main()
{
	int n,A[100];
	cin>>n;
	for(int i=0 ; i<n ; i++)
	{
		int a;
		cin>>a;
		A[i] = a;
	}
	for(int i=0 ; i<n ; i++)
	{
		cout<<A[i];
		if(i != n-1)
		{
			cout<<" ";
		}
	}
	cout<<endl;
	for(int i=1 ; i<n ; i++)
	{
		int c = A[i];
		int j = i-1;
		while(j >= 0 && A[j] > c)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = c;
		for(int k=0 ; k<n ; k++)
		{
			cout<<A[k];
			if(k != n-1)
		{
			cout<<" ";
		}
		}
		cout<<endl;
	}
	return 0;
}
