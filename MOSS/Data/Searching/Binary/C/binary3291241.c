#include<stdio.h>
#define SMAX 100000
#define TMAX 50000
#define FOUND 1
#define NOT_FOUND 0

int search(int *, int, int);

int main(){
  int n, q, cnt = 0;
  int s[SMAX], t[TMAX];
  int i;

  scanf("%d", &n);
  for(i=0;i<n;i++) scanf("%d", &s[i]);

  scanf("%d", &q);
  for(i=0;i<q;i++){
    scanf("%d", &t[i]);
    cnt += search(s, t[i], n);
    //printf("%d\n", search(s, t[i], n));
  }

  printf("%d\n", cnt);
  
  return 0;
}

int search(int *s, int key, int n){
  int mid, left, right;
  left = 0;
  right = n;
  while(left < right){
    mid = (left + right) / 2;
    if(s[mid] == key) return FOUND;
    else if(s[mid] > key) right = mid;
    else left = mid + 1;
  }
  return NOT_FOUND;
}

