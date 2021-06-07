#include <stdio.h>

#define I 10000000
#define MAX 100

int n, m[MAX][MAX], Q[MAX], head = 0, tail, d[MAX];

void enqueue(int x)
{
  Q[tail] = x;
  tail = (tail+1)%MAX;
}

int dequeue()
{
  int x;

  x = Q[head];
  head = (head+1)%MAX;

  return x;
}

void bfs(int s)
{
  int q, i, u;

  enqueue(s);
  for (i = 0; i < n; i++)
    d[i] = I;
  d[s] = 0;
  while (head != tail){
    u = dequeue();
    for (i = 0; i < n; i++){
      if (m[u][i] == 0)
	continue;
      if (d[i] != I)
	continue;
      d[i] = d[u] + 1;
      enqueue(i);
    }
  }
  for (i = 0; i < n; i++){
    printf("%d ",i+1);
    if (d[i] == I)
      printf("-1\n");
    else
      printf("%d\n",d[i]);
  }
}

int main()
{
  int i, j, a, u, k;

  scanf("%d",&n);
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      m[i][j] = 0;
  for (i = 0; i < n; i++){
    scanf("%d%d",&u,&k);
    for (j = 0; j < k; j++){
      scanf("%d",&a);
      m[u-1][a-1] = 1;
    }
  }
  tail = n;
  bfs(0);
    
  return 0;
}

