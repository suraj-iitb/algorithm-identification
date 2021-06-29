#include<stdio.h>
#define N 100

int main(){
  
  int i,j,n,key,count=0;
  int A[N];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<=n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	key = A[j];
	A[j] =A[j-1];
	A[j-1] = key;
	count++;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
  
  return 0;
}

