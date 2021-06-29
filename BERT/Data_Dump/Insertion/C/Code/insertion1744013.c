#include <stdio.h>
#define N 100
void insertionSort(int*,int);
int main(){
  int i,j,n,tmp;
  int A[N];

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    scanf("%d",&A[i]);

  for(i = 0; i<n; i++) {
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");

  insertionSort(A,n);
 
  return 0;
}

void insertionSort(int A[], int n)
{
  int i,j,v;

  for(i=1; i<n; i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
  
    for(j = 0; j<n; j++) {
      if(j>0) printf(" ");
      printf("%d",A[j]);
    }
    printf("\n");
  }
}
