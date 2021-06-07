#include<stdio.h>
#define NOT_FOUND -1

int binarySearch(int *,int,int);

int main(){
  int i,n,q,key,A[1000000],sum=0;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(binarySearch(A,n,key)!=NOT_FOUND) sum++;
  }
  printf("%d\n",sum);
  return 0;
}

int binarySearch(int A[],int n,int key){
  int left,right,mid;

  left=0;
  right=n;

  while(left<right){
      mid=(left+right)/2;
    if(key==A[mid]) return 1;

    if(key>A[mid]) left=mid+1;
    else if(key<A[mid]) right=mid;
  }
  if(left==right) return NOT_FOUND;
  else return 0;
}

