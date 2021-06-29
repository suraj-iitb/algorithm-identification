#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define VMAX 10000
void CountingSort(short* ,short* ,int);
int main()
{
  unsigned short *A,*B;
  int C[VMAX+1];
  int n,i,j;

  scanf("%d",&n);
  //printf("eva\n");
  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  //ここからが自分
  for(i=1;i<=n;i++) scanf("%hd",&A[i]);
  CountingSort(A,B,n);
  for(i=1;i<n;i++) printf("%d ",B[i]);
  printf("%d\n",B[i]);
  free(A);
  free(B);
  return 0;
}
void CountingSort(short*A,short*B,int k)
{
  int i,j;
  int C[VMAX+1];

  for(i=0;i<VMAX;i++) C[i]=0;
  for(j=1;j<=k;j++) C[A[j]]++;
  for(i=1;i<VMAX;i++) C[i]=C[i]+C[i-1];
  for(j=k;j>=1;j--)
    {
      B[C[A[j]]] = A[j];
      C[A[j]]--;
     
    }
}

  
  
    

