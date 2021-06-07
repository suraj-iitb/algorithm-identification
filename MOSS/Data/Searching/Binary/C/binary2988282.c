#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int *,int ,int);

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
    //printf("%d\n",T[i]); 
    number=BinarySearch(S,T[i],n);
    if(number==1) {
      //printf("check");
      count++;
    }
  }

  printf("%d\n",count);
  
  return 0;
}

int BinarySearch(int *A,int key,int n) {
  int left=0,right=n,mid;
  while(left < right) {
    mid = (left+right) / 2;
    //printf("S:%d\n",A[mid]);
    if(A[mid] == key) return 1;
    else if(key<A[mid]) right=mid;
    else left = mid+1;
  }
  return -1;
}


