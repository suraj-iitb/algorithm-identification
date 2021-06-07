#include<stdio.h>
#define N 101
#define BLACK 2
#define GRAY 1
#define WHITE 0
int dfs(int);
int n,a[N][N],color[N],z,b[N],c[N];
int main(){
  int i,j,k,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      a[i][j]=0;
    }
  }
  for(i=0;i<n;i++){
    i++;
    i--;
    i++;
    scanf("%d%d",&i,&k);
    i--;
    for(j=0;j<k;j++){
      scanf("%d",&v);
      v--;
      a[i][v]=1;
    }
  }
  z=0;
  for(i=0;i<n;i++)color[i]=WHITE;
  for(i=0;i<n;i++){
    if(color[i]==WHITE)dfs(i);
  }
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,b[i],c[i]);
  }
  return 0;
}

int dfs(int i){
  int j;
 
  
  color[i]=GRAY;
   z++;
  b[i]=z;
  for(j=0;j<n;j++){
    if(a[i][j]==0)continue;
    else if(color[j]==WHITE)dfs(j);
  }
  color[i]=BLACK;
  z++;
  c[i]=z;
  
}


