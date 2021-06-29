#include<stdio.h>
#include<stdlib.h>

void int_display(int *A,int n)
{
  int i;
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n");
}

void insertion_sort(int *A,int n)
{
  int i,j,key;
  int_display(A,n);
  for(i=1;i<=n-1;i++){
    key=A[i];
    j=i-1;
    while(j>=0 && A[j]>key){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=key;
    int_display(A,n);
  }
}

int main()
{
  int *A;
  int i,n;
  scanf("%d",&n);
  A=malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  insertion_sort(A,n);
  return 0;
}
