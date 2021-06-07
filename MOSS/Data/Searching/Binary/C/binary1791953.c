#include <stdio.h>

int binarySearch(int, int, int*);

int main() {
  int n, q, i, count = 0; 
  int s[100000], t;
  
  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&s[i]);
  
  scanf("%d",&q);
  for(i = 0;i < q;i++) {
    scanf("%d",&t);
    count += binarySearch(n,t,s);
  }
  
  printf("%d\n",count);
  
  return 0;
}

int binarySearch(int n,int key,int s[]) {
  int left = 0;
  int right = n;
  int mid;
  while(left < right) {
    mid = (left + right) / 2;
    if(key == s[mid]) return 1;
    if(key > s[mid]) left = mid + 1;
    else if(key < s[mid]) right = mid;
  }
  return 0;
}
