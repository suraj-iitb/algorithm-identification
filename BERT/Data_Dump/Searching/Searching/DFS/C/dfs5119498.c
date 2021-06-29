#include<stdio.h>
 
#define N 100
 
int num, M[N][N];
int a[N], d[N], f[N],T;

void visit(int u)
{
	int i;
	a[u] = 1;
	T++;
	d[u] = T;
	
	for(i=0; i<num; i++)
	{
		if(M[u][i] == 0) continue;
		if(a[i] == 0)visit(i);
	}
	
	a[u] = 2;
	T++;
	f[u] = T;
}
  
int main(void)
{
	int i, j, v, next, k;
	
	scanf("%d", &num);
	
	for(i=0; i<num; i++)
	{
		a[i] = 0;
		for(j=0; j<num; j++)
		{
			M[i][j] = 0;
		}
	}
	
	for(i = 0; i<num; i++)
	{
		scanf("%d %d", &v, &k);
		
		for(j=0; j<k; j++)
		{
			scanf("%d", &next);
			
			M[v-1][next-1] = 1;
		}
	}
	
	for(i=0; i<num; i++)
	{
		if(a[i]==0) visit(i);
	}
	
	for(i=0; i<num; i++)
	{
		printf("%d %d %d\n", i+1, d[i], f[i]);
	}
	
	return 0;
}
 


