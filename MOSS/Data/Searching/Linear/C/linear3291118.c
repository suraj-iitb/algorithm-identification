#include<stdio.h>
#define SMAX 10001
#define TMAX 500
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
  }

  printf("%d\n", cnt);
  
  return 0;
}

int search(int *s, int key, int n){
  int i = 0;
  s[n] = key;
  while(s[i] != key){
    i++;
    if(i == n) return NOT_FOUND;
  }
  return FOUND;
}

