#include <stdio.h>
#define M 100

int main()
{
  int limit,i=0,A[M];
  int v,h,j;
  scanf("%d",&limit);
  for(i=0;i<limit;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<limit;i++){
    v = A[i];
    j = i - 1;
    while(j >=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(h=0;h<limit-1;h++)printf("%d ",A[h]);
      printf("%d\n",A[limit-1]);
  }
  return 0;
}

