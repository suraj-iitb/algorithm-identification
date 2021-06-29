#include <stdio.h>
#define NOTFOUND 0

int binarysearch(int n, int a[100000], int key){
  int left = 0, right = n, mid;
  while(left < right){
    mid = (left + right) / 2;
    if (a[mid] == key) return a[mid];
    else if (a[mid] > key) right = mid;
    else left = mid+1;
  }
  return NOTFOUND;
}
int main(){
  int i, cnt=0, n, q, s[100000], t[50000];

  //scanning
  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &s[i]);
  scanf("%d", &q);
  for(i = 0; i < q; i++) scanf("%d", &t[i]);

  //search
  for(i = 0; i < q; i++){
    if(binarysearch(n, s, t[i]) == t[i]) cnt++;
    else continue;
    }
  
  printf("%d\n", cnt);
  

  return 0;
}

