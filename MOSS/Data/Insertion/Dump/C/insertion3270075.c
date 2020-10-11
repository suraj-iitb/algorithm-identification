#include<stdio.h>

void insertionSort(int *,int);
int main(){
  int a[100],i,j,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(j=0;j<n;j++){
      printf("%d",a[j]);
      if(j!=n-1){
	printf(" ");
      }
    }
  printf("\n");
  insertionSort(a,n);
}

void insertionSort(int *A,int N){
  int i,j,v;
  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(j=0;j<N;j++){
      printf("%d",A[j]);
      if(j!=N-1){
	printf(" ");
      }
    }
    printf("\n");
  }
}
    
  
  

