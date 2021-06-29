#include <stdio.h>
#define N 100

int main(){
  int i=0,j,n,minj,temp,count=0,flag=0;
  int A[N];
  
  scanf("%d",&n);
  while(i < n){
    scanf("%d",&A[i]);
    if(A[i]>=0 && A[i]<=100)i++;
  }
  
  for(i=0; i < n; i++){
    minj = i;   
    for(j=i; j<n; j++){
      if(A[j] < A[minj]){
	minj = j;
	flag = 1;
      }
    }
    if(flag == 0)continue;
    flag = 0;   
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;
    count++;
  }
  
  for(i=0; i<n-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  
  return 0;
}

