#include <stdio.h>
#define max 100
 
int arry[max][max];
int d[max],f[max];
int n,t=0;

void Depth(int);

int main(){
  int i,j,k,u,v;
 
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    scanf("%d%d",&u,&k);
    for(j=0;j<k;j++){
      scanf("%d",&v);
      arry[u-1][v-1]=1;
    }
  }
  for(i=0;i<n;i++) if(d[i]==0)Depth(i);
 
  for(i=0;i<n;i++) printf("%d %d %d\n",i+1,d[i],f[i]);
  return 0; 
}

void Depth(int i){ 
  int j;
  t++;
  d[i]=t;
  for(j=0;j<n;j++)  if(arry[i][j]!=0 && d[j]==0)Depth(j);
  t++;
  f[i]=t;
}
 
 
