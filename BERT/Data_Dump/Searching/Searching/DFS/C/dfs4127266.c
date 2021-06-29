#include<stdio.h>
int m[101][101];
int s[101];
int n[101];
int p,k=0;

void search(x){
  int i;

  s[x]=++k;
  for(i=1;i<=p;i++){
    if(m[x][i]==0) continue;
    if(s[i]>0) continue;

    search(i);
  }
  n[x]=++k;
}

int main(void){
  int u,k,v;
  int i,j;

  scanf("%d",&p);
  for(i=0;i<p;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      m[u][v]=1;
    }
  }
  for(i=1;i<=p;i++){
    if(s[i]==0) search(i);
  }
  for(i=1;i<=p;i++){
    printf("%d %d %d\n",i,s[i],n[i]);
  }
  return 0;
}

    

