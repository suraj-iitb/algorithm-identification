#include<stdio.h>
#define N 1000000

int A[N],n;

int binarysearch(int key) {

  int left=0,right=n,mid;
  
  while(left < right) {
    mid = (left+right) / 2;
    if(key == A[mid])
      return 1;
    if(key > A[mid] )
      left = mid + 1;
    else if(key < A[mid])
      right = mid;
  }
  return 0;
}

int main(void) {

  int i,p,k,cnt=0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  
  scanf("%d",&p);
  for(i=0;i<p;i++) { 
    scanf("%d",&k);
 if(binarysearch(k))
   cnt++;
  }
  printf("%d\n",cnt);
  
  return 0;
}
