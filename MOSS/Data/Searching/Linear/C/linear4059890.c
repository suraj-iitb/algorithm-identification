#include<stdio.h>

int main(){

  int N1,N2,i,j,key,count=0;

  scanf("%d", &N1);
  int A[N1];
  for(i=0;i<N1;i++)scanf("%d",&A[i]);
  scanf("%d", &N2);
  int B[N2];
  for(i=0;i<N2;i++)scanf("%d",&B[i]);

  for(i = 0 ; i< N2 ; i++){
    j = 0;
    key = B[i];
    while(1){
      if(j == N1)break;
      if(A[j] == key){
	count++;
	break;
      }
      j++;
    }
  }

  printf("%d\n",count);

  return 0;
}


