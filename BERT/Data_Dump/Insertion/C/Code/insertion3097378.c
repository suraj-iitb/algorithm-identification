#include<stdio.h>

#define MAX 1000

void ISort(int A[],int N);

int main(void) {
    int A[MAX];
    int N, i;
    scanf("%d", &N);

    for(i=0; i<N; ++i){
      scanf("%d", &A[i]);
    }

    for(i=0; i<N; i++) {
      printf("%d", A[i]);
      if(i != N-1)
        printf(" ");
    }
    printf("\n");

    ISort(A, N);
}

void ISort(int a[],int n) {
  for(int i=1; i<n; ++i) {

      int v = a[i];
      int j = i-1;

      while(j >= 0 && a[j] > v) {
          a[j+1] = a[j];
          j--;
      }
      a[j+1] = v;

      for(int p=0; p<n; p++) {
        printf("%d", a[p]);
        if(p != n-1)
          printf(" ");
      }
      printf("\n");
  }
}

