#include<stdio.h>

int binarySearch(int *, int, int);

int main(){
  int i, j, n, q;
  int cnt = 0;
  int s[100000], t[50000];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &t[i]);
    cnt = cnt + binarySearch(s, n, t[i]);
  }
  printf("%d\n", cnt);
  
  return 0;
}

int binarySearch(int *a, int n, int key){
  int mid;
  int left  = 0;
  int right = n;

  while(left < right){
    mid = (left + right) / 2;
    if(a[mid] == key) return 1;
    else if(key < a[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}

