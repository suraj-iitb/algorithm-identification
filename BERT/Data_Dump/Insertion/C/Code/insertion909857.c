#include <stdio.h>
int j,N;
int A[100];
int key;

void print(){
  int i;
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1)printf(" ");
  }
  printf("\n");
}

int main(){
  int i;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  print();

  for(i=1;i<N;i++){
    key = A[i];
    j = i -1;
    
    while (j >= 0 && A[j] > key){
      A[j+1] = A[j];
      j--;

    }

    A[j+1] = key;
    print();
  }

    return 0;
}
