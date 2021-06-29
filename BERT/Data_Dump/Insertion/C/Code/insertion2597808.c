#include<stdio.h>

int main()
{
  int data[99], n, i, j, A, M;
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%d", &data[i]);
  }
  
  printf("%d", data[0]);
  for (j = 1; j < n; j++){
      printf(" %d", data[j]);
  }
  printf("\n");
  
  
  for(i = 1; i < n; i++){
    if (data[i] < data[i-1]){
      M = data[i];
      for(j = 0; j < i; j++){
        if(M < data[j]){
          A = data[j];
          data[j] = M;
          M = A;
        }
        data[i] = M;
        
      }
    }
    printf("%d", data[0]);
    for (j = 1; j < n; j++){
      printf(" %d", data[j]);
    }
  printf("\n");
  }
  return 0;
}
