//ALDS1-1-A: Insertion Sort
//2019.05.24

#include <stdio.h>

int main(void){
  int n;
  scanf("%d\n", &n);
  int data[n];


  for (int i = 0; i < n; i++) scanf("%d\n", &data[i]);

  for (int k = 0; k < n; k++) {
    printf("%d", data[k]);
    if (k == n-1) {
      printf("\n");
    }else{
      printf(" ");
    }
  }

  int tmp;
  for (int i = 1; i < n; i++) {
    tmp = data[i];
    int j = i - 1;
    while(data[j] > tmp && j >= 0){
      data[j+1] = data[j];
      j--;
      data[j+1] = tmp;
    }
    for (int k = 0; k < n; k++) {
      printf("%d", data[k]);
      if (k == n-1) {
        printf("\n");
      }else{
        printf(" ");
      }
    }

  }

  return 0;
}

