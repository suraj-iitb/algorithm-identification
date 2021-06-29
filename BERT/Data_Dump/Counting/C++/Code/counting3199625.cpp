//飛ばし

#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

int A[2000000];
int C[MAX+1];

void CountingSort(int A[], int n){
  // Count
  for(int i=0; i<n; i++){
    C[A[i]]++;
  }

  // Sort
  int idx=0;
  for(int i=0; i<MAX+1; i++){
    for(int j=0; j<C[i]; j++){
      A[idx++] = i;
    }
  }
}

int main(){

  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &A[i]);
  }

  CountingSort(A, n);

  for(int i=0; i<n; i++){
    printf("%d", A[i]);

    if(i != n-1){
      printf(" ");
    }
    else{
      printf("\n");
    }
  }

  return 0;
}

