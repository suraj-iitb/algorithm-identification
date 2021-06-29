#include<iostream>
#include<cstdio>
using namespace std;
const int MAX = 2000001;
const int VMAX = 10000;

int main(int argc, char const *argv[])
{
	unsigned short *A, *B;

	int C[VMAX+1];
	int n;
	cin>>n;
	A = new unsigned short[n+1];
	B = new unsigned short[n+1];
	for (int i = 0; i < VMAX; ++i)
		{
			C[i] = 0;
		}
	for (int i = 0; i < n; ++i)
	{
		scanf("%hu",&A[i+1]);
		C[A[i+1]]++;
	}
	for (int i = 1; i <= VMAX; ++i)
	{
		C[i] = C[i-1] + C[i];
	}
	for (int j = n; j >= 1; --j)
	{
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
	for (int i = 1; i <= n; ++i)
	{	
		if(i-1) cout<<" ";
		cout<<B[i];
	}
	cout<<endl;
	return 0;
}
