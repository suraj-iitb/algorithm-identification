#include<stdio.h>
#include<stdlib.h>
int main(){
int i = 0;
int j = 0;
int k = 0;
int N;
int *A,v;
scanf("%d",&N);

A = (int *)malloc(sizeof(int) * N);
for(i=0;i<N;i++){
  scanf("%d",&A[i]);
}
printf("%d",A[0]);
for(k= 1;k<N;k++){
  printf(" %d",A[k]);
}
printf("\n");
// N個の要素を含む0-オリジンの配列
    for (i = 1; i < N;i++){

  v = A[i];
    j = i - 1;
    while (j >= 0 && A[j] > v){
      A[j+1] = A[j];
     j--;
   A[j+1] = v;
}

printf("%d",A[0]);
for(k= 1;k<N;k++){
  printf(" %d",A[k]);
}

printf("\n");
    }

return 0;
}

