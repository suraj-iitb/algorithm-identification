#include<stdio.h>
#define MAX 101

void depthF(int);

int n;
int v[MAX][MAX];
int d[MAX],f[MAX];
int t=0;

int main(){
  
  int i,j,k,a,b;
  int p[MAX];
  scanf("%d",&n);
  
  for(i=1;i<=n;i++){
    p[i]=0;
    d[i]=0;
    f[i]=0;
    
    for(j=1;j<=n;j++){
      v[i][j]=0;
    }
    
  }
  
  for(i=1;i<=n;i++){
    
    scanf("%d%d",&a,&k);
    
    for(j=1;j<=k;j++){
      
      scanf("%d",&b);
      v[a][b]=1;
      p[b]=1;
    }
    v[i][1]=2;
  }

  for(i=1;i<=n;i++){
    
    if(i==1 || p[i]==0){
      depthF(i);
    }
    
  }

  
  for(i=1;i<=n;i++){
    
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  
  return 0;
}



void depthF(int i){
  int j,k;
  
  for(j=1;j<=n;j++){

    if(v[i][j]==1){

      for(k=1;k<=n;k++) v[k][j]=2;

      if(d[i]==0){
	  t++;
	  d[i]=t;
      }
      depthF(j);
    }
      
  }

  if(d[i]==0){
    t++;
    if(d[i]==0) d[i]=t;
  }
  
  t++;
  f[i]=t;
}

