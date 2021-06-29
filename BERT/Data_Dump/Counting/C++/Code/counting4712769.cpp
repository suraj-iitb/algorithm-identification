#include <iostream>
#define RANGE 10010
#define MAX 2000001
using namespace std;

void Counting_Sort(int A[], int B[], int k, int n)
{
	int C[RANGE];
	for (int i = 0;i <= k;i++)
	{
		C[i] = 0;
	}
	for (int i = 1;i <= n;i++)
	{
		C[A[i]]++;
	}
	for (int i = 1;i <= k;i++)
	{
		C[i] += C[i-1];
	}
	for (int i = n;i >= 1;i--)
	{
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
}

int main ()
{
	int n, A[MAX], B[MAX];
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> A[i];
	}
	
	Counting_Sort(A, B, RANGE, n);
	
	
	cout << B[1];
	for (int i = 2;i <= n;i++)
	{
		cout << " " << B[i];
	}
	cout << endl;
	return 0;
 } 
