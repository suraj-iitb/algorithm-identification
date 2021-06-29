#include<stdio.h>
#define N 100

int main(){
  int A[N], a, count = 0, i, j, k, temp;

  scanf("%d",&a);

  for(i = 0; i < a; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0; i < a; i++){
    for(j = a-1; j > i; j--){
      if(A[j] < A[j-1]){

      temp = A[j-1];
      A[j-1] = A[j];
      A[j] = temp;
      count++;
      }
    }
  }
  for(k = 0; k < a; k++){
    if(k == a-1) printf("%d\n",A[a-1]);
    else printf("%d ",A[k]);
  }
  printf("%d\n",count);

  return 0;
}
