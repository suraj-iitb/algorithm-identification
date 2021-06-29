#include<stdio.h>
#define N 100

int n,A[N][N],b[N];

void Breadth(int num, int res);

int main()
{
  int i,j,k,p,q;

  scanf("%d",&n);

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      A[i][j]=0;
    }
  }
  for(i=0; i<n; i++){
    scanf("%d%d",&p,&k);
    p--;

    for(j=0; j<k; j++){
      scanf("%d",&q);
      q--;
      A[p][q]=1;
    }
  }
  for(i=0; i<n; i++){
    b[i]=-1;
  }
  Breadth(0,-1);
  for(i=0; i<n; i++){
    printf("%d %d\n",i+1,b[i]);
  }
  return 0;
}

void Breadth(int num,int res)
{
  int i;
  
  res++;
  b[num]=res;

  for(i=0; i<n; i++){
    if(A[num][i]==1){
      if(b[i]<=res && b[i]>=0)continue;
      Breadth(i,res);
    }
  }
}

