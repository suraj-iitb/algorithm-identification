#include <stdio.h>
#include <stdlib.h>

int main(){

  int n,i,j,flag=1,t,c=0;

  int* A;

  scanf("%d",&n);
  A = (int*)malloc(n);
   for(i=0;i<n;i++){
     scanf("%d",&A[i]);
  }

   while(flag){

    flag=0;
    
    for(j=n-1;j>0;j--){
      
      if(A[j]<A[j-1]){
	t=A[j-1];
	A[j-1]=A[j];
	A[j]=t;
	c++;
	flag=1;
	
	}
      }
}
   printf("%d",A[0]);
   for(i=1;i<n;i++){
   printf(" %d",A[i]);
  }
  printf("\n%d\n",c);
  return 0;
}


