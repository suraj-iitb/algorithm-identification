#include <stdio.h>
 
 int main(){

 int A[100];
 int val;
 int i,j,tmp,cmp;
 int count = 0;

 scanf("%d",&val);

 for(i = 0;i < val;i++){
scanf("%d",&A[i]);
 }

 for(i = 0;i < val;i++){
     cmp = i;
	 for(j = i + 1;j < val;j++){
		 if(A[j]<A[cmp]){
			 cmp = j;
           }
	 }

	 if(A[i] > A[cmp]){
  tmp = A[cmp];
  A[cmp] = A[i];
  A[i] = tmp;
  count++;
	 }
 }

 for(i = 0;i < val - 1;i++)
   printf("%d ",A[i]);
 printf("%d\n",A[i]);
 printf("%d\n",count);

	 return 0;
    }
