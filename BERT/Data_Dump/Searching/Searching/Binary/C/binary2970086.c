#include <stdio.h>

int binarySearch(int *, int);

int length=0;

int main(){
  int n=0;
  int q=0;
  int i=0;
  int count=0;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d", &T[i]);
  }
  length=sizeof(S)/sizeof(int);
  for(i=0;i<q;i++){
    if(binarySearch(S,T[i])==1)
      count++;
  }
  printf("%d",count);
  printf("\n");

  return 0;
}

int binarySearch(int *A,int key){
  int left=0;
  int right=0;
  int mid=0;
  right=length;
  while(left<right){
    mid=(left+right)/2;
    if(key==A[mid])
      return 1;

    if(key>A[mid])
      left=mid+1;
    else if(key<A[mid])
      right=mid;
  }
  return 0;
}

