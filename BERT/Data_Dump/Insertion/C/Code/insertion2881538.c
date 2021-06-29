#include<stdio.h>
#define MAX 101

void print(int n,int *A){
  int i;
  for(i=0;i<n-1;i++)
    printf("%d ",A[i]);
  printf("%d\n",A[i]);
}

void insertion_sort(int n,int *A){
  int i,j,v;
  for(i=0;i<n;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    print(n,A);
  } 
}

int main(){
  int n,i;
  int a[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  insertion_sort(n,a);
  return 0;
}

