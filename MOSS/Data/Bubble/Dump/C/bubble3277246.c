#include<stdio.h>

int main(){
  int A[100];
  int flag,j,temp,N,s;
  int i = 0,a = 0;

  scanf("%d",&N);

  for(i = 0; i <= N-1; i++) scanf("%d",&A[i]);
  
  flag = 1;

  while(flag){
    flag = 0;
    for(j = N-1; 1 <= j; j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag = 1;
	a++;
      }
    }
  }

  for(s = 0; s <= N-1; s++){
    if(s > 0) printf(" ");
    printf("%d",A[s]);
  }
  printf("\n");
  printf("%d\n",a);

   return 0;
   
}

  

