#include <stdio.h>
#define N 100000

int binarySearch(int x);

int s[N], t[N], n, q;

int main()
{
  int i, j, c=0;;

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &s[i]);

  scanf("%d", &q);
  for(i=0; i<q; i++)
    scanf("%d", &t[i]);

  
  for(i=0; i<q; i++){
    if(binarySearch(i)!=-1) c++;
  }
  printf("%d\n",c);

  return 0;
}

int binarySearch(int x)
{
  int left = 0, right = n, mid=0;

  while(left<right){
    mid = (left + right) / 2;
    if(s[mid] == t[x]) return mid;
    else if(t[x]<s[mid]) right = mid;
    else left = mid + 1;
  }
  return -1;
}
