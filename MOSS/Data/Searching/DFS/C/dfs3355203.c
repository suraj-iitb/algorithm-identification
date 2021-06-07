#include <stdio.h>
#define N 101
#define WHITE 0
#define BLACK 1
#define GRAY 10

int d[N],f[N];
int colour[N],A[N][N];
int n,time;


void visit(int r){
  int i;
  colour[r]=GRAY;
  d[r]=++time;
  for(i=0;i<n;i++){
    if(!A[r][i])continue;

    if(colour[i]==WHITE)visit(i);
  }
  colour[r]=BLACK;
  f[r]=++time;
}

void  DepthFirstSearch(){
  int i;
  for(i=0;i<n;i++)
    colour[i]=WHITE;
  time=0;
  for(i=0;i<n;i++)
    if(colour[i]==0)visit(i);
}


int main(){
  int i,j,k,c,num;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d%d",&num,&c);
    for(j=0;j<c;j++){
      scanf("%d",&k);
      A[num-1][k-1]=1;

    }
  }

  DepthFirstSearch();

  for(i=0;i<n;i++)
    printf("%d %d %d\n",i+1,d[i],f[i]);
  

  return 0;
}

