#include<stdio.h>
#define N 100

int main(){
  int i = 0,j = 0, flag = 1,n = 0,a = 0,b = 0;
  int A[N];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++)
    scanf("%d",&A[i]);

  i = 0;
  
  while(flag == 1){
    flag = 0;
    for(j = n - 1 ; j >= i+1 ; j--){
      if(A[j] < A[j-1]){
	a = 0;
	a = A[j];
	A[j] = A[j-1];
	A[j-1] = a;
	flag = 1;
	b++;
      }
    }
    i++;
  }

  for(j = 0 ; j < n ; j++){
    printf("%d",A[j]);
    if(j <= n-2) printf(" ");
  }
  printf("\n");
  printf("%d\n",b);

  return 0;
}
