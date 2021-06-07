#include <stdio.h>

#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void push(int);
void pop(void);
void dfs(int);
void dfs_pre(void);
int next(int);

int S[MAX],top;
int M[MAX+1][MAX+1],D[MAX+1],F[MAX+1],colr[MAX+1];
int n,count;
int nt[MAX+1];

int main(){
  int i,j,u,k,v;
  
  scanf("%d",&n);
  
  for(i=0;i<n+1;i++){
    for(j=0;j<n+1;j++){
      M[i][j]=0;
    }
  }
  
    for(i=1;i<=n;i++){
      scanf("%d %d",&u,&k);
      
      for(j=1;j<=k;j++){
        scanf(" %d",&v);
        
        M[u][v] = 1;
      }
    }

    dfs_pre();
    
    return 0;
}


void push(int x){

  top++;
  S[top] = x;
 
}

void pop(void){
  top--;
  }

 void dfs_pre(void){
   int u,i;

   for(i=0;i<n+1;i++){
     colr[i] = WHITE;
     nt[i] = 0;
   }
   count=0;
   
   for(u=1;u<=n;u++){
     if(colr[u] == WHITE)dfs(u);
   }

   for(i=1;i<=n;i++){
     printf("%d %d %d\n",i,D[i],F[i]);
   }
 }

void dfs(int r){
  int i,j,u;
  int v = 0;

  for(i=0;i<n+1;i++)nt[i] = 0;
  
  push(r);
  colr[r] = GRAY;
  D[r] = ++count;
  
  while(top > 0){
    u = S[top];
    v = next(u);
    
    if( v != 0 ){
      if(colr[v] == WHITE){
        colr[v] = GRAY;
        D[v] = ++count;
        push(v);
      }
    }
    
    else{
      pop();
      colr[u] = BLACK;
      F[u] = ++count;
    }
  }        
}
int next(int u){
  int v;

  for(v = nt[u]+1;v <= n;v++){
    nt[u] = v;
    if(M[u][v])return v;
  }
  return 0;
}

