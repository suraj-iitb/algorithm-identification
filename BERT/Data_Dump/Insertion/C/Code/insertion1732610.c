#include <stdio.h>

#define N 1000

int main()
{
  int i, j, k;
int n;
int A[N];
int v;

 scanf("%d",&n);
 for(i=0;i<n;i++){
   scanf("%d",&A[i]);
 }

 for (i=1; i < n; i++) { 
   for (k=0; k < n; k++) { 
     if(k==n-1){
       printf("%d\n", A[k]);
       break;
     }
     printf("%d ", A[k]);
   }
   v=A[i];
   j = i-1; 

   while ((j >= 0) && (A[j] > v)) {
     A[j+1] = A[j];
     j--;
   }
   A[j+1] = v;
 }
 
 for (i=0; i < n; i++) { 
   if(i==n-1){
     printf("%d\n", A[i]);
     break;
     }
   printf("%d ", A[i]);
 }
 return 0;
}
