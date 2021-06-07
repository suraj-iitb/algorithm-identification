#include <stdio.h>
#define N 100000
#define Q 50000
int main(){
  int S[N], T[Q], n, q, i, cnt=0, left, right, mid, key;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0;i<q;i++)
    scanf("%d",&T[i]);
  for(i=0;i<q;i++){
    key=T[i];
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right)/2;
      if(key == S[mid]){
	cnt++;
	break;
      }
      if(key > S[mid])
	left = mid + 1;
      else if(key < S[mid])
	right = mid;
    }
  }
  printf("%d\n",cnt);
  return 0;
}

