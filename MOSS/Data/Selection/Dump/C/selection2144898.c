#include<stdio.h>

static const int N = 1000;

void trace(int A[], int n){
  int i;
  for ( i = 1; i <= n; i++ ){
    if ( i > 1 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){
  int n, i, j;
  int A[N+1];
  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);


  /*
  * Insert sort
  */
  // trace(A, n);
  // for ( i = 2; i < n+1 ; i++) {
  //   int key = A[i];
  //   int j = i-1;
  //   while (j >= 1 && A[j] > key) {
  //     A[j+1] = A[j];
  //     j--;
  //   }
  //   A[j+1] = key;
  //   trace(A, n);
  //    /* code */
  // }

  /*
  * Bubble sort
  */
  // int count = 0;
  // for (i =1; i< n+1; i++){
  //   for ( j = n; j >= i+1; j--) {
  //     if (A[j] < A[j-1]){
  //       count += 1;
  //       int tmp = A[j];
  //       A[j] = A[j-1];
  //       A[j-1] = tmp;
  //     }
  //     /* code */
  //   }
  // }
  // trace(A,n);
  // printf("%d\n", count);


  /**
  * Selection sort
  */
   int count = 0;
   for (i=1; i< n+1; i++){
     int min = i;
     for (j=i; j<n+1; j++){
       if (A[j] < A[min]){
         min = j;
       }
     }
     if (min != i) {
       /* code */
       int tmp = A[min];
       A[min] = A[i];
       A[i] = tmp;
       count += 1;
     }
     
   }
   trace(A,n);
   printf("%d\n", count);

  return 0;
}
