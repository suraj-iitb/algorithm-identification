#include <stdio.h>

int s,head,comp[100],count[100],out[100];
int graph_s[100][100];

void DFS_s(int x){
  int i;
  comp[x]=1;
  count[x]=++s;
  for(i=0;i<head;i++){
    if(graph_s[x][i]==0) continue;
    if(comp[i]==0){
      DFS_s(i);
    }
  }
    comp[x]=2;
    out[x]=++s;
}
  

void DFS_clear(){
  int i;
  for(i=0;i<head;i++) comp[i]=0;
  s=0;
  for(i=0;i<head;i++){
    if(comp[i]==0) DFS_s(i);
  }

  for(i=0;i<head;i++){
    printf("%d %d %d\n",i+1,count[i],out[i]);
  }
}

int main(){
  int nu,out,near,i,j;

  scanf("%d",&head);

  for(i=0;i<head;i++){
    for(j=0;j<head;j++){
      graph_s[i][j]=0;
    }
  }

  
  for(i=0;i<head;i++){
    scanf("%d%d",&nu,&out);
    for(j=0;j<out;j++){
      scanf("%d",&near);
      graph_s[nu-1][near-1]=1;
    }
  }

  DFS_clear();

  
  return 0;
}

