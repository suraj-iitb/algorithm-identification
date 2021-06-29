#include <stdio.h>
#define N 100

int main(){

  int a,i,v,j,k;
  int A[N];

  scanf("%d",&a);

  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }

  for( k = 0 ; k < a-1 ; k++ ) printf("%d ",A[k]);
  printf("%d\n",A[a-1]);

  for( i = 1 ; i < a ; i++ ){
    v = A[i];
    j = i - 1;
    while( j >= 0 && A[j] > v ){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for( k = 0 ; k < a-1 ; k++ ){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[a-1]);
  }
  return 0;
}
