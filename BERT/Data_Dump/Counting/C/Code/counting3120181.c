#include<stdio.h>
#define N 2000001
#define M 10001
int n,A[N],B[N],C[M];
void countingSort(void);
int main(){
  int i;
  int count=0;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }
  countingSort();
  for(i=1;i<=n;i++){
    if( (i-1)!=0 ){
      printf(" ");
    }
    printf("%d",B[i]);
    count++;
  }
  printf("\n");
  return 0;
}
void countingSort(void){
  int i;
  for(i=0;i<M;i++){
    C[i] = 0;
  }
  for(i=1;i<=n;i++){
    C[A[i]]++;
  }
  for(i=1;i<M;i++){
    C[i] += C[i-1];
  }
  for(i=1;i<=n;i++){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  return;
}
