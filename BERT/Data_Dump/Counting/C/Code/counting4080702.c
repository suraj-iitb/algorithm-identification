#include <stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(int *,int *, int);
int n,C[VMAX+1];

int main(){

 int *A, *B;
 int i, j;

scanf("%d",&n);

A = malloc(sizeof(int)*n+1);
B = malloc(sizeof(int)*n+1);

for(i=0;i<n;i++)               //Aの格納
{
  scanf("%d",&A[i]);
}

CountingSort(A,B,VMAX);
for(i=1;i<=n;i++)
{
  if(i!=n)printf("%d ",B[i]);
  else printf("%d\n",B[i]);
}

  return 0;
}

void CountingSort(int *A,int *B,int k)
{
  int i,j,C[k+1];
  for(i=0;i<k;i++) C[i] = 0;

  for(i=0;i<n;i++)  C[A[i]]++;/* C[i] に i の出現数を記録する */

  for(i=0;i<k;i++) C[i] = C[i] + C[i-1];    /* C[i] に i 以下の数の出現数を記録する*/

  for(j=n;j>=0;j--)
  {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

