#include<stdio.h>
#define N 100
#define White 0
#define Gray 1
#define Black 2
void dfs_init(void);
void dfs(int);
int tops(void);
void push(int);
void pop(void);
int next(int);

int n, M[N][N];
int color[N],d[N],f[N],co,rem[N];
int S[N*N],top=-1;

int main(){
  int i,j,u,k,v;
  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      M[i][j] = 0; 
    }
  }

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d %d",&u,&k);
    for(j = 0; j < k; j++){
      scanf("%d",&v);
      M[u-1][v-1] = 1;
    }
  }

  dfs_init();
  for(i = 0; i < n; i++){
    if(color[i] == White) dfs(i);
  } 
  
  for(i = 0; i < n; i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}

void dfs_init(){
  int i;
  for(i = 0; i < n; i++){
    color[i] = White;
  }
}

void dfs(int r){
  int u,v;
  
  push(r);
  color[r] = Gray;
  d[r] = ++co;
  
  while(top != -1){
    u = tops();
    v = next(u);
    if(v != -1){
      if(color[v] == White){
	color[v] = Gray;
	d[v] = ++co;
	push(v);
      }
    }
    else {
      pop();
      color[u] = Black;
      f[u] = ++co;
    }
  }
}

int tops(){
  return S[top];
}

void push(int u){
  S[++top] = u;
}

void pop(){
  top--;
}

int next(int u){
  int v;
  for(v = rem[u]; v < n; v++){
    rem[u] = v + 1;
    if(M[u][v]) return v;
  }
  return -1;
}
