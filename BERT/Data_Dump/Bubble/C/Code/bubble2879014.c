#include<stdio.h>
#define MAX 101

int count = 0;

void bubble_sort(int n,int *A){
  int i,j,tmp;
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        count++;
      }
    }
  }
}

int main(){
  int n,i,j,tmp;
  int A[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  bubble_sort(n,A);
  for(i=0;i<n-1;i++)
    printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
}

