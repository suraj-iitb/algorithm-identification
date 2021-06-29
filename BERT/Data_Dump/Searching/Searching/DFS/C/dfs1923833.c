#include<stdio.h>
#define N 101
#define WHITE 0
#define GRAY 2
#define BLACK 1
typedef struct{
  int v[N];
  int dis;
  int fin;
  int color;
  int next;
} Graph;
Graph g[N];
int time,n;
int s[N],top=0;

void push(int x)
{
  s[++top] = x;
}

int pop()
{
  return s[--top+1];
}

void visit(int r)
{
  int ver,u,x;
  push(r);
  g[r].color = GRAY;
  g[r].dis = ++time;
  while(top!=0) {
    x = s[top];
    ver = g[x].v[g[x].next++];
    if(ver!=0) {
      if(g[ver].color == WHITE) {
	      push(ver);
	      g[ver].color = GRAY;
	      g[ver].dis = ++time;
      }
    }
    else {
      u = pop();
      g[x].color = BLACK;
      g[x].fin = ++time;
    }
  }
}

void dfs()
{
  int i;
  for(i=1; i<=n; i++)
    g[i].color = WHITE;
  for(i=1; i<=n; i++)
    if(g[i].color == WHITE)
      visit(i);
}

int main()
{
  int i,j,u,k;

  scanf("%d",&n);
  for(i=0; i<n; i++) {
    scanf("%d%d",&u,&k);
    for(j=0; j<k; j++) {
      scanf("%d",&g[u].v[j]);
    }
  }
  dfs();
  for(i=1; i<=n; i++)
    printf("%d %d %d\n",i,g[i].dis,g[i].fin);
  return 0;
}
