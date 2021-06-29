#include<stdio.h>
#include<stdlib.h>
 
#define WHITE 10000
#define BLACK 10001
#define GRAY 10002
#define TRUE 1
#define FALSE 0
#define NUL NULL
 
void dfs(void);
void visit(int);
void push(int);
void pop(void);
int isEmpty(void);
 
int v[101][101],s[101],time1,n;
int *d,*f,*color;
int top = 0;
 
int main(){
  int u,i,j,w,k;
 
  scanf("%d",&n);
 
  d = malloc(sizeof(int) * (n + 1));
  f = malloc(sizeof(int) * (n + 1));
  color = malloc(sizeof(int) * (n + 1));
 
  for(i = 1;i <= n;i++){
    scanf("%d %d",&u,&k);
    for(j = 1;j <= k;j++){
      scanf("%d",&w);
      v[i][w] = 1;
    }
  }
 
  dfs();
 
  for(i = 1;i <= n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
 
  return 0;
}
 
void dfs(){
  int i = 1,j = 1;
  for(i = 1;i <= n;i++){
      color[i] = WHITE;
  }
 
  time1 = 0;
 
  for(i = 1;i <= n;i++){
    if(color[i] == WHITE){
      visit(i);
    }
  }    
 
}
 
void visit(int r){
  int u,vv=NUL,i;
 
  push(r);
  color[r] = GRAY;
  d[r] = ++time1;
 
  while(isEmpty() == FALSE){
    vv=NUL;
    u = s[top];
    for(i = 1;i <= n;i++){
    if(v[u][i] == 1 && color[i] == WHITE){
      vv = i;
      break;
    }
     
    }
    if(vv != NUL){
      if(color[vv] == WHITE){
    push(vv);
    color[vv] = GRAY;
    d[vv] = ++time1;
      }
    }
    else{
      pop();
      color[u] = BLACK;
      f[u] = ++time1;
    }
  }
}
 
void push(int x){
  top++;
  s[top] = x;
}
 
int isEmpty(){
  if(top == 0){
    return TRUE;
  }
  else{
    return FALSE;
  }
}
 
void pop(){
  top--;
}
