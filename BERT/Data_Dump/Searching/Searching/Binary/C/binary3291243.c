#include<stdio.h>
#include<stdlib.h>
int binarySearch(int,int*,int);
int main(){
  int n1,n2,*N1,*N2,i,count=0;
  scanf("%d",&n1);
  N1 = (int *)malloc(n1 * sizeof(int));
  for(i=0;i<n1;i++){
    scanf("%d",&N1[i]);
  }
  scanf("%d",&n2);
  N2 = (int *)malloc(n2 * sizeof(int));
  for(i=0;i<n2;i++){
    scanf("%d",&N2[i]);
  }
  for(i=0;i<n2;i++){
    if(binarySearch(N2[i],N1,n1) == 1) count++;
  }
  printf("%d\n",count);
  return 0;
}
int binarySearch(int key,int *A,int n){
  int left=0,right=n,mid;
  while(left < right){
    mid = (left + right)/2;
    if(A[mid] == key) return 1;
    else if(key < A[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}

