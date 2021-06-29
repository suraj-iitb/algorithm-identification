#include <stdio.h>
#include <stdlib.h>

int main(){
  int flag = 0;
  int i,j;
  int tmp,cnt = 0;
  int N;
  int A[100];

  if(scanf("%d",&N) > 100)
    exit(1);
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || A[i] > 100)
      exit(2);
  }

  do{
    flag = 0;
    for(j = N-1; j > 0; j--){
      if(A[j] < A[j-1]){ 
	flag = 1;
	tmp = A[j-1];
	A[j-1] = A[j];
	A[j] = tmp;
	cnt++;
      }
    }       
  } while(flag==1);

  for(i = 0; i < N; i++){
    printf("%d",A[i]);
    if(i != N-1)
      printf(" ");
  }
  printf("\n%d\n",cnt);
  return 0;
}


