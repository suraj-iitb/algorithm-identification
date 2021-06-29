#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <climits>

using namespace std;

int bubbleSort(int *A,int N){
  int count=0;
  bool flag=1;
  while(flag){
    flag = 0;
    for(int j=N-1;j>0;j--){
      //printf("%d %d\n",A[j],A[j-1]);
      if(A[j] < A[j-1]) {
        int tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag=1;
        count++;
       }
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
  int count = bubbleSort(A,n);
  for(int i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)
      putchar(' ');
  }
  printf("\n%d\n",count);
}
