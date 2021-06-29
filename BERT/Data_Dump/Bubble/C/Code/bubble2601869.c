#include<stdio.h>

int main(){
  int n, i, j, flag, count, A;
  int data[99];
  count = 0;
  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%d", &data[i]);
  }

  flag = 1;
  while(flag){
    flag = 0;
    for(j = n-1; j >= 1; j--){
      if (data[j] < data[j-1]){
        A = data[j];
        data[j] = data[j-1];
        data[j-1] = A;
        count++;
        flag = 1;
      }
    }
  }
  printf("%d", data[0]);
  for(i = 1; i < n; i++){
    printf(" %d", data[i]);
  }
  printf("\n%d\n", count);
}
