#include<stdio.h>


#define N 100


int main(){
  int A[N],n,i,j,minj,key,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(A[i]!=A[minj]){
      key=A[i];
      A[i]=A[minj];
      A[minj]=key;
      count++;
    }
  }
    

  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[n-1],count);
  return 0;
}

