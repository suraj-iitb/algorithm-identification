#include<stdio.h>
#define MAX 2000001
void countingsort(int*, int*, int);

int main()
{
int n, i, A[MAX],B[MAX];

scanf("%d",&n);
for(i=0; i<n; i++)scanf("%d",&A[i]);
countingsort(A, B, n);
return 0;
}

void countingsort(int *A, int *B, int n)
{
  int i; int c[MAX];
  for(i=0; i<=MAX; i++)
   c[i] = 0;
  for(i=0; i<n; i++)
   c[A[i]]++;
  for(i=0; i<MAX; i++)
   c[i+1] += c[i];

  for(i=n-1; i>=0; i--)
   B[--c[A[i]]] = A[i];

   for(i=0; i<n-1; i++)
   {
   printf("%d ",B[i]);
   }
   printf("%d\n",B[n-1]);
}

