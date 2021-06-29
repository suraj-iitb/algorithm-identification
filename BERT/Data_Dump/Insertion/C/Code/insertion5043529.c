#include <stdio.h>
#include <stdlib.h>
#define N 100
#define A 1000

int main()
{
  int i,j,n,sort[N],v,k;
  scanf("%d",&n);
  if(n>N){
    printf("errar");
    exit(1);
  }
  for(i=0;i<n;i++) scanf("%d",&sort[i]);
  for(i=0;i<n;i++){
    for(j=0;j<i;j++){
      if(sort[j]>sort[i]){
        v=sort[i];
        for(k=i;k>=j;k--)sort[k]=sort[k-1];
        sort[j]=v;
        break;
      }
    }
    for(k=0;k+1<n;k++)printf("%d ",sort[k]);
    printf("%d\n",sort[n-1]);
  }
}
