#include <stdio.h>
#include <stdlib.h>

int main() {
  int cnt=0, i, right, left, mid, *a, t, n, q;

  scanf("%d", &n);
  a = (int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++) scanf("%d", &a[i]);

  scanf("%d", &q);
  for(i=0;i<q;i++) {
    scanf("%d", &t);
    left = 0;
    right = n;
    while(left<right) {
      mid = (right+left)/2;
      if(a[mid]==t) {
	cnt++;
	break;
      }
      else if(a[mid]>t) right = mid;
      else left = mid + 1;
    }
  }

  printf("%d\n", cnt);
  
  free(a);
  return 0;
}

