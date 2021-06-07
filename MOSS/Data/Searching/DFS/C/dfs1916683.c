#include<stdio.h>
#include<stdlib.h>

#define N 101

void push(int x);
void pop(void);
int isEmpty(void);
int isFull(void);
void visit(int);
void dfs(int);
int next(int, int);

int d[N], f[N], A[N][N], t = 0, top = 0, n, S[N];
char color[N];

int main(){
  int i, j, k, l, m;
  
  scanf("%d",&n);
  for(i = 1; i <= n; i++){
    d[i] = 0;
    f[i] = 0;
    for(j = 1; j <= n; j++){
      A[i][j] = 0;
    }
  }
  for(i = 1; i <= n; i++){
    scanf("%d%d", &l, &m);
    for(j = 1; j <= m; j++){
      scanf("%d", &k);
      A[l][k] = 1; 
    }
  }

  dfs(n);

  for(i = 1; i <= n; i++){
    printf("%d %d %d\n", i, d[i], f[i]);
  }

  return 0;
}

void dfs(int u){
  int i; 

  for(i = 1; i <= u; i++){
    color[i] = 'w';
  }
  t = 0;

  for(i = 1; i <= u; i++){
    if(color[i] == 'w') visit(i);
  }

}

void visit(int r){
  int u, v;

  push(r);
  color[r] =  'g';
  d[r] = ++t;
  while(isEmpty() != 0){
    u = S[top];
    //printf("%d\n",top);
    v = next(u, n);
    if(v != NULL){
      if(color[v] == 'w'){
	push(v);
	color[v] = 'g';
	d[v] = ++t;
      }
      else{
	pop();
	color[u] = 'b';
	f[u] = ++t;
      }
    }
  }

}

int next(int u, int n){
  int i;

  for(i = 1; i <= n; i++){
    if((A[u][i] == 1) && (d[i] == 0)) return i;
  }

  return -1;

}

void push(int x){
  if(isFull() == 0){
    fprintf(stderr, "overfullow");
    exit(8);
  }
  top++;
  S[top] = x;
}

void pop(void){
  if(isEmpty() == 0){
    fprintf(stderr, "underfullow");
    exit(8);
  }
  top--;
}

int isEmpty(void){
  if(top  == 0) return 0; 
  else return 1;
}

int isFull(void){
  if(top >= N -1) return 0; 
  else return 1;
}
