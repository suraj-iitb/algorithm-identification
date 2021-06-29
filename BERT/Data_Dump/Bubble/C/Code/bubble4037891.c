#include <stdio.h>
#define N 100

int bubbleSort(int *,int);
void printA(int *,int);
void swap(int *,int *);

int main(){
  int i,n,A[N],count;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  count=bubbleSort(A,n);
  printA(A,n);
  printf("%d\n",count);
  return 0;
} 

int bubbleSort(int A[],int n){
  int i,j,flag = 1,count=0;
  while(flag){
    flag = 0;
    for(j=n-1;j>0;j--){
      if (A[j] < A[j-1]){
	swap(&A[j],&A[j-1]);
	flag = 1;
	count++;
      }
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

