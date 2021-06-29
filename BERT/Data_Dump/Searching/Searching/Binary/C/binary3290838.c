#include<stdio.h>


int binarySearch(int n,int *A,int key){
  int left=0,right=n,mid;

  while(left<right){
    mid=(left+right)/2;
    
    if(A[mid]==key) return 1;
    
    else if(key<A[mid]) right = mid;
    
    else left = mid+1;

  }
  return 0;
}

int main(){
  int i,n,q,A[100000],B,count=0;
  
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&B);
    if(binarySearch(n,A,B)==1) count++;
  }

  printf("%d\n",count);

  return 0;
}

