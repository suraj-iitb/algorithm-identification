#include <stdio.h>
 
int main(void)
{
 int A[2000];
 int N, i, j, v, k;

 scanf("%d", &N);
  
 for(i = 0; i < N; i++)
 scanf("%d", &A[i]);

for(k = 0; k < N; k++)
 if(k < N-1)
 printf("%d ", A[k]);
 else
 printf("%d", A[k]);

 printf("\n");

 for(i = 1; i < N; i++)
{

 j = i - 1;
 v = A[i];

 while(j >= 0 && A[j] > v)
{
 A[j+1] = A[j];
 j--;
}
 A[j+1] = v;

for(k = 0; k < N; k++)
 if(k < N-1)
 printf("%d ", A[k]);
 else
 printf("%d", A[k]);

 printf("\n");

}


return 0;

}

 
