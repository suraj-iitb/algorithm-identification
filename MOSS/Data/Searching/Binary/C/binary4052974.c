#include <stdio.h>
#define N 100000
int binarySearch(int[],int,int);
int main(){
  int x,i,y,b,S[N],count=0;
  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&S[i]);
   
  }
  scanf("%d",&y);
  for(i=0;i<y;i++){
    scanf("%d",&b);
    if(binarySearch(S,x,b)== 1)count++;
    
  }
  printf("%d\n",count);
  return 0;
}
int binarySearch(int A[],int n,int b){
  int left=0,right=n,mid;
  while(left<right){
    mid=(left + right)/2;
    if(A[mid]==b)return 1;
    else if(b< A[mid])right =mid;
    else left=mid +1;
  }
  return 0;
}

