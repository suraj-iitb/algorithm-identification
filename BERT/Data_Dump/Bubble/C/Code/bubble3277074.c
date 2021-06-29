#include<stdio.h>

int main()
{
  int N,A[100];
  int i,j,flag=1,cnt=0;
  int a;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  while(flag){
    flag = 0;
    for(j=N-1;j>=1;j--){
      if(A[j] < A[j-1]){
	a = A[j];
	A[j] = A[j-1];
	A[j-1] = a;
	flag = 1;
	cnt++;
      }
      else continue;
    }
  }
  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

