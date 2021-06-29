#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void countingsort(int [],int);

int main(){
  int A[MAX];
  int n, i, j;

  scanf("%d", &n);


  /* your code */
  for(i=0 ; i<n ; i++)
  {
    scanf("%d",&A[i]);
  }

  countingsort(A,n);

  for(i=0 ; i<n-1 ; i++)
  {
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);

  return 0;
}

void countingsort(int A[],int n)
{
  int i,j,k=0;

  int C[VMAX];
  for(i=0;i<VMAX;i++){
    C[i]=0;
  }
  for(i=0;i<n;i++){
    C[A[i]]++;
  }
  for(i=0;i<VMAX;i++){
    for(j=C[i];j>0;j--){
A[k++]=i;
    }
}
}
