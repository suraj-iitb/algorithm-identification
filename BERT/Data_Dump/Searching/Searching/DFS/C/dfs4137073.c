#include <stdio.h>
#define N 100
#define A 0
#define B 1
#define C 2

int n,hi[N][N];
int de[N],fi[N],judge[N],count;

void Depth_visit (int st);
void depth();

int main(){
  int i,j,k,s,t;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      hi[i][j]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&s,&k);
    s--;

    for(j=0;j<k;j++){
      scanf("%d",&t);
      t--;
      hi[s][t]=1;
    }
  }

  depth();

  return 0;
}
      

void Depth_visit (int st){/*深さ優先探索*/
  int a;
  judge[st]=1;
  de[st]= ++count;

  for(a=0;a<n;a++){
    if(hi[st][a]==0)
      continue;
    if(judge[a]==0){
      Depth_visit(a);
    }
  }

  judge[st]=2;
  fi[st]=++count;
}
  
void depth(){
  int b;

  for(b=0;b<n;b++)
    judge[b]=0;
  count=0;

  for(b=0;b<n;b++){
    if(judge[b]==0)
      Depth_visit(b);
  }

  for(b=0;b<n;b++){
    printf("%d %d %d\n",b+1,de[b],fi[b]);
  }
}

