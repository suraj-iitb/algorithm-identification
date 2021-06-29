#include<stdio.h>
#define BLACK 5
#define GRAY 4
#define WHITE 3
void visit(int);
int d[1000],f[1000],color[1000],time=0,n;
int a[1000][1000];
int main(){
  int i,j,b,num,st,u;
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      a[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&num,&st);
    for(j=0;j<st;j++){
      scanf("%d",&b);
      a[num][b]=1;
    }
  }
  for(u=0;u<n;u++){
    color[u] =  WHITE;
  }
  time = 0;
  for(u=0;u<n;u++){
    if(color[u] == WHITE)
      visit(u);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}
void visit(int u){
  int v;
  color[u] = GRAY; // White vertex u has just been discovered                  
  d[u] = ++time;
  for(v=0;v<=n;v++){ // Explore edge (u,v)                                     
    if(a[u+1][v+1]==1){
      if(color[v] == WHITE){
        visit(v);
      }
    }
  }
  color[u] = BLACK; // Blacken u; it is finished                               
  f[u] = ++time;
}
