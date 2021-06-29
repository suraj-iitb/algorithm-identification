#include <stdio.h>
#define N 100000
#define Q 50000

int main(){
  int n, q, i, j, count = 0, a[N], b[Q], left, right, mid;

  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d", &a[i]);
  }
  scanf("%d", &q);
  for(i = 0;i < q;i++){
    scanf("%d", &b[i]);
  }
  for(i = 0;i < q;i++){
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;
      if(b[i] == a[mid]){
	count++;
	break;
      }
      if(b[i] > a[mid]){
	left = mid + 1;
      }
      else if(b[i] < a[mid]){
	right = mid;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
