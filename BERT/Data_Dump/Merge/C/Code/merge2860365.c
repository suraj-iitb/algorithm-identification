#include <stdio.h>
#define L 500000

int s[L];
int workspace[L];
int cnt = 0;

void mergeSort(int *a, int low, int high) {
  int mid, i, j, k;

  if(low >= high)
    return;

  mid = (high + low) / 2;
  mergeSort(a, low, mid);
  mergeSort(a, mid + 1, high);

  for(i = low;i <= mid;i++) {
    workspace[i] = a[i];
  }

  for(i = 0;i <= high - mid - 1;i++) {
    workspace[mid + i + 1] = a[high - i];
  }

  j = low;
  k = high;
  int l;
  for(i = low;i <= high;i++) {
    cnt++;
    if(workspace[j] <= workspace[k])
      a[i] = workspace[j++];
    else
      a[i] = workspace[k--];
  }
}

int main() {
  int n, i;

  scanf("%d", &n);
  for(i = 0;i < n;i++)
    scanf("%d", &s[i]);

  mergeSort(s, 0, n - 1);

  for(i = 0;i < n - 1;i++)
    printf("%d ", s[i]);
  printf("%d\n", s[i]);
  printf("%d\n", cnt);

  return 0;
}

