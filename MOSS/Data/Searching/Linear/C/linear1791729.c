#include <stdio.h>

int linearSearch(int,int,int*);

int main() {
  int n, q, i, j, count = 0; 
  int s[10001], t;
  
  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&s[i]);
  scanf("%d",&q);
  for(i = 0;i < q;i++) {
    scanf("%d",&t);
    count += linearSearch(n,t,s);
  }
  printf("%d\n",count);
  
  return 0;
}

int linearSearch(int n,int key,int s[]) {
  int i=0;
  s[n] = key;
  while(s[i] != key) {
    i++;
  }
  if(i != n) return 1;
  else return 0;
}
