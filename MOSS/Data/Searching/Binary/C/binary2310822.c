#include <stdio.h>
#define N 100000

int a (int key);

int n;
int s[N];
int main() {

  int key, c = 0;
  int i, q;

  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &s[i]);
  }
  scanf("%d", &q);
  for(i=0;i<q;i++){
    scanf("%d", &key);
    if(a(key) == 1) c++;
  }
  printf("%d\n", c);
  return 0;
}

int a (int key) {
  int l = 0, r = n, mid;
  while(l<r){
    mid =(l+r)/2;
    if(key == s[mid]) return 1;
    if(key > s[mid]) l = mid+1;
    else if(key < s[mid]) r = mid;
  }
  return 0;
}
