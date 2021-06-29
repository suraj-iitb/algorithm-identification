#include<stdio.h>
#define M 100 

struct gif{
  int k;
  int col;
  int r[M];
  int t[2];
};

typedef struct gif fig;
fig A[M];
int T=0;

void dan(int u){
  int x;
  A[u].col=1;
  A[u].t[0]=++T;
  //printf("%d",A[u].t[0]);
  for(x=0;x<A[u].k;x++)if(A[A[u].r[x]-1].col==0)dan(A[u].r[x]-1);
  A[u].t[1]=++T;
};

int main(){
  int a,b,i,j;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    A[i].col=0;
    scanf("%d%d",&b,&A[i].k);
    for(j=0;j<A[i].k;j++)scanf("%d",&A[i].r[j]);
    //A[i].r[j+1]=0;
  }
  for(i=0;i<a;i++)if(A[i].col==0)dan(i);
  for(i=0;i<a;i++)printf("%d %d %d\n",i+1,A[i].t[0],A[i].t[1]);
}

