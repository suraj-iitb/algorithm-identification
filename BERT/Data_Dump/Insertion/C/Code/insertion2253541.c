#include <stdio.h>

void listElements(int*, int);

int main() {
  int i = 0, j, n, key;
  int num[100];
  
  scanf("%d ", &n);
  while((scanf("%d", &num[i])) != EOF) {
    i++;
  }
  
  for (i = 1; i < n; i++) {
    listElements(num, n); 
    key = num[i];
    j = i -1;
    
    while(j >= 0 && num[j] > key) {
      num[j+1] = num[j];
      j--;
    }
    num[j+1] = key;
  }
  listElements(num, n); 
  
  return 0;
}

void listElements(int *num, int n) {
  int i;
  for(i = 0; i < n; i++) {
    if (i == (n-1)) {
      printf("%d\n", num[i]);
      break;
    }
    printf("%d ", num[i]);
  }
  return;
}
