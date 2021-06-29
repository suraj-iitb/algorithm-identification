#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <climits>

using namespace std;

int selectionSort(int *A,int N){
  int count=0;
  for(int i=0;i<N-1;i++){
      int minj=i;
      for(int j=i;j<N;j++){
        if(A[j] < A[minj]) {
          minj = j;
        }
      }
      if(i!=minj){
        int tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;
        count++;
      }
  }
  return count;
}

int main(){
  int n,*A;

  scanf("%d\n",&n);

  A=(int *)malloc(n*sizeof(int));

  for(int i=0;i<n;i++){
    scanf("%d ",&A[i]);
  }
  int count = selectionSort(A,n);
  for(int i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)
      putchar(' ');
  }
  printf("\n%d\n",count);
}
