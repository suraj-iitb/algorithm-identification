#include<stdio.h>
#define N 100

int main(){

  int i,j,k,l,A[N],flag = 1,count = 0;

  scanf("%d",&j);

  for(i = 0;i < j;i++){
    scanf("%d",&A[i]);
  }

  for(i = 0;i < j;i++){
    while(flag == 1){
      flag = 0;
      for(k = j-1;k != 0;k--){
	l = A[k];
	if(A[k] < A[k-1]){
	  A[k] = A[k-1];
	  A[k-1] = l;
	  flag = 1;
	  count++;
	}
      }
    }
    
    //printf("%d",A[i]);
    //if(k != j-1)printf(" ");
  }
  for(i=0;i<j-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
}

