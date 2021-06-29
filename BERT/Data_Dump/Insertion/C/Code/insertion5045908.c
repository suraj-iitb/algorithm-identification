#include <stdio.h>

int main()
{
  int i, v, j,N;
  int A[100];
  scanf("%d",&N);
   for(j=0;j<N;j++)
     {
       scanf("%d",&A[j]);
	 }
 
 for(i=0;i<N;i++){
   v=A[i];
   j=i-1;


   while(j>=0&&A[j]>v)
     {
       A[j+1]=A[j];
       j--;
     }
   A[j+1]=v;

 
   for(j=0;j<N;j++){
     printf("%d",A[j]);
     if(j!=N-1)printf(" ");
   }
   printf("\n");
 }
 return 0;
}
  

