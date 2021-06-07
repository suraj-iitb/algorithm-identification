#include <stdio.h>

int A[100][100],n,d[101],f[101];

void bfs(){
  int i,v;
  int a=0,z=0;
  
  for(i=1;i<=n;i++)d[i]=-1;

  f[z++]=1;
  d[1]=0;

  while(a!=z){
    v=f[a++];
      for(i=1;i<=n;i++){
	if(d[i]==-1&&A[v-1][i-1]==1){
	  d[i]=d[v]+1;
	  f[z++]=i;
	}
      }
  }
}

int main(){
  int i,j;
  int x,y,z;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      A[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&x,&y);
    x--;
    for(j=0;j<y;j++){
      scanf("%d",&z);
      z--;
      A[x][z]=1;
    }
  }

 
  bfs();

  for(i=1;i<=n;i++) printf("%d %d\n",i ,d[i]);

  return 0;
}


