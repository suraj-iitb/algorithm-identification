#include <stdio.h>

void insert(int [], int);
void printout(int [], int);


int main(){
  int N,i,j;
  int A[100];

  scanf("%d\n",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);

  printout(A, N);
  insert(A, N);
  
  return 0;
}

void insert(int A[], int N){
  int i,j,v=0;

  for(i=1;i<N;i++){
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    printout(A, N);
  }
}

void printout(int A[],int N){
  int i;

  for(i=0;i<N;i++){
    if(i != 0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

