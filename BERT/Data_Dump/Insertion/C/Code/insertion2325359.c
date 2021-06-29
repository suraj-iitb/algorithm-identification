#include<stdio.h>
int main(void){
   int i,j,k,N,A[1005],v,temp;

   scanf("%d",&N);
   for(i=0;i<N;i++){
   scanf("%d",&A[i]);
   }

   for(i=0;i<N;i++){
	   v=A[i];
	   j=i-1;
	   while(j>=0 && A[j]>v){
		   temp=A[j+1];
		   A[j+1]=A[j];
		   A[j]=temp;

		   j--;
		   A[j+1]=v;
	   }
      for(k=0;k<N-1;k++){  printf("%d ",A[k]);}
      printf("%d\n",A[k]);

   }
	return 0;
}
