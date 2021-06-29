#include <stdio.h>

#define N 100

int main(){

  int i,j,A[N],n,tmp,count=0,mini;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    mini = i;
    for(j=i;j<n;j++){
      if(A[j]<A[mini]) mini = j;
    }
    if(A[i]>A[mini]) count++;
    tmp = A[i];
    A[i] = A[mini];
    A[mini] = tmp;
  }
  
  for(i=0;i<n;i++){
    if(i==n-1) printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }

  printf("%d\n",count);

  return 0;
}
