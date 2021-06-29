#include <stdio.h>

#define MAX 101
void selectionSort(int *,int);

int main(void){
  int A[MAX],i,j,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,n);
  return 0;
}

void selectionSort(int A[],int n){
  int i,j,a,minj,tmp,count=0,flag;

  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
        minj=j;
      }
    }
    tmp = A[i];
    A[i]=A[minj];
    A[minj]=tmp;
    if(i!=minj)count++;
  }
  for(a=0;a<n;a++){
    printf("%d",A[a]);
    if(a!=n-1)printf(" ");
  }
  printf("\n%d\n",count);
}
