#include<stdio.h>

static const int N = 100;

void insertionSort(int A[], int n){
  int i;
  for(i = 1; i <= n; i++ ){
    if(i > 1) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(){
  int n, i, j, v;
  int A[N+1];
  scanf("%d", &n);
  for(i = 1; i <= n; i++ ) scanf("%d", &A[i]);
  insertionSort(A,n);
  for(i = 2; i <= n; i++){
    v = A[i];  //3. v = A[i]
    j = i - 1; //4. j = i - 1
    while(j >= 0 && A[j] > v){ //5. while j >= 0 かつ A[j] > v
      A[j+1] = A[j]; //6. A[j+1] = A[j]
      j--;           //7. j--
      A[j+1] = v;   //8. A[j+1] = v
    }
    insertionSort(A,n);
  }
  return 0;
}

