#include<stdio.h>

#define N 100

void SelectionSort(int *);

int n;
int count=0;


int main(){
  int A[N+1];
  int i,m;
  
  scanf("%d", &n);
  for( i = 0; i < n; i++ ) scanf("%d", &A[i]);
  
  SelectionSort(A);
  
  printf("%d\n",count);
  return 0;
}

void SelectionSort(int A[]){
  int i,j,key,m,mini,X;
  for(i=0;i<n;i++){
    mini=i;
    X=0;
    for(j=i;j<n;j++){
      if(A[j]<A[mini]){
	mini=j;
	X=1;
      }
    }
    if(X==1){
	key=A[i];
	A[i]=A[mini];
	A[mini]=key;
	count++;
    }
  }
  for ( m = 0; m <= n-1; m++ ){
    if ( m > 0 ) printf(" ");
    printf("%d", A[m]);
  }
  printf("\n");
}
