#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>

using namespace std;

void printArray(int *A,int N){
  for(int i=0;i<N;i++) {
    printf("%d",A[i]);
    if(i<N-1)
      putchar(' ');
    else
      putchar('\n');
  }
}

void insertionSort(int* A, int N){
  int v,j;
  printArray(A,N);
  for(int i=1;i<N;i++){
    v=A[i];
    j = i-1;
    while(j>=0&&A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1]=v;
    printArray(A,N);
  }
}

int main(){
  int n,*p;

  scanf("%d\n",&n);

  p=(int *)malloc(n*sizeof(int));

  for(int i=0;i<n;i++){
    scanf("%d ",&p[i]);
  }

  insertionSort(p,n);
}
