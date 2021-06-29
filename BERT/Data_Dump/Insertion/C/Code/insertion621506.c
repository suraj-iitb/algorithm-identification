#include<stdio.h>

int n;
int A[100];


void trace(){
  int i;
  for ( i = 0; i < n; i++ ){
    printf("%d", A[i]);
    if(i+1!=n){
      printf(" ");
    }
  }
  printf("\n");
}

int main(){
  int i;
  int j;
  int key;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ){
    scanf("%d", &A[i]);
  }
  for (j = 1; j<n; j++){
    key = A[j];
    trace();
    i = j - 1;
    while (i >= 0 && A[i] > key){
      A[i+1] = A[i];
      i = i - 1;
    }
      A[i+1] = key;	  
  }			  
  trace();
  return 0;
}
