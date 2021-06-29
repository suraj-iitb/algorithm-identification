#include <stdio.h>
#define N 100
int main(){

  int i,j,n,A[N],temp,count=0,minj;

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
    if(i!=minj){
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      count++;
    }
  }


  for(j=0;j<n;j++){
    printf("%d",A[j]);
    if(j==n-1) break;
    printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

