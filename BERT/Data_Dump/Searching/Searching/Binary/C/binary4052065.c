#include <stdio.h>

int binarySearch(int *, int, int);

int main(){
  int n, q, s[100000], t, a, count=0;

  scanf("%d",&n);
  for(a = 0; a < n; a++){
    scanf("%d",&s[a]);
  }
  scanf("%d",&q);
  for(a = 0; a < q; a++){
    scanf("%d",&t);
    if(binarySearch(s,n,t) != -1) count++;
  }

  printf("%d\n",count);
  return 0;
}

int binarySearch(int *p, int n, int key){
  int left=0, right=n, mid;
  
  while(left < right){
    mid = (left+right) / 2;
    if(*(p+mid) == key) return mid;
    else if(key < *(p+mid)) right = mid;
    else left = mid+1;
  }
  return -1;
}

