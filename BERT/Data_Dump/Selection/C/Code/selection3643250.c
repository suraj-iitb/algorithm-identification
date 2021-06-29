#include<stdio.h>

int main(void){
  int n, minj, buffa;
  int count = 0;
  int MAX = 100;
  int R[MAX], i , j, k, flag;
  scanf("%d", &n);

  for(k=0;k<n;k++) scanf("%d", &R[k]);

  for(i=0;i<n-1;i++){
    minj = i;
    flag = 0;
    for(j=i;j<n;j++){
      if(R[minj]>R[j]){ 
        minj = j;
        flag = 1;
      } 
    }
    if(flag == 1){
    buffa = R[minj];
    R[minj] = R[i];
    R[i] = buffa;
    count = count + 1;

    }}

  for(i=0;i<n-1;i++) printf("%d ", R[i]);
  printf("%d\n", R[n-1]);
  printf("%d\n", count);
  return 0;
}



