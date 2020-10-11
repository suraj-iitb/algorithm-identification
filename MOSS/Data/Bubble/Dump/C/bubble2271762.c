#include<stdio.h>
#define N 100

int main(){
  int i, j, s, t, flag, temp;
  int A[N];

  scanf("%d",&s);
  for(j = 0; j < s; j++){
    scanf("%d",&A[j]);
  }
  
  flag = 1;
  i = 0;
  t = 0;
  while(flag){
    flag = 0;
    for(j = s - 1; j >= i + 1; j--){
      if(A[j] < A[j-1]){
	temp = A[j];
	A[j] = A[j-1];
	A[j-1] = temp;
	flag = 1;
	t++;
      }
    }
    i++;
  }

  for(j = 0; j < s; j++){
    printf("%d",A[j]);
    if(j != s - 1) printf(" ");
  }
  printf("\n%d\n",t);
  
  return 0;
}
