#include <stdio.h>

#define N 10000
#define Q 500

int compare(const void *a, const void *b){
  return *(int *)a - *(int *)b;
}

int *uniq(int *a, int *n){
  int i, j, prev = a[0];
  for(i=1, j=1; i<*n; i++){
    if(prev != a[i]){
      a[j] = a[i];
      prev = a[i];
      j++;
    }
  }
  *n = j;
  return a;
}

int main(void)
{
  int i, j, n, q, c=0;
  int S[N], T[Q];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }

  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d", &T[i]);
  }

  qsort(S, n, sizeof(int), compare);
  uniq(S, &n);

  for(i=0; i<n; i++){
    for(j=0; j<q; j++){
      if(S[i] == T[j]){
        c++;
      }
    }
  }
  printf("%d\n", c);

  return 0;
}
