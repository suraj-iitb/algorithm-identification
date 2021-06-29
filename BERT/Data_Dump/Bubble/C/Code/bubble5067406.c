#include<stdio.h>

int main(){
    
  int flag=1, j, N, A[100], num, cnt=0;
    
  scanf("%d",&N);
    
  for(j=0;j<N;j++){
    scanf("%d",&A[j]);
  }

  while(flag == 1){
    flag = 0;
    for(j=N-1;j>=1;j--){
      if(A[j] < A[j-1]){
	num = A[j];
	A[j] = A[j-1];
	A[j-1] = num;
	flag = 1;
	cnt++;
      }
    }
  }
   
  for(j=0;j<N;j++){
    if (j != 0){
      printf(" ");}
    printf("%d",A[j]);
  }
  printf("\n%d\n",cnt);

  return 0;
}

