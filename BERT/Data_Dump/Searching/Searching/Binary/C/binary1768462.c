#include<stdio.h>

int s[100000];
int n;

int binarySearch(int);

int main()
{
  int q, c=0, i;
  int t[50000];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &t[i]);
  }

  for(i = 0; i < q; i++){
    if(1 == binarySearch(t[i])) c++;
  }

  printf("%d\n", c);

  return 0;
}

int binarySearch(int key)
{
  int left = 0;
  int right = n;
  int mid;
 
  while(left < right){
    mid = (left + right) / 2;
    if(s[mid] == key) return 1;
    else if(key < s[mid]) right = mid;
    else left = mid + 1;
  }
  return 0;
}
