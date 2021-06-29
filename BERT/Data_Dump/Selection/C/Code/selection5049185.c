#include<stdio.h>
#define N 100

int main(){
  int A[N], a, count = 0, i, j, k, temp,minj;

  scanf("%d",&a);

  for(i = 0; i < a; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0; i < a; i++){
    minj = i;
    for(j = i; j < a; j++){
      if(A[j] < A[minj])
        minj = j;
    }
    if(i != minj){
      temp = A[minj];
      A[minj] = A[i];
      A[i] = temp;
      count++;
    }
  }
  for(k = 0; k < a; k++){
    if(k == a-1) printf("%d\n",A[a-1]);
    else printf("%d ",A[k]);
  }
  printf("%d\n",count);

  return 0;
}
