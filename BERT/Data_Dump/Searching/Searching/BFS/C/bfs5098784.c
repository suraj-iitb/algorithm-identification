#include<stdio.h>

#define INF 99999999

void enter(int);
int out(void);
void bfs(int);

int n;
int G[100][100],d[100],judge[100];
int head=0,tail=0,que[100];

void enter(int x)
{
  que[tail] = x;
  tail = (tail + 1) % 100;
}

int out(void)
{
  int x;
  x = que[head];
  head = (head +1) % 100;
  return x;
}


void bfs(int x)
{
  int i,u;

  for(i=0;i<n;i++) {
    judge[i] = 0;
    d[i] = INF;
  }

  judge[x] = 1;
  d[x] = 0;
  enter(x);

  while(head != tail) {
    u = out();
    for(i=0;i<n;i++) {
      if(G[u][i] == 1 &&judge[i] == 0) {
	judge[i] = 1;
	d[i] = d[u] + 1;
	enter(i);
      }
    }
    judge[u] = 2;
  }

  for(i=0;i<n;i++) {
    printf("%d ",i+1);
    if(d[i] == INF)
      printf("-1\n");
    else
      printf("%d\n",d[i]);
  }
}
 
    
int main()
{
  int x,y,z,i,j;

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      G[i][j] = 0;
    }
  }

  for(i=0;i<n;i++) {
    scanf("%d%d",&x,&y);
    x--; 
    for(j=0;j<y;j++) {
      scanf("%d",&z);
      z--; 
      G[x][z] = 1;
    }
  }

  bfs(0);
  
  return 0; 
}
