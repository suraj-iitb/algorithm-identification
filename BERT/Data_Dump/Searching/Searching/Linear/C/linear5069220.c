#include <stdio.h>
#define NOTFOUND 0
#define FOUND 1


int liniarsearch(int n, int a[10000], int key){
  int i = 0;
  while(a[i] != key){
    i++;
    if(i == n) return NOTFOUND;
  } 
  return FOUND;
}

int main(){
  int i, cnt=0, n, q, s[10000], t[500];

  //scanning
  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &s[i]);
  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", &t[i]);

  for(i = 0; i < q; i++){
    if(liniarsearch(n, s, t[i]) == FOUND) cnt++;
    else if(liniarsearch(n, s, t[i]) == NOTFOUND) continue;
    }
  
  printf("%d\n", cnt);
  
  return 0;
}

