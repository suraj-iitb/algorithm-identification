#include<stdio.h>
#define N 100

int main(){
  int A[N],i,j,minj,n,tmp,count;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n;i++){
    minj = i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    if(i!=minj){
      count++;
    }
    
  }

  for(i=0;i<n;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
  

  return 0;
}

  

