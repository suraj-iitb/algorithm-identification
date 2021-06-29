#include <stdio.h>
 
 int main(){

  int val;
  int h,i,key,N;
  int count = 0;
  int A[100];

  scanf("%d",&val);
 
  for(i = 0;i < val;i++){
  scanf("%d",&A[i]);
  }

  for(h = 0;h < val;h++){
  for(i = val - 1 ;i > h;i--){
	  if(A[i] < A[i - 1]){
		  key = A[i - 1];
		  A[i - 1] = A[i];
		  A[i] = key;
        count++;
	  }
   }
  }
	 for(i = 0;i < val-1;i++)
   printf("%d ",A[i]);
   printf("%d\n",A[i]);
      printf("%d\n",count);
	 return 0;
  }
 
