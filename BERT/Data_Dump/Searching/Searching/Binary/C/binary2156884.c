#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n, *s, q, *t, c = 0;
  int i, mid, right, left;

  scanf("%d", &n);
  s = (int *)malloc(sizeof(int) * n);
  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }
  scanf("%d", &q);
  t = (int *)malloc(sizeof(int) * q);
  for(i = 0; i < q; i++){
    scanf("%d", &t[i]);
  }

  for(i = 0; i < q; i++){
    right = n;
    left = 0;
    while(left < right){
      mid = (left + right) / 2;
      if(s[mid] == t[i]){
	c++;
	break;
      }else if(s[mid] > t[i]){
	right = mid;
      }else{
	left = mid+1;
      }
    }
  }
  printf("%d\n", c);
  free(s);
  free(t);
  return 0;
}
