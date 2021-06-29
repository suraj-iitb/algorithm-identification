#include<stdio.h>

int main()
{
  int N = 0,k = 0,i = 0,v = 0,j = 0,A[1000],l = 0;
  scanf("%d",&N);
  if(0 <= N && N <= 100){
    for(k = 0;k < N;k++){
      scanf("%d",&A[k]);
      printf("%d",A[k]);
      if(k < N-1){
	printf(" ");
      }
    }
    printf("\n");
    for(i = 1;i <= N-1;i++){
      v = A[i];
      j = i - 1;
      while(j >= 0 && A[j] > v){
	A[j+1] = A[j];
	j--;
      }
      A[j+1] = v;
      for(l = 0;l < N;l++){
	printf("%d",A[l]);
	if(l < N-1){
	  printf(" ");
	}
      }
      printf("\n");
    }
  }
  return 0;
}

