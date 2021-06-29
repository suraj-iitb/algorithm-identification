#include<stdio.h>

#define N 100

void BubbleSort(int *);

int n;
int count=0;


int main(){
  int A[N+1];
  int i,m;
  
  scanf("%d", &n);
  for( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  
  BubbleSort(A);
  
  printf("%d\n",count);
  return 0;
}

void BubbleSort(int A[]){
  int i,j,key,m;
  for(i=0;i<n;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){

	key=A[j];
	A[j]=A[j-1];
	A[j-1]=key;
	count++;
      }
    }
  }
  for ( m = 0; m <= n-1; m++ ){
    if ( m > 0 ) printf(" ");
    printf("%d", A[m]);
  }
  printf("\n");
}
