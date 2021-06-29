#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int binarySearch(int n, int *S, int key);

int main(void)
{
	int n,q,count=0;
	int *S,*T;
	//入力
	scanf("%d", &n);
	S = (int *) malloc (sizeof (int) * n);
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d", &S[i]);
	}
	
	
	scanf("%d", &q);
	T = (int *) malloc (sizeof (int) * q);
	for(i=0; i<q; i++)
	{
		scanf("%d", &T[i]);
	}
	//二分探索
	for(i=0; i<q; i++)
	{
		if(binarySearch(n, S, T[i]))
		{
			count++;
		}
	}
	
	//出力
	printf("%d\n", count);
	
	//解放
	free(T);
	T = NULL;
	free(S);
	S = NULL;
	return 0;
}

int binarySearch(int n, int *S, int key)
{
	
	int left = 0;
	int right = n;
	int mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(S[mid] == key)
		{
			return true;
		}
		else if(key < S[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return false;
}
