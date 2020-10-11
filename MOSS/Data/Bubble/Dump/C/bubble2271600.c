#include <stdio.h>
#define N 100

int main(){
  int i,j,s,length,count=0,flag;
  int A[N];

  scanf("%d", &length);
  for(i=0; i<length; i++) {
    scanf("%d", &A[i]);
  }

  flag = 1;
  while(flag){
    flag = 0;
    for(j=0; j<length; j++) {
      if(A[j] < A[j-1]) {
	s = A[j];
	A[j] = A[j-1];
	A[j-1] = s;
	count ++;
	flag = 1;
      }
    }
  }

  for(i=0; i<length; i++) {
    printf("%d", A[i]);
    if(i!=length-1) 
      printf(" ");
  }
    printf("\n");
    printf("%d\n", count);
    return 0;
}
