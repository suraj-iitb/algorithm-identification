#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int *,int ,int);

int main() {
  int n,q;
  int *T;
  int *S;
  int i;
  int number;
  int count=0;

  scanf("%d",&n);
  //printf("%d\n",n);

  S = (int *)malloc(n * sizeof(int));
  
  for(i=0;i<n;i++) {
    scanf(" %d",&S[i]);
  }

  scanf("%d",&q);

  T = (int *)malloc((q+1) * sizeof(int));
  for(i=0;i<q;i++) {
    scanf(" %d",&T[i]);
  }
  
  for(i=0;i<q;i++) {
    //printf("%d\n",T[1]);
    number=LinearSearch(S,T[i],n);
    if(number!=-1) count++;
    //printf("%d ",T[i]);
  }
  //for(i=0;i<q;i++) printf("%d ",T[i]);
  
   printf("%d\n",count);
  
  return 0;
}

int LinearSearch(int *A,int key,int q) {
  int i=0;
  A[q] = key;
  while(A[i] != key) {
    i++;
    if(i==q) return -1;
  }
  //printf(": %d,%d ",key,A[i]);
  return 1;
}

