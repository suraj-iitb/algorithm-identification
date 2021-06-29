#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
   return 1 if found
          0 else anything
 */
int
binary_search(int target, int xs[], int size) {
  int left=0, right = size;
  do {
    // printf("BGN left:%d right:%d\n", left, right);
    int mid = (left + right) / 2;    
    if (target < xs[mid]) {
      right = mid;
    } else {
      left = mid;
    }
    // printf("END left:%d right:%d\n", left, right);    
  } while (left < right - 1);
  // printf("LST left:%d right:%d\n", left, right);      
  if (xs[left] == target) return 1;
  
  return 0;
}

int
main() {
  //  int xs[] = { 1,2,2,2,3,4,5 };
  /*
  int xs[] = { 10, 14, 19, 26, 27, 31, 33,35, 42,44 };
  int size = sizeof(xs) / sizeof(xs[0]);
  assert(1 == binary_search(10, xs, size) );
  assert(1 == binary_search(44, xs, size) );
  assert(1 == binary_search(26, xs, size) );
  assert(0 == binary_search(1, xs, size) );
  */
  int *s, *t;
  s = malloc(sizeof(int)*100000);
  t = malloc(sizeof(int)*50000);
  int n, q;
  scanf("%d", &n);
  int i;
  for (i=0;i<n;++i) {
    int v;
    scanf("%d", &v);
    s[i] = v;
    // printf("%d:%d\n", i, s[i]);
  }
  scanf("%d", &q);
  for (i=0;i<q;++i) {
    int v;
    scanf("%d", &v);
    t[i] = v;
  }
  int sum = 0;
  for (i=0;i<q;++i) {
    int tv = t[i];
    sum += binary_search(tv, s, n);
  }
  printf("%d\n", sum);
  free(s);
  free(t);
  s = NULL; t = NULL;
  return 0;
}
