#include <stdio.h>
#define N 100

int bubble(int *, int);

int main(){

  int i, n, A[N], count;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  count=bubble(A, n);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

int bubble(int *A, int n){

  int i, j, sub, count=0;

  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        sub=A[j];
        A[j]=A[j-1];
        A[j-1]=sub;
        count++;
      }
    }
  }
  return count;
}

