#include<stdio.h>
#include<iostream>
using namespace std;

int bubble(int A[], int n){
  int i,j;
  bool flag=1;
  int sw = 0;
  for ( i = 0; flag; i++ ){
      flag=0;
      for ( j = n-1; i < j; j-- ){
        if(A[j] < A[j-1]){
        swap(A[j],A[j-1]);
        sw += 1;
        flag=1;
        }
      }
  }
  return sw;
}

int main(){
  int n, i, j,sw;
  int A[100];
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  sw=bubble(A,n);
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d", sw);
  printf("\n");
  return 0;
}
