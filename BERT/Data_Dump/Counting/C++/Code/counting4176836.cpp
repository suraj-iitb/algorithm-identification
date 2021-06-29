#include <bits/stdc++.h>

using namespace std;

void printVector(vector<int> A, int n)
{
	int i;
	for(i = 0; i < n-1; i++)
		printf("%d ", A[i]);
	printf("%d\n", A[i]);
}

void countingSort(vector<int> A, vector<int> B, vector<int> C, int MIN, int k, int n)
{
	for(int i = 0; i < n; i++)
		C[A[i]-MIN]++;
	
	for(int i = 1; i < k; i++)
		C[i] += C[i-1];
	
	for(int i = n-1; i >= 0; i--)
	{
		B[C[A[i]-MIN]-1] = A[i];
		C[A[i]-MIN]--;
	}
	
	for(int i = 0; i < n; i++)
		A[i] = B[i];
	
	printVector(A, n);
}

int main()
{
	int n, m, MIN = 1 << 25, MAX = 0, k = 0;
	scanf("%d", &n);
	
	vector<int> A;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		
		A.push_back(m);
		
		if(A[i] > MAX)
			MAX = A[i];
		if(A[i] < MIN)
			MIN = A[i];	
	}
	
	k = MAX-MIN + 1;
	
	vector<int> B(n);
	vector<int> C(k);
	
	countingSort(A, B, C, MIN, k, n);
	
	return 0;
}
