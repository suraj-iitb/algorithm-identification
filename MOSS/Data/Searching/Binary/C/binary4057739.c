#include<stdio.h>
#define N 100000

int main(){
  int a,b,i,j,left,right,mid,A[N],B[N],count=0;

  scanf("%d",&a);
  for(i=0;i<a;i++)
    scanf("%d",&A[i]);

  scanf("%d",&b);
  for(i=0;i<b;i++){
    scanf("%d",&B[i]);
    
    left = 0;
    right = a;

    while(left < right){
      mid = (left+right)/2;
      if(A[mid] == B[i]){
	count++;
	break;
      }
      
      else if(B[i] < A[mid]){
	right = mid;
      }
      
      else left = mid+1;
    }
    
    // printf("wa-i\n");
  }
  
  printf("%d\n",count);
	
  return 0;
}
  

