#include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  int num[n];
  int count = 0;
  for(int i = 0; i < n; i++) scanf("%d", &num[i]);
  for(int i = 0; i < n; i++){
    int minj = i;
    for(int j = i; j < n; j++){
      if(num[j] < num[minj]) {
        minj = j;
      }
    }
    if(i != minj) count++;
    int tmp = num[minj];
    num[minj] = num[i];
    num[i] = tmp;
  }
  for(int i = 0; i < n; i++){
    printf("%d", num[i]);
    if(i != n - 1) printf(" ");
    else printf("\n");
  }
  printf("%d\n", count);
  return 0;
}
