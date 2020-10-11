#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print_list(int *A,int n){
  int i;
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)
      printf(" ");
    else
      printf("\n");
  }
}

void insertion_sort(int *A,int n){
  int i,j,temp;
  print_list(A,n);//??¨?????¨
  for(i=1;i<n;i++){
    temp=A[i];
    j=i-1;
    while(j>=0&&A[j]>temp){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=temp;
    print_list(A,n);//??¨?????¨
  }
}

int main(void){
  int *A,i,n;
  
  scanf("%d",&n);
  A=(int *)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  insertion_sort(A,n);
  
  free(A);
  return(0);
}
