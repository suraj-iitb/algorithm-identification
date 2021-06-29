#include<iostream>

using namespace std;
int selectionSort(int A[], int N);
int main()
{	
	int A[100];
	int N;
	int sw;
	cin>>N;
	for (int i = 0; i < N; ++i)
	{
		cin>>A[i];
	}
	sw=selectionSort(A,N);
	for (int i = 0; i < N; ++i)
	{	
		if(i) cout<<" ";
		cout<<A[i];
	}
	cout<<endl;
	cout<<sw<<endl;
	return 0;
}
int selectionSort(int A[], int N)
{
	int i,j,sw=0,minj;
	for(i=0; i<=N-1; ++i)
	{	
		minj=i;
		for(j=i; j<=N-1; ++j)
		{
			if (A[j]<A[minj])
			{
				minj=j;
			}
		}
		if(i!=minj){
			++sw;}
		swap(A[i],A[minj]);	
	}
	return sw;
}
