#include<stdio.h>

void insertionSort(int A[],int N){
  int i,v,j,r;
  for(r=0;r<N;r++){
      if(r==N-1){
	printf("%d\n",A[r]);
      }
      else{
	printf("%d ",A[r]);
      }
    }
  for(i=1;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(r=0;r<N;r++){
      if(r==N-1){
	printf("%d\n",A[r]);
      }
      else{
	printf("%d ",A[r]);
      }
    }
  }
}
  

int main(void){
  int i,n;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  insertionSort(a,n);
  return 0;
}
