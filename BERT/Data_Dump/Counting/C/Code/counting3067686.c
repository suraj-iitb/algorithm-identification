#include<stdio.h>
#define VMAX 10000
#define MAX 2000000
int A[MAX];
int B[MAX];

int main(){
  int i,n,j;
  int C[VMAX+1];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }


  for(i = 0;i < VMAX;i++){
    C[i] = 0;
  }

  for(j = 0;j < n;j++){
    C[A[j]]++;
  }
  for(i = 1;i < VMAX;i++){
    C[i] = C[i] + C[i-1];
  }
  for(j = n; j >= 0;j--){
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  }

  for(i=0;i<n-1;i++){
    printf("%d ",B[i]);
      }
  printf("%d\n",B[n-1]);
  return 0;
}

