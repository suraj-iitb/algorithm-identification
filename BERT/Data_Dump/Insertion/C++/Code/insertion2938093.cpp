#include <bits/stdc++.h>
using namespace std;

#define N 100

int main(void){

  int n, A[N];
  int i, j, key;
  
  scanf("%d", &n);
  
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
    if(i) printf(" %d",A[i]);
    else  printf("%d", A[i]);
  }
  printf("\n");

  for(i=1; i<n; i++){
    key=A[i];
    j=i-1;

    while(j >= 0 && A[j] > key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;

    for(j=0; j<n; j++){
      if(j) printf(" %d", A[j]);
      else  printf("%d", A[j]);
    }
    printf("\n");
  }
  
  return 0;
}

