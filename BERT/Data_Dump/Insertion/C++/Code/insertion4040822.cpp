#include<stdio.h>
void insertionSort(int [], int); // N個の要素を含む0-オリジンの配列A
void test(int [], int);

int main(){
  int i,j,M;
  int A[100];

  scanf("%d",&M);
  for(i=0;i<M;i++) scanf("%d",&A[i]);


  test(A,M);
  insertionSort(A,M);

  return 0;
}

void insertionSort(int A[], int M) {
  int i,j,x;
  for (i=1;i<M;i++){
    x= A[i];
    j = i-1;
    while (j>=0 && A[j] > x){
      A[j+1] = A[j];
      j--;

    }
     A[j+1] = x;
     test(A,M);
  }

}

void test(int A[], int M){
  int i;
  for(i=0;i<M;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);

  }
  printf("\n");

}

