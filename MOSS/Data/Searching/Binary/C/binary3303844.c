#include <stdio.h>

int main()
{
  int n, q, t[1000000], s[1000000];
  int count = 0, i, left, right, mid;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &t[i]);
  }

  
  for(i = 0; i < q; i++){
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;
      if(t[i] == s[mid]){
	count++;
	break;
      }
      else if(t[i] > s[mid]) left = mid + 1;
      else if(t[i] < s[mid]) right = mid;
      else break;
    }
  }
  printf("%d\n", count);
  return 0;
}

