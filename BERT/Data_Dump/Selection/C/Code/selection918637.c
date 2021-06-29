#include<stdio.h>
#define N 100
int main(){
  int i;
  int j;
  int n;
  int mini;
  int count=0;
  int tmp;
  int A[N];
  scanf("%d",&n);
  for( i=0; i<n; i++ ){
    scanf("%d",&A[i]);
  }
  for( i=0; i<n; i++ ){
    mini = i;
    for( j=i; j<n ; j++ ){
      if( A[j] < A[mini] ){
	mini = j;
      }
    }
    if( mini != i ) count++;
    tmp=A[i];
    A[i]=A[mini];
    A[mini]=tmp;
  }
  for( i=0; i<n; i++ ){
    printf("%d", A[i]);
    if( i<n-1 ) printf(" ");
  }
  printf("\n%d\n",count); 
  return 0;
}
