#include <stdio.h>
int binarysearch(int*, int);

int n;

int main(){
  int i,j,q, cnt = 0;
 
  scanf("%d", &n);
  int s[n];
  for(i = 0; i < n; i ++)
    scanf("%d", &s[i]);
 
  scanf("%d", &q);
  int t[q];
  for(i = 0; i < q; i ++)
    scanf("%d", &t[i]);

  for(i = 0; i < q; i++)
    cnt += binarysearch(s, t[i]);

  printf("%d\n", cnt);
  return 0;
}

int binarysearch(int *s, int key){
  int left = 0, right = n, mid;
  while(left < right){
    mid = (left + right) / 2;
    if(s[mid] == key)
      return 1;
    else if (key < s[mid])
      right = mid;
    else
      left = mid + 1;
  }
  return 0;
}
