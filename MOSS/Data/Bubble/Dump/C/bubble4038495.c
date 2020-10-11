#include<stdio.h>

int main(){
  int A[100],i,j,k,temp,cnt=0;
  scanf("%d",&k);
  for(i=0;i<k;i++){
    scanf("%d",&A[i]);
  }
  for (i = 0;i < k-1 ;i++) {
    for (j = 0;j < k-1 ;j++) {
      if (A[j + 1] < A[j]) {
	temp = A[j];
	A[j] = A[j + 1];
	A[j + 1] = temp;
	cnt++;
      }
    }
  }
    
    
    for(i=0;i<k;i++){
      if(i)printf(" ");
      printf("%d",A[i]);
    }
    printf("\n");
  printf("%d\n",cnt);
  return 0;
  }
  

