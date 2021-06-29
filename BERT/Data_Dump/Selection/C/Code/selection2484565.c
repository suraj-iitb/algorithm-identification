#include <stdio.h>
int main(){
  int n,i,j,temp,min,flag,count = 0;
  int A[100];
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }
  for(i = 0;i < n;i++){
    min = i;
    for(j = i+1;j < n;j++){
      if(A[j] < A[min])   min = j;
    }
    if(A[i] > A[min]){
      temp = A[i];
      A[i] = A[min];
      A[min] = temp;
      count++;
    }
  }
  for(i = 0 ;i < n;i++){
    printf("%d",A[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
