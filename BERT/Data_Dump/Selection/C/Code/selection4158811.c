#include <stdio.h>
#define N 100

int select(int *, int);

int main(){

  int i, n, A[N], count;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  count=select(A, n);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

int select(int *A,int n){

 int i, j, minj, sub, count=0;

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj])
         minj=j;
    }
    sub=A[i];
    A[i]=A[minj];
    A[minj]=sub;
    if(i!=minj) count++;
  }
  return count;
}
