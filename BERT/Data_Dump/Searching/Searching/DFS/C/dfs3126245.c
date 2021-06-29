#include<stdio.h>
void dfs(int a);
int n,go[101],back[101],link[101],keep[101][101],count=1;
 
int main(){
  int i,j,num;
 
  scanf("%d",&n);
 
  for(i=1;i<=n;i++){
    go[i]=back[i]=0;
    scanf("%d",&num);
    scanf("%d",&link[num]);
    for(j=1;j<=link[num];j++) scanf("%d",&keep[num][j]);
  }
  for(i=1;i<=n;i++){
    if(go[i]==0)dfs(i);
  }
 
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,go[i],back[i]);
  }
  return 0;
}
 
void dfs(int a){
  int i;
  go[a]=count++;
 
  for(i=1;i<=link[a];i++){
    if(go[keep[a][i]]==0){
      dfs(keep[a][i]);
    }
  }
  back[a]=count++;
   
}
