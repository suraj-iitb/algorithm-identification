#include <stdio.h>
#define N 101

int n,hi[N][N];
int distance[N];

void width(int st);

int main(){
  int i,j,k,s,t;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      hi[i][j]=0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&s,&k);
    distance[s]=-1;      /*距離がないとき*/

    for(j=0;j<k;j++){
      scanf("%d",&t);
    
      hi[s][t]=1;
    }
  }

  distance[1]=0;     /*スタートからの距離が0*/
  width(1);

  for(i=1;i<=n;i++){
    printf("%d %d\n",i,distance[i]);
  }
  
  return 0;
}
      
void width(int st){
  int i;
  int max[N];
  int s=0,g=0;

  max[g]=st;
  ++g;

  while(1){
    if(s==g) break;

    st=max[s];
    ++s;

    for(i=1;i<=n;i++){
      if(hi[st][i]==1){
	if(distance[i]>=0)
	  continue;
	max[g]=i;
	++g;

	distance[i]=distance[st]+1;
      }
    }
  }
}

  

