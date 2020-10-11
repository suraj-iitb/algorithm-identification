#include <stdio.h>
#define N 100
int selectionSort(int *, int);

int main(){

  int n, A[N];
  int i, total;


  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  total=selectionSort(A, n);

  for(i=0; i<n-1; i++){
    printf("%d ", A[i]);
  }
  printf("%d\n", A[n-1]);
  printf("%d\n", total);

  return 0;

}

int selectionSort(int A[], int n){

  int i, j, min, temp, count=0;

  for(i=0; i<n-1; i++){
    min=i;
    for(j=i+1; j<n; j++){
      if(A[j]<A[min]){
	min=j;

      }
    }
    temp=A[i];
    A[i]=A[min];
    A[min]=temp;

    if(i!=min) count++;
  }

  return count;
}

