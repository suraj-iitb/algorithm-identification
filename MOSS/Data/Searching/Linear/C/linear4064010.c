#include<stdio.h>
#define N 10000

int linearSearch();

int main(){
  int i,n,A[N], a,b,c = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  scanf("%d", &a);
  for(i = 0; i < a; i++){
    scanf("%d", &b);
    if( linearSearch(A,b,n) == 1 ) c++;
  }
  printf("%d\n",c);
  return 0;
}

int linearSearch(int A[], int b, int n){
  int i;
  for(i = 0 ; i < n-1; i++){
    if(A[i] == b) return 1;
  }
  return 0;
}
