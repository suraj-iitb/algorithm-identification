#include <stdio.h>

#define N 100000
#define Q 50000

int main(){
  int i, j, n, m, a[N], b[Q], f = 0, left, right, mid;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);

  scanf("%d", &m);

  for(i = 0; i < m; i++)
    scanf("%d", &b[i]);

  for(i = 0; i < m; i++){
    left = 0;
    right = n;

    while(left < right){
      mid = (left + right) / 2;
      if(a[mid] == b[i]){
	f++;
	break;
      }

      else if(b[i] < a[mid]){
	right = mid;
	continue;
      }

      else{
	left = mid + 1;
	continue;
      }
    }
  }

  printf("%d\n", f);

  return 0;
}
      

    
    

