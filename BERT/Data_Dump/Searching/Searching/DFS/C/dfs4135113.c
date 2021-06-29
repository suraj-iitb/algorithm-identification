#include<stdio.h>
#define MAX 100
#define white 0
#define black 2
#define gray 1

void dfs(void );
void dvisit(int );

int n;
int Adj[MAX][MAX],d[MAX],f[MAX];
int color[MAX],time;

int main(){
  int u,v,k,i,j;;
  scanf("%d", &n);
   for(i=0; i<n; i++){
     for(j=0;j<n;j++)
      Adj[i][j]=0;
  }

  for(i=0; i<n; i++){
    scanf("%d", &u);
    scanf("%d", &k);
    u--;
  for(j=0;j<k;j++){
      scanf("%d", &v);
      v--;
      Adj[u][v]=1;
  }
  }
   
  dfs();

  return 0;
}

void dfs(void ){
  int u;
  for(u=0;u<n;u++){
    color[u]=white;}
  time=0;
  
  for(u=0;u<n;u++){
    if(color[u]==white)dvisit(u);}
  for(u=0;u<n;u++){
    printf("%d %d %d\n", u+1,d[u],f[u]);
  }
}

void dvisit(int u){
  int v;
  color[u]=gray;
  time+=1;
  d[u]=time;
  for(v=0;v<n;v++){
    if(Adj[u][v]==0)continue;
    if(color[v]==white){
      dvisit(v);}}color[u]=black;
  time+=1;
  f[u]=time;}

