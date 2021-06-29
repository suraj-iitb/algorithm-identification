#include<stdio.h>

int binarySearch(int A[],int n,int B){
  int mid;
  int left=0;
  int right=n;
  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==B){
      return 1;
    }
    if(B>A[mid]){
      left=mid+1;
    }
    else if(B<A[mid]) right=mid;
  }
  return 0;
}
	   

int main(){
  int n,i,q,B;
  int A[100000];
  int res=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&B);
    if(binarySearch(A,n,B)) res++;
  }
  printf("%d\n",res);
  return 0;
}
