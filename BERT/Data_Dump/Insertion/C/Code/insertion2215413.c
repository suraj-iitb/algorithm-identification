#include <stdio.h>

void Print(int* A,int n){
  int i;
  for(i=0;i<n;i++){
    if(i)
      printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}


void insertSort(int* A,int n){

  int i,j,v;

  for (i = 0; i < n; i++) {
    v = A[i];
    j = i-1;

    while (j>=0&& A[j]>v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    Print(A,n);
  }

}



int main(int argc, char const *argv[]) {

  int n;
  int i;
  int A[100];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  insertSort(A,n);

  return 0;
}
