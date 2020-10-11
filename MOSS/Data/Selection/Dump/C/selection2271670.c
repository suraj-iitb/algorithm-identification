#include<stdio.h>

#define N 100

int selectionSort(int *, int);

int main(){

  int A[N],n,i,cunt;

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&A[i]);

  cunt =  selectionSort(A,n);

  for(i=0;i<n-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",cunt);
  
  return 0;

}

int selectionSort(int A[], int n){
  int i,j,key,cunt = 0,minj;

  for(i=0;i<n;i++){
    minj = i;

    for(j=i;j<n;j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    key = A[i];
    A[i] = A[minj];
    A[minj] = key;
    if(i != minj)cunt++;
  }
  return cunt;
}
