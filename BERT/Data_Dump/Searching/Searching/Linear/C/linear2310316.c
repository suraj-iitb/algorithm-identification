#include <stdio.h>
#include <stdlib.h>

int linear(int *, int*, int, int);
int same(int *, int*, int, int);

int main() {
  int *s, *t;
  int n, q, i;

  scanf("%d", &n);
  s = (int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++){
    if(scanf("%d", &s[i])==EOF)break;
  }

  scanf("%d", &q);
  t = (int *)malloc(q*sizeof(int));
  for(i=0;i<q;i++){
    if(scanf("%d", &t[i])==EOF)break;
  }

  printf("%d\n", linear(s, t, n, q));

  free(s);
  free(t);
  
  return 0;
}

int linear(int *s, int *t, int n, int q){
  int i, j;
  int count = 0;
  for(i=0;i<n;i++){
    for(j=0;j<q;j++){
      if(s[i]==t[j] && same(s, t, i, j)==0) count++;
    }
  }

  return count;
}

int same(int *s, int *t, int k, int l){
  int i;

  for(i=0;i<k;i++){
    if(s[i]==s[k]) return 1;
  }
  for(i=0;i<l;i++){
    if(t[i]==t[l]) return 1;
  }

  return 0;
}
