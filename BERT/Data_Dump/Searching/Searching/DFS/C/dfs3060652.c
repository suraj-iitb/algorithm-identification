#include<stdio.h>
#define RANGE 101
int g[RANGE][RANGE],d[RANGE],f[RANGE];
int ts=0,n;

void search(x){
  int i;
  ts++;
  d[x]=ts;
  for(i=0;i<n;i++){
    if(g[x][i]!=0 && d[i]==0){
      search(i);
    }
  }
  ts++;
  f[x]=ts;
}


int main(){
  int i,j,m,l,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&m);
    scanf("%d",&l);
    for(j=0;j<l;j++){
      scanf("%d",&k);
      g[m-1][k-1]=1;
    }
  }
  for(i=0;i<n;i++){
    if(d[i]==0) search(i);
  }

  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,d[i],f[i]);
  }
  return 0;
}



