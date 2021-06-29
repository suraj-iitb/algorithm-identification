#include <stdio.h>

void InsertionSort(int n, int nums[]) {
  int i, j, k;
  int v;

  for (k = 0; k < n; k++) {
    printf("%d", nums[k]);
    if (k == n-1)  {
      putchar ('\n');
      break;
    }
    putchar(' ');
  }
  
  for (i = 1; i < n; i++) {
    v = nums[i];
    j = i-1;
    while (0 <= j && v < nums[j]) {
      nums[j+1] = nums[j];
      j--;
    }
    nums[j+1] = v;
    for (k = 0; k < n; k++) {
      printf("%d", nums[k]);
      if (k == n-1)  {
	putchar ('\n');
	break;
      }
      putchar(' ');
    }
  }
  
}

int main() {
  int n;
  int nums[100];

  scanf("%d", &n);

  int i;
  for (i = 0; i < n; i++) {
    scanf("%d", &nums[i]);
  }

  InsertionSort(n, nums);

  return 0;
}
