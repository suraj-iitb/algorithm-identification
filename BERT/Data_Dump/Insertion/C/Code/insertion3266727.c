#include<stdio.h>

void InsertionSort(int A[], int n);

int main()
{
  int i;
  int n;
  int A[101];

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }
  
  InsertionSort(A, n);

  return 0;
}

void InsertionSort(int A[], int n)
{
  int i=0,j=0;
  int key;

  for(i = 0;i < n;i++){
    key = A[i];
    j = i-1;
    while(j >= 0 && A[j] >= key){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = key;
    
    for(j = 0;j < n;j++){
      if(j) printf(" ");
      printf("%d",A[j]);
    }
    printf("\n");
  }
}

