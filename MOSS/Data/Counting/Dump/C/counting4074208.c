#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

void countingsort(int A[],int B[],int k,int n)
{
  int C[MAX+1],i,j;

  for (i=0;i<=k;i++){
    C[i]=0;
  }
  for(j=0;j<n;j++){
    C[A[j+1]]++;
  }
  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

}


int main(){
  int n,i,*A,*B;

  scanf("%d",&n);

  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1);

  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
  }
  countingsort(A,B,MAX,n);

  for(i=1;i<=n;i++){
    if(i>1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");


  return 0;
}

