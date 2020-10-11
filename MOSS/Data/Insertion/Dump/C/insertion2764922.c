#include <stdio.h>
#include <string.h>

void printArr(int arr[], int n) {
  char space[2] = "";
  for (int i = 0; i < n; i++) {
    printf("%s", space);
    printf("%d", arr[i]);
    strcpy(space, " ");
  }
  printf("\n");
}

int main(void) {
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  printArr(a, n);
  for (int i = 1; i < n; i++) {
    int tmp = a[i];
    int j;
    for (j = i - 1; j >= 0 && a[j] > tmp; j--) {
      a[j + 1] = a[j];
    }
    a[j + 1] = tmp;
    printArr(a, n);
  }
}
