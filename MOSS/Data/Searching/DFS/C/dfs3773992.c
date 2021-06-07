#include <stdio.h>
#define max 101
int p[max];
int d[max];
int n,t=0;
int use[max];
int m[max][max];


void cal(int u);

int main (){
 
  int i,j;
  int k,u,r;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&r);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&u);
      m[r][u] = 1;
    }
  }
  i=1;
  while(i<=n){
    if(use[i] == 0){
    t++;
	d[i]=t;
	use[i]=1;
	cal(i);
   }
    i++;
  }

  for(i=1;i<=n;i++){
printf("%d %d %d\n",i,d[i],p[i]);
  }
  return 0;
}
void cal(int u){
  
  int v;
  
  for(v=0;v<max;v++){
    if(m[u][v]==1 && use[v] == 0){
      use[v]=1;t++;
      d[v]=t;
	  cal(v);
    }
  }
    p[u] = ++t;
}
