#include<stdio.h>
#define N 100

int main()
{

  int i,j,k,key,n,A[N];

scanf("%d",&n);
 for(i = 0; i <= n-1; i++)
 {
   scanf("%d",&A[i]);
 }
   for (i = 0; i <= n-1; i++)
   {
    key = A[i];
    /* insert A[i] into the sorted sequence A[0,...,j-1] */
    j = i - 1;
    while (j >= 0 && A[j] > key)
    {
        A[j+1] = A[j];
        j--;
    }
    A[j+1] = key;
    for(k = 0; k < n-1; k++){
    printf("%d ",A[k]);
     }
    printf("%d",A[n-1]); 
    printf("\n"); 
     
   }
 return 0;
}

