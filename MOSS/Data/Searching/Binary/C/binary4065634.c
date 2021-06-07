#include <stdio.h>
#define N 1000000

int binarySearch();

int main(){
  int i, n, A[N], a,b,c= 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  scanf("%d", &a);
  for(i = 0; i < a; i++){
    scanf("%d", &b);
    if( binarySearch(A,b,n) ) c++; 
  }
  printf("%d\n", c);
  return 0;
}

int binarySearch(int A[], int b, int n){
  int l,r,m;
  l = 0;
  r = n;
  while(l < r){
    m = (l + r) / 2;
    if(A[m] == b) return 1;
    if(b < A[m]) r = m;
    else if(b > A[m]) l = m + 1;

  }
  return 0;
}

