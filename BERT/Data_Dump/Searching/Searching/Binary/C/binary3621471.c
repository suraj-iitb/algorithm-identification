#include <stdio.h>

int s[100000];
int n;

int binary_search(int key) {
  int left = 0;
  int right = n;
  int mid;
  while(left < right) {
    mid = (left + right) / 2;
    if (s[mid] == key)
      return 1;
    else if (s[mid] > key) 
      right = mid;
    else 
      left = mid + 1;
  }
  return 0;
}
  
int main(void) {
  int q;
  int t;
  int i;
  int count = 0;
    
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &s[i]);
  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &t);
    if (binary_search(t))
      count++;
  }
  
  printf("%d\n", count);
    
  return 0;
}

