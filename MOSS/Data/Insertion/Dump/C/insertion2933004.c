#include <stdio.h>
#include <stdlib.h>
 
void InsertionSort(int *a, int n);
void Nprint(int *a, int n);
 
int main(void){
  int i, n, *a;
 
  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  if(a == NULL){
    printf("?????¢????¢??????¨??????\n");
    return -1;
  }
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  InsertionSort(a, n);
  return 0;
}
 
 
void InsertionSort(int *a, int n){
  int i, j, temp;
 
  Nprint(a, n);
 
  for(i = 1; i < n; i++){
    for(j = i-1; j >= 0; j--){
      if(a[j] < a[j+1])  break;
      temp = a[j];
      a[j] = a[j+1];
      a[j+1] = temp;
    }
    Nprint(a, n);
  }
}
 
 
void Nprint(int *a, int n){
  int i;
 
  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    if(i < n-1){
      printf(" ");
    }
  }
  printf("\n");
}
