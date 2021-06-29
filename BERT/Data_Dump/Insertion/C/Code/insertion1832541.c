#include<stdio.h>
#define MAX 1000
int main(void)
{  

   int i,N,v,j,k;
   int A[MAX];
   
   scanf("%d",&N);
   for(i=1;i<=N;i++)
    {
	scanf("%d",&A[i]);
	}

	 printf("%d",A[1]);
	 for(i = 2;i <= N;i++)
	 {
	   printf(" %d",A[i]);
	 }
	
     printf("\n");
   for (i = 2 ; i< N+1; i++)
   {
     v = A[i];
     j = i - 1;
     while (j >= 0 && A[j] > v)
	 {
       A[j+1] = A[j];
       j--;
     A[j+1] = v;
	 }
	 
	 printf("%d",A[1]);
	 for(k = 2;k < N+1;k++)
	 {
	   printf(" %d",A[k]);
	 }
	 printf("\n");
   }
return 0;	
}
