#include <stdio.h>
#define N 1000

int main() {
  int i,minj,A[N],a,cnt=0,j;
  scanf("%d",&a);
  for(i=0;i<a;i++)scanf("%d",&A[i]);
  for(i=0;i<a;i++){
    minj=i;
    for(j=i;j<a;j++)if(A[j]<A[minj])minj=j;
    if(minj!=i){
      int b=A[i];
      A[i]=A[minj];
      A[minj]=b;
      cnt++;
    }
  }
  for(i=0;i<a;i++){
    if(i==a-1)printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",cnt);
  return 0;
}

