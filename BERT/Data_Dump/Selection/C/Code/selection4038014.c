#include <stdio.h>
#define N 100

int selectionSort(int *,int);
void printA(int *,int);
void swap(int *,int *);

int main(){
  int i,n,A[N],count;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  count=selectionSort(A,n);
  printA(A,n);
  printf("%d\n",count);
  return 0;
} 
int selectionSort(int A[],int n){
  int i,j,count=0,minj;
  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if (A[j] < A[minj]){
	minj = j;
      }
    }
    if(i!=minj){
      swap(&A[i],&A[minj]);
      count++;
    }
  }
  return count;
}
void printA(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n");
}

void swap(int *p1,int *p2){
  int temp;
  temp=*p1;
  *p1=*p2;
  *p2=temp;
}

