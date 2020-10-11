#include <stdio.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(int,int);
int A[MAX],B[MAX],C[VMAX+1];

int main(){
  int n,i;
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  CountingSort(VMAX,n);

  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
  return 0;
}

void CountingSort(int l,int n){
  int i;

  for(i=0;i<=l;i++){
    C[i]=0;
  }

  for(i=0;i<n;i++){
    C[A[i]]++;
  }

  for(i=0;i<l;i++){
    if(i==0){
      C[i]=C[i];
    }
    else C[i]=C[i]+C[i-1];
  }

  for(i=n-1;i>=0;i--){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
}

