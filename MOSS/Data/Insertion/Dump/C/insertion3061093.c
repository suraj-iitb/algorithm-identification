#include <stdio.h>
int N;
void Print(int *);
//関数について
void InsertionSort(int A[]){
  int i,j;
  int value;
  for(i=1;i<N;i++){
    value=A[i];
    j=i-1;
    while( j>=0 && A[j] > value){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=value;
    Print(A);
  }
}

void Print(int A[]){
  int i;
  for(i=0;i<N;i++){
     if(i>0)printf(" "); 
    printf("%d",A[i]);

  }
  printf("\n");
}

int main(){
  int A[1000];
  int i;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  Print(A);
  InsertionSort(A);

  return 0;
}


