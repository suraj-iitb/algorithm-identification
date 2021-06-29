#include <stdio.h>
#define N 100000
#define Q 50000

int T[Q],S[N];
int n, c;
void BinarySearch(int);

int main() {

  int i, q;

  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  for(i=0; i<q; i++) scanf("%d", &T[i]);

  for(i=0; i<q; i++) {
    BinarySearch(T[i]);
  }
  printf("%d\n", c);
  return 0;
}

void BinarySearch(int key){
  int left, right, mid;
  left = 0;
  right = n;
  while(left < right) {
    mid = (left + right) / 2;

    if(S[mid]==key){
      c++;
      break;
    }
    else if(key < S[mid]) right = mid;
    else left = mid + 1;
  }
}
