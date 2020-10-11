#include <stdio.h>
int main(){
  int j, n, tmp, cnt = 0;
  int A[100];
  int flag = 1;

  scanf("%d", &n);
  for(j = 0; j < n; j++)
    scanf("%d", &A[j]);

  while(flag == 1){
    flag = 0;
    for(j = n-1; j >= 1; j--){
      if(A[j] < A[j-1]){
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        flag = 1;
        cnt++;
      }
    }
  }
  for(j = 0; j < n-1; j++)
    printf("%d ", A[j]);
  printf("%d\n", A[j]);
  printf("%d\n", cnt);
  return 0;
}
