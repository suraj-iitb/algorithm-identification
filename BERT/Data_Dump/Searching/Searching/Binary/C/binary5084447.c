#include <stdio.h>
#define N 1000000

int A[N], n;

int binarysearch(int);

int main()
{
	int i, q, key, cnt = 0;
	
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	
	scanf("%d", &q);
	for(i = 0; i < q; i++)
	{
		scanf("%d", &key);
		if( binarysearch(key)) cnt++;
	}
	
	printf("%d\n", cnt);
	
	return 0;
}

int binarysearch(int key)
{
	int l = 0, r = n, m;
	
	while(l < r)
	{
		m = (l + r) / 2;
		if(key == A[m]) return 1;
		else if(key < A[m]) r = m;
		else if(key > A[m]) l = m + 1;
	}
	
	return 0;
}
