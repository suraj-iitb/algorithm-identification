#include<stdio.h>

int main(){
  int n,q,i,j,count=0,left,right,mid;
  scanf("%d",&n);
  int A[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  int B[q];
  for(i=0;i<q;i++){
    scanf("%d",&B[i]);
  }
 
  
  for(i=0;i<q;i++){
    left=0;
    right=n;
    while(left<right){
      mid=(left+right)/2;
      if(A[mid]==B[i]){
	count++;
	break;
      }
      else if(B[i]<A[mid]) right=mid;
      else left=mid+1;
    }
  }

  printf("%d\n",count);
  return 0;
}



