#include <stdio.h>

int selectionSort(int A[],int n){
  int i,j;
  int tmp,count=0;
  for(i=0;i<n;i++){
    int minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]) minj=j;
    }
    if(i!=minj){
      tmp=A[i];
      A[i]=A[minj];
      A[minj]=tmp;
      count++;
    }
  }
  return count;
}

int main(void){
  int i,n;
  scanf("%d",&n);
  int A[n],count;
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  count=selectionSort(A,n);
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

