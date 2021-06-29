#include<stdio.h>
#include<stdlib.h>
#define VMAX 10000
#define MAX 2000001

int main()
{
  unsigned short *A, *B;

  int C[VMAX+1];
  int n, m, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for (i=0;i<=VMAX;i++) C[i]=0;

  for (i=0;i<n;i++)
  {
    scanf("%hd",&A[i+1]);
    C[A[i+1]]++;
  }

  for (i=1;i<=VMAX;i++) C[i]+=C[i-1];

  for (j=1;j<=n;j++)
  {
    
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for (m=1;m<=n;m++)
  {
    if (m>1) printf(" ");
    printf("%d",B[m]);
  }

  printf("\n");
  
  return 0;
}

