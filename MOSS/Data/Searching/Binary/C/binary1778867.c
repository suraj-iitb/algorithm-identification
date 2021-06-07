#include<stdio.h>
#define N 100000
#define Q 50000

int search(int);
int S[N];
int n;

int main() {
  int q,T[Q],i,j,x,count=0;
  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(i = 0; i < q; i++) {
    scanf("%d",&T[i]);
  }
  for(i = 0; i < q; i++) {
   x = search(T[i]);
    if(x == 1 ) {
      count++;
          }
  }
  printf("%d\n",count);
  return 0;
}

int search(int key) {
  int left = 0,right,mid;
  right = n;
  while(1) {
    mid =(left + right) / 2;
    if(key == S[mid]) {
      return 1;
    }
    if(key < S[mid]) right = mid;
    else if(key > S[mid]) left = mid + 1;
    if(left == right)
      {
        break;
      }
  }
  return 0;
}
