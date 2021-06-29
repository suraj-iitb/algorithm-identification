#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int n,A[MAX],B[MAX],k;

void CountingSort();

int main(){

  int i, j;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);

  }
 

  CountingSort();
  for(i=1;i<n+1;i++){
    if(i>1)printf(" ");
    printf("%d",B[i]);
  }
printf("\n");

  return 0;
}

void CountingSort()
{
  int i,j,C[VMAX];
  
  for(i=0;i<=VMAX;i++){
    C[i]=0;
  }
    
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }

  for(i=1;i<=VMAX;i++){
    C[i]=C[i]+C[i-1];
  }

  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}

