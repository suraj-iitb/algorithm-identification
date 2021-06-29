#include <stdio.h>

#define N 10000

int linearsearch(int A[], int key, int n)
{
	int i = 0;
	A[n] = key;
	while(A[i] != key) i++;
	return i != n;
}

int main()
{
	int A[N], n, q, i, key, cnt = 0;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	scanf("%d", &q);
	for(i = 0; i < q; i++)
	{
		scanf("%d", &key);
		if( linearsearch(A, key, n)) cnt++;
	}
	
	printf("%d\n", cnt);
	
	return 0;
}
