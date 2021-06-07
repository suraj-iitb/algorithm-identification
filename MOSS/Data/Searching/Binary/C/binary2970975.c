/*二分探索*/
#include <stdio.h>
#define N 100000
#define Q 50000
int main(){
  int s[N], t[Q], n, q, i, count=0;
  int left, right, mid;

  scanf("%d", &n);

  for (i=0; i<n; i++){
    scanf("%d", &s[i]);
  }
  
  scanf("%d", &q);
  
  for (i=0; i<q; i++){
    scanf("%d", &t[i]);
    /*探索*/
    left = 0;
    right =n;
    while (left < right){
      mid = (left + right)/2;
      if (s[mid] == t[i]){
	count++;
	break;
      }
      else if (t[i] < s[mid])
	right = mid;
      else
	left = mid + 1;
    }
    
  }

  printf("%d\n", count);

  return 0;
}

