#include<stdio.h>

int main()
{
  int n, i, j,  minj, A, count;
  int data[99];
  count = 0;
   
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &data[i]);
  }
  
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(data[j] < data[minj]){
        minj = j;
      }
    }
    A = data[i];
    data[i] = data[minj];
    data[minj] = A;
    if(i != minj){
      count++;
    }
  }

  
  printf("%d", data[0]);
  for(i = 1; i < n; i++){
    printf(" %d", data[i]);
  }
  printf("\n%d\n", count);
}
