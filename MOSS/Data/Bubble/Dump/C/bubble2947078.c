#include<stdio.h>

int main(){

  int i;
  int length;
  
  scanf("%d",&length);

  int A[length];

  for (i = 0 ; i < length ; i++){
    scanf("%d",&A[i]);
  }

  int flag = 1;
  int j;
  int tmp;
  int counter = 0;
  

  while (flag){
    flag = 0;
    for(j = length - 1 ; j > 0 ; j-- ){
      if( A[j] < A[j - 1] ){

	tmp = A[j];
	A[j] = A[j - 1];
	A[j - 1] = tmp;

	flag = 1;
	counter++;
      }
    }
  }


  for(i = 0 ; i < length ; i++){
    printf("%d",A[i]);
    if(i < length - 1)printf(" ");
  }
  
  printf("\n");

  printf("%d\n",counter);
  
  
  return 0;
}

