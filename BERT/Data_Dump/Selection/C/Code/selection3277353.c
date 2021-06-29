#include<stdio.h>

int main(){
  int A[100];
  int j,temp,N,s,min;
  int i = 0,a = 0;

  scanf("%d",&N);

  for(i = 0; i <= N-1; i++) scanf("%d",&A[i]);

  for(i = 0; i <= N-1; i++){
    min = i;
    for(j = i; j <= N-1; j++){ 
      if(A[j] < A[min])
	min = j;
    }
      temp = A[i];
      A[i] = A[min];
      A[min] = temp;
      if(i != min) a++;
  }
    
  for(s = 0; s <= N-1; s++){
    if(s > 0) printf(" ");
    printf("%d",A[s]);
  }
  printf("\n");
  printf("%d\n",a);

  return 0;
   
}

