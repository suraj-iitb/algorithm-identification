#include<stdio.h>

#define N 100

void selectionSort(int A[], int n);

main(){

  int i, n, A[N];
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++) scanf("%d", &A[i]);
  
  selectionSort(A, n);
  
  return 0;
}

void selectionSort(int A[], int n){

  int i, j, min, temp, a = 0, k;
  
  if(n != 1){
    for(i = 0; i < (n - 1); i++){
      min = i;
      for(j = (i + 1); j < n; j++){
	if(A[j] < A[min]) min = j;
      }
      if(i != min){
	temp = A[i];
	A[i] = A[min];
	A[min] = temp;
	a++;
      }
    }
  }
  for(i = 0; i < n; i++){
    if(i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n%d\n", a);
}




  
