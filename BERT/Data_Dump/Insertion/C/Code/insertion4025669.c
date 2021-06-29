#include<stdio.h>
#include<stdlib.h>

#define N 100

void insertionSort(int *,int);

int main()
{
  int i,j,n,get;
  int array[N];
  
  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    scanf("%d",&array[i]);
      }
  insertionSort(array,n);
  
  return 0;
}

void insertionSort(int A[], int n)
{
  int i,j,v,k;

  for(k = 0; k < n-1; k++){
      printf("%d ",A[k]);
    }
  printf("%d",A[n-1]);
  printf("\n");
  
  for(i = 1; i < n; i++){
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(k = 0; k < n-1; k++){
      printf("%d ",A[k]);
    }
    printf("%d",A[n-1]);
    printf("\n");
  }
}

