#include<stdio.h>
#define N 100

void dfs(void);
void visit(int);
void push(int);
void pop(void);
int next(int);

int n, color[N], d[N], f[N], time, temp[N], G[N][N];
int S[N*N], top=-1;

int main()
{
  int u, k, i, j, v;

  for(i = 0; i < N; i++){
    for(j = 0; j < N; j++){
      G[i][j] = 0;
    }
  }

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d%d", &u, &k);
    for(j = 0; j < k; j++){
      scanf("%d", &v);
      G[u-1][v-1] = 1;
    }
  }
  
  dfs();

  for(i = 0; i < n; i++) if(color[i] == 1) visit(i);

  for(i = 0; i < n; i++) printf("%d %d %d\n", i+1, d[i], f[i]);

  return 0;
}

//????????????
void dfs(void)
{
  int i;

  for(i = 0; i < n; i++) color[i] = 1; //1 = white
  time = 0;
}

void visit(int r)
{
  int u, v;

  push(r); // Stack S
  color[r] = 2; //2 = GRAY
  d[r] = ++time;

  while(top != -1){
    u = S[top];
    v = next(u);

    if(v != -1){
      if(color[v] == 1){
        color[v] = 2;
	d[v] = ++time;
	push(v);
      }
    }
    else{
      pop();
      color[u] = 3; //3 = BLACK
      f[u] = ++time;
    }
  }
}

void push(int x)
{
    top++;
    S[top] = x;
}

void pop(void)
{
  top--;
}

int next(int u)
{
  int i;

  for(i = temp[u]; i < n; i++){
    temp[u] = i + 1;
    if(G[u][i]) return i;
  }
  return -1;
}
