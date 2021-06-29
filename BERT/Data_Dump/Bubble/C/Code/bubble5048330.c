
#include<stdio.h>
int main(){
  int N,A[100];
  int i,j;
  int cnt=0,keep;
  int flag=1;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  i=0;
  while (flag){
    flag = 0;
    for (j = N-1;j>=i+1;j--){
      if (A[j] < A[j-1]){
	keep=A[j];
	A[j]=A[j-1];
	A[j-1]=keep;
	flag = 1;
	cnt++;
      }
      
    }
    i++;
  }
   for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i != N-1)printf(" ");
  }
  printf("\n%d\n",cnt);
  return 0;
}

