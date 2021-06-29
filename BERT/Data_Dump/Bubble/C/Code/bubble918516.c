#include<stdio.h>
#define N 100
int main(){
  int i;
  int j;
  int n;
  int count=0;
  int tmp;
  int A[N];
  scanf("%d",&n);
  for( i=0; i<n; i++ ){
    scanf("%d",&A[i]);
  }
  for( i=0; i<n; i++ ){
    for( j=n-1; j>=i+1; j-- ){
      if( A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	count++;
      }
    }
  }
  for( i=0; i<n; i++ ){
    printf("%d", A[i]);
    if( i<n-1 ) printf(" ");
  }
  printf("\n%d\n",count); 
  return 0;
}
