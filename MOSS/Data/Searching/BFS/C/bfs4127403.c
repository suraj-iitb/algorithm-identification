#include<stdio.h>
#define N 100

void visit(int);
void vi(int);

int n,d[N+1],cnt=0,adj[N+1][N+1],count;

int main()
{
  int i,j,u,k,v;

  scanf("%d",&n);

  for(i = 0; i <= n; i++){
    d[i] = 99;
    for(j = 0; j <= n; j++){
      adj[i][j] = 0;
    }
  }
  
  for(i = 0; i < n; i++){
    scanf("%d %d",&u,&k);
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      adj[u][v] = 1;
    }
  }
  visit(1);

  for(i = 1; i <= n; i++){
    if(d[i] == 99)d[i] = -1;
    printf("%d %d\n",i,d[i]);
  }

  return 0;
}
    
void visit(int u){
  int i;
  
  d[u] = cnt;

  while(1){
    if(u == n+1)break;
  //for(i = 1; i <= n; i++){
  //if(adj[u][i] == 1){
  //if(d[i] > cnt){
  //cnt++;
  //visit(i);
  //cnt--;
    for(i = 1; i <= n; i++){
      if(adj[u][i] == 1){
	if(d[i] > cnt+1){
	  d[i] = cnt+1;
	  count = d[i];
	  vi(i);
	}
      }
    }
    u++;
    cnt = d[u];
    if(d[u] ==99){
      while(1){
	u++;
	if(u == n+1)break;
	if(d[u] < 99){
	  cnt = d[u];
	  break;
	}
      }
    }
  }
  
}

void vi(int u){
  int i;
  for(i = 1; i <= n; i++){
    if(adj[u][i] == 1){
      if(d[i] > count+1)
	d[i] = count+1;
    }
  }
}

