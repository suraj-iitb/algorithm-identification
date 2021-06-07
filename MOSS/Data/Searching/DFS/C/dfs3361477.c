#include <stdio.h>
#define WHITE  0
#define GRAY   1
#define BLACK  2
#define NIL   -1
#define N    101

typedef struct{
  int id;
  int k;
  int v[1000];
}DATA;

void dfs(int,int);
void visit(int,int);
void push(int);
void pop(void);
int top(void);
int next(int,int);
  
int time,count=0;
int S[N],d[N],f[N],color[N],G[N][N];
DATA data[100];

int main() {

  int i,j,n;
  
  scanf("%d",&n);
  for(i = 1; i <= n; i++) {
    scanf("%d%d",&data[i].id,&data[i].k);
    if(data[i].k == 0 ) data[i].v[1] = 0;
    
    for(j = 1; j <= data[i].k; j++) {
      scanf("%d",&data[i].v[j]);
      if(data[i].v[j] == data[i].v[data[i].k]) data[i].v[(data[i].k)+1] = NIL;
    }
  }

  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      	G[i][j] = 0;   
    }
  }
  
  for(i = 1; i <= n; i++) {
    for(j = 1; j <= n; j++) {
      	G[i][data[i].v[j]] = 1;   
    }
  }


  dfs(data[1].id,data[n].id);

for(i = 1; i <= n; i++) {
  printf("%d %d %d\n",data[i].id,d[i],f[i]);
 }

return 0;
}

void dfs(int u,int V)
{
  int i;
  for(i = u; i < V; i++) {
    color[i] = WHITE;
  }
  time = 0;
  for(i = u; i < V; i++) {
    if(color[i] == WHITE) visit(i,V);
  }
}

void visit(int r,int V)
{
  int u,v;
  
  push(r);
  color[r] = GRAY;
  d[r] = ++time;
  
  while(count != 0) {
    u = top();
    v = next(u,V);
    if(v != 0) {
      if(color[v] == WHITE) {
	push(v);
	color[v] = GRAY;
	d[v] = ++time;
      }
    }
    else {
      pop();
      color[u] = BLACK;
      f[u] = ++time;
    }
  }
  
}

void push(int r)
{
  S[count] = r;
  count++;
}

void pop(void)
{
  count--;
}

int top(void)
{
  return S[count-1];
}

int next(int u,int V)
{
  int i,flag=0;
for(i = 1; i <= V; i++) {
  if(G[u][i] == 1) {
    G[u][i] = 0;
    flag++;
    break; 
}
 }
 if(flag == 0)
   return 0;
 else
   return i;
}


