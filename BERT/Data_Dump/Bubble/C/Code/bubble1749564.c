#include<stdio.h>
#define N 100
int main(){
  int i,j,key,n,A[N],count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>=0;j--){
      if(A[j-1]>A[j]){
	key=A[j-1];
	A[j-1]=A[j];
	A[j]=key;
	count++;
      }  
    }
  }
  printf("%d",A[0]);
  for(i=1;i<n;i++){
    printf(" %d",A[i]);
  }
  printf("\n%d\n",count);
      return 0;
    
  }
