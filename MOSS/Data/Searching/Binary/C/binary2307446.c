#include <stdio.h>

#define SMAX 100000
#define TMAX 50000
#define NOT_FAUND -1

int binarySearch(int*,int,int);

int main(){

  int i,n,q,S[SMAX],T[TMAX],count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  for(i=0;i<q;i++){
    if(binarySearch(S,n,T[i])!=NOT_FAUND){
      count++;
    }
  }

  printf("%d\n",count);
  return 0;
}

int binarySearch(int* A,int n,int key){

  int right=n,left=0,mid;
  while(left<right){
    mid=(left+right)/2;
    if(key==A[mid]) return mid;
    if(key>A[mid]) left=mid+1;
    else right=mid;
  }
  return NOT_FAUND;
  
}
