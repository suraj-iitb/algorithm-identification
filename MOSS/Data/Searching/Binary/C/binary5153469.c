#include<stdio.h>
#define YOUSO 100000
int A[YOUSO],n;
int binarySearch(int);
int main(){
  int i,j,k,sum=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&j);
  for(i=0;i<j;i++){
    scanf("%d",&k);
    if(binarySearch(k))sum++;
  }
  printf("%d\n",sum);
  return 0;
}
int binarySearch(int x){
  int left=0;
  int right=n;
  int mid;
  while(left<right){
    mid=(left+right)/2;
    if(x==A[mid]) return 1;
    if(x>A[mid]) left=mid +1;
    else if(x<A[mid]) right=mid;
  }
  return 0;
}




