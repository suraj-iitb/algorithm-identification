#include <stdio.h>

int A[100000], n;
int search(int key){
  int l = 0;
  int r = n;
  int m;
  while (l < r) {
    m = (l + r) / 2 ;
    if (A[m] == key) {
      return 1;
    }
    else if (key > A[m]) {
      l = m + 1;
    }
    else if (key < A[m]) {
      r = m;
    }
  }
  return 0;
}

int main() {
  int i,q,key,cnt=0;

  scanf("%d",&n);
  for (i = 0; i < n; i++) {
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);
  for (i = 0; i < q; i++) {
    scanf("%d",&key);
    if (search(key)) {
      cnt++;
    }
  }
  printf("%d\n",cnt);
  return 0;
}

