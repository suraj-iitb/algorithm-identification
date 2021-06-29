#include <stdio.h>
int A[100];
int N;
void trace(){
  int i;
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

void insertionSort(){
  int i,j,v;
  for(i= 1;i<N;i++){
    v = A[i];
    j = i - 1;
    while (j >= 0&&A[j] > v){
      A[j+1] = A[j];
      j--;
    }
      A[j+1] = v;
      trace();
  }
}

int main(){
  int i;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  trace();
  insertionSort();
  return 0;
}

