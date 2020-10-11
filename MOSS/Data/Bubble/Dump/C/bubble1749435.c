#include<stdio.h>

#define N 100

int main(){
  int i, j, n, A[N], flag=1, cnt=0, a=0;

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  i = 0;
  while(flag == 1){
    flag = 0;
    for(j = n-1; j >= i+1; j--){
      if(A[j] < A[j-1]){
	a = A[j-1];
	A[j-1] = A[j];
	A[j] = a;
	cnt++;
	flag = 1;
      }
    }
    i++;
  }

  for(i = 0; i < n-1; i++){
    printf("%d ", A[i]);
  }
  printf("%d\n%d\n",A[i],cnt);

  return 0;
}
