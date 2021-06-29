#include<iostream>
using namespace std;
int A[100];
void print(int A[], int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		cout<<A[i]<<" ";
	}
	cout<<A[n-1]<<endl;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>A[i];
	}
	print(A,n);
	for (int i = 1; i < n; ++i)
	{
		int v = A[i];
		int j = i-1;
		while(j >= 0 && A[j] > v)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		print(A, n);
	}

	return 0;
}
