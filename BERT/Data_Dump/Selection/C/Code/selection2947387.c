#include<stdio.h>

int main(){
  int A[100],i,j,n,tmp;
  int minj,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);

  for(i=0;i<n-1;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(A[j] < A[minj])
        minj = j;
    }
    if(i != minj){
    count++;
  }
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
  }
  for(i=0;i<n-1;i++)
    printf("%d ",A[i]);
  printf("%d\n%d\n",A[n-1],count);

  return 0;
}

