#include <iostream>
#include <cstdio>
const int MAXN = 101;
int n, A[MAXN];

using namespace std;

void trace(int A[], int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("%d", A[i]);
		if(i < n-1)
		{
			printf(" ");
		}
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	trace(A, n);
	for(int i = 1; i < n; i++)
	{
		int key = A[i];
		int j = i-1;
		while (i >= 0 && A[j] > key) {
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
		trace(A, n);
	}
	
	return 0;
}
