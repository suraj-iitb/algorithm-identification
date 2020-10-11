#include <stdio.h>
#define N 100

int main(){

  int a,i,v,j,k,count;
  int A[N];

  scanf("%d",&a);

  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }

  for( i = 1 ; i < a ; i++ ){
    v = A[i];
    j = i - 1;
    while( j >= 0 && A[j] > v ){
      A[j+1] = A[j];
      j--;
      count++;
    }
    A[j+1] = v;
  }
  
  for(i=0;i<a-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[a-1]);
  printf("%d\n",count);
  return 0;
}
