#include <stdio.h>
#define N 100

int main(){
  int i = 0, j = 0, k = 0;
  int flag = 1, n = 0, key = 0;
  int A[N];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  while(flag >= 1){
    flag = 0;
    for(i = n-1; i >= 1; i--){
      if(A[i] < A[i-1]){
	key = A[i-1];
	A[i-1] = A[i];
	A[i] = key;
	flag = 1;
	k++;
      }
    }
  }

  for(i = 0; i < n; i++){
    printf("%d",A[i]);
    if(i == n-1)printf("\n");
    else printf(" ");
  }
  printf("%d\n",k);
  
  return 0;
}

