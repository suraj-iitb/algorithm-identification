#include<iostream>
using namespace std;

void insertionSort(int A[],int N)
{
	for(int i=0;i<N;i++)
	{
		int v = A[i];
		int j = i-1;
		while (j>= 0 && A[j] >v)
		{
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		for(int i =0;i<N-1;i++)cout<<A[i]<<" ";
		cout<<A[N-1]<<endl;
	}
}

int main()
{
	int N;cin>>N;
	int A[100];for(int i=0;i<N;i++)cin>>A[i];
	insertionSort(A,N);
	return 0;
}
