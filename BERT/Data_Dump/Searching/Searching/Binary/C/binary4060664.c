#include<stdio.h>

int main(){
  int i,j;
  int N,M;
  int A[100000],B[100000],cmp,count=0;
 
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  
  int left,right,mid=N;
  
  scanf("%d",&M);
  for(i=0;i<M;i++) scanf("%d",&B[i]);

  for(i=0;i<M;i++){
    
    cmp=B[i];
    
    left=0;
    right=N;
    while(left<right){
     
      mid=(left+right)/2;
    
      if(cmp==A[mid]){
	count++;
	break;
      }
      else if(cmp>A[mid]){
	left=mid+1;
      }
      else if(cmp<A[mid]){
	right=mid;
      }
      
    }
    
  }

  printf("%d\n",count);




  return 0;
}

