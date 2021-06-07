#include <stdio.h>

#define N 100
#define W 0
#define G 1
#define B 2

int n,T[N][N];
int color[N],d[N],f[N],tt;
int nt[N];
int top = 0; 
int S[N];

void push(int key)
{
	top++;
	S[top] = key;
}

int pop()
{
	int tmp;

	tmp = S[top];
	top--;
	return tmp;
}



int r_next_node(int u)
{
	int v;

	//printf("next関数が呼び出され、ntは%d\n",nt[u]);

	for(v = nt[u]; v < n; v++)
	{
		nt[u] = v + 1;
		if(T[u][v])return v;
	}

	return -1;
}

void Dfs_stack(int r)
{
	int i,u,v;

	for(i = 0; i < n; i++)
	{
		nt[i] = 0;
	}

	push(r);
	color[r] = G;
	d[r] = ++tt;
	while(top != 0)
	{
		u = S[top];
		v = r_next_node(u);
		if(v != -1)
		{
			if(color[v] == W)
			{
				color[v] = G;
				d[v] = ++tt;
				push(v);
			}
		}
		else
		{
			pop();
			color[u] = B;
			f[u] = ++tt;
		}
	}
}

void depth_serch()
{
	int i,u;
	for(i = 0; i < n; i++)
	{
		color[i] = W;
		nt[i] = 0;
	}
	tt = 0;

	for(u  =0; u < n; u++)
	{
		if(color[u] == W)
		{
			Dfs_stack(u);
		}
	}
	for( i = 0 ; i < n;  i++)
	{
		printf("%d %d %d\n",i+1,d[i],f[i]);
	}
}




int main()
{
	int i,j,u,k,v;


	scanf("%d",&n);

	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			T[i][j] = 0;
		}
	}


	for(i = 0; i < n; i++)
	{
		scanf("%d%d",&u,&k);
		u--;
		for(j = 0; j < k; j++)
		{
			scanf("%d",&v);
			v--;
			T[u][v] = 1;

		}
	}

	depth_serch();	

	return 0;

}


