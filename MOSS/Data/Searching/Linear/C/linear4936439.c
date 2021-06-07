#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

int linearSearch(int n, int *S, int key);

int main(void)
{
	int n,q,count=0;
	int *S,*T;
	//入力
	scanf("%d", &n);
	S = (int *) malloc (sizeof (int) * (n+1));//番兵用の+1
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d", &S[i]);
	}
	S[n]=0;
	
	scanf("%d", &q);
	T = (int *) malloc (sizeof (int) * q);
	for(i=0; i<q; i++)
	{
		scanf("%d", &T[i]);
	}
	//線形探索
	for(i=0; i<q; i++)
	{
		if(linearSearch(n, S, T[i]))
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

int linearSearch(int n, int *S, int key)
{
	S[n]=key;
	int i=0;
	while(S[i]!=key)
	{
		i++;
	}
	if(i==n)
	{
		return false;
	}
	return true;
}
