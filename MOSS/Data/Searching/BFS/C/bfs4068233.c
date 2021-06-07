#include <stdio.h>
#include <stdlib.h>

#define l 100
#define INFTY (1<<21)
#define max 100000

int n , m[l][l];
int d[l];

int head,tail;
int q[max];

void initialize()
{
	head = tail = 0;
}

int isEmpty()
{
	if(head == tail)
	{
		return 1;
	}
	else{
		return 0;
	}
}

int isFull()
{
	if(head == (tail + 1) % max)
	{
		return 1;
	}
	else{
		return 0;
	}
}

void enqueue(int x)
{
	if(isFull() == 1)
	{
		fprintf(stderr,"エラー");
	}
	else{
		q[tail] = x;
		if(tail + 1 == max)
		{
			tail = 0;
		}
		else{
			tail++;
		}
	}
}

int dequeue()
{
	int x;
	if(isEmpty() == 1)
	{
		fprintf(stderr,"エラー");
		exit(0);
	}
	else{
		x = q[head];
		if(head + 1 == max)
		{
			head = 0;
		}
		else{
			head++;
		}
		return x;
	}
}

void bfs(int s)
{
	enqueue(s);
	for(int i= 0; i <n; i++)
	{
		d[i] = INFTY;
	}
	d[s] = 0;
	int u;
	while(!isEmpty())
	{
		u = dequeue();
		for( int v = 0; v < n; v++)
		{
			if(m[u][v] == 0){continue;}
			if(d[v] != INFTY){continue;}
			d[v] = d[u] + 1;
			enqueue(v);
		}
	}
	for(int i = 0; i < n; i++)
	{
		printf("%d ",i+1);
		if(d[i] == INFTY) printf("-1\n");
		else printf("%d\n",d[i]);
	}
}

int main(void)
{
	int u, k,v;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			m[i][j] = 0;
		}
	}
	for( int i = 0; i < n; i++)
	{
		scanf("%d",&u);
		scanf("%d",&k);
		u--;
		for(int j = 0; j < k; j++)
		{
			scanf("%d",&v);
			v--;
			m[u][v] = 1;
		}
	}
	bfs(0);
	return 0;
}
