#include<stdio.h>

#define MAX 2000000
#define k 10000

int A[MAX],B[MAX],C[MAX];
int n;

void CountingSort(int);

int main(){
  int i;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  CountingSort(n);

  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  return 0;
}

void CountingSort(int n){
  int i,j;

  for(i=0;i<k;i++) C[i]=0;

  for(j=0;j<n;j++) C[A[j]]++;

  for(i=1;i<k;i++) C[i]=C[i]+C[i-1];

  for(j=n-1;j>=0;j--){
    C[A[j]]--;
    B[C[A[j]]]=A[j];
  }
}
