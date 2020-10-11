#include<stdio.h>

int A[2000000],B[2000000];
int main(){

  int i,j,n,C[10001];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
}

  for(i=0;i<=10000;i++){
    C[i] = 0;
}
  for(j=0;j<n;j++){
    C[A[j+1]]++;

  }
  for(i=1;i<10000;i++){
    C[i] = C[i]+C[i-1];

  }

  for(j=1;j<=n;j++){

    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=1;i<n;i++){

    printf("%d ",B[i]);

  }
  printf("%d\n",B[i]);

  return 0;
}
