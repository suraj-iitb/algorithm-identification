//未通过 

#include <iostream>
#include <limits.h>

#define MAX 10000

using namespace std;

void counting_sort(int A[], int B[], int n);

int main()
{
	

	int n;
	cin >> n;
	
	int * A = new int [n];
	int * B = new int [n];
	
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	
	counting_sort(A, B, n);
	
	for (int i = 0; i < n; i++)
	{
		if (i) cout << ' ';
		cout << B[i];
	}
	cout << endl;
}




void counting_sort(int A[], int B[], int n)
{
	int C[MAX] = {0};
	
	for (int i = 0; i < n; i++) C[A[i]]++;
	
	for (int i = 1; i <= MAX; i++) C[i] += C[i-1];
	
	for (int i =0; i < n; i++)
	{
		B[--C[A[i]]] = A[i];
	}
}

