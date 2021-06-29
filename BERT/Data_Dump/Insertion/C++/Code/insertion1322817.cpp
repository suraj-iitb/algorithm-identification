#include <stdio.h>

int main(){
 int A[1000],N=0;
 scanf("%d", &N);
 for(int i=0;i<N;i++){
  scanf("%d", &A[i]);
 }
 for(int i=0;i<N;i++){
  int v;
  v = A[i];
  int j = i - 1;
  while( j >= 0 && A[j] > v){
   A[j+1] = A[j];
   j--;
   A[j+1] = v;
  }
  for(int i=0;i<N-1;i++){
   printf("%d ", A[i]);
  }
  printf("%d\n", A[N-1]);
 }
}
