#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

int binarySearch(int *, int, int);

int main(){
  int n,q;
  int *s, *t;
  int i,j;
  int count=0;

  scanf("%d",&n);
  s = (int *)malloc(sizeof(int) * n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  t = (int *)malloc(sizeof(int) * q);
  for(i = 0 ; i < q ; i++){
    scanf("%d",&t[i]);
  }

  for(i = 0 ; i < q ; i++){
    if(binarySearch( s, t[i], n)) count++;
  }
  printf("%d\n",count);

  free(s);
  free(t);
  return 0;
}

int binarySearch(int *s, int t, int n){
  int flag=0;
  int l, r, m;
  int i=0;

  l = 0;
  r = n;
  m = (l + r) / 2;

  while(l < r){
    m = (l + r) / 2;
    if(s[m] == t) return TRUE;
    else if(t < s[m]) r = m;
    else l = m + 1;
  }
  return FALSE;
}
