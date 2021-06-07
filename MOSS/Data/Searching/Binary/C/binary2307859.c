#include <stdio.h>
#define N 100000
#define M 50000
int main(){
  int i,j,left,right,mid,n,length,count=0,A[N],B[M];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&length);
  for(j=0;j<length;j++){
    scanf("%d",&B[j]);
  }
  
  for(i=0;i<length;i++){
    left=0;
    right=n;
    while(left<right){
      mid=(right+left)/2;
      if(B[i]==A[mid]){
	count++;
	break;
      }
      if(B[i]>A[mid]){
	left=mid+1;
      }
      else if(B[i]<A[mid]){
	right=mid;
      }
    }
    
      
  }
  
  printf("%d\n",count);
  return 0;
}
