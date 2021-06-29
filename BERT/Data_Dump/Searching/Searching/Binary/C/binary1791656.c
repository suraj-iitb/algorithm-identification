#include <stdio.h>

#define N 100000
#define Q 50000

int main(){
  int i,j,S[N],T[Q],n,q,count=0,left,right,mid,key;
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i=0; i<q; i++) scanf("%d",&T[i]);

  for(i=0; i<q; i++){
    left =0;
    right = n;
    while(left < right){
      key = T[i];
      mid = (left + right) / 2;
      if (S[mid] == key) {
	count++;
	break;
      }
      else if(key < S[mid])
	right = mid;
      else left = mid + 1;
    }
  }

  printf("%d\n",count);

  return 0;

}
