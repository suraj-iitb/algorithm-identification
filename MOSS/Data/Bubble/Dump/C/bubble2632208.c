#include <stdio.h>

int main(){
  int N,i,j,num=0;
  int A[100];

  scanf("%d\n",&N);
  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0 ; i < N ; i++){
    for(j = 0 ; j < N-1-i ; j++){
      if(A[j] > A[j+1]){
        num++;
        int t = A[j];
        A[j] = A[j+1];
        A[j+1] = t;
      }
    }
  }

  for(i = 0 ; i < N ; i++){
    if(i < N-1) printf("%d ",A[i]);
    else printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",num);
  return 0;
}
