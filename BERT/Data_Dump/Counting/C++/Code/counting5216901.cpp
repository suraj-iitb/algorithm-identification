#include<iostream>
#define M 10002
#define MAX 2000001

using namespace std;

void countingsort(int A[], int B[], int k)
{
	int C[M];
	for(int i=0;i<M;i++)
	{
		C[i]=0;
	}
	for(int i=0;i<k;i++)
	{
		C[A[i]]++;
	}
	for(int i=1;i<M;i++)
	{
		C[i]=C[i]+C[i-1];
	}
	for(int j=k-1;j>=0;j--)
	{
		B[C[A[j]]]=A[j];
		C[A[j]]--;
	}
}
int main()
{
	int n;
	cin>>n;
	int A[MAX], B[MAX];
	for(int i=0;i<n;i++) cin>>A[i];
	countingsort(A,B,n);
	for(int i=1;i<=n;i++)
	{
		if(i!=1)cout<<" ";
		cout<<B[i];
	}
	cout<<endl;
	return 0;
}
