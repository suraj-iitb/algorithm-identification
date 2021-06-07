#include<stdio.h>

int binarySearch(int);

int s[100000], t[50000], n;

int main()
{
  int q, i, count=0;

  scanf("%d",&n);
  for( i=0 ; i<n ; i++ )
    scanf("%d",&s[i]);
  scanf("%d",&q);
  for( i=0 ; i<q ; i++ )
    scanf("%d",&t[i]);

  for( i=0 ; i<q ; i++ )
    if(binarySearch(t[i])>=0) count++;
  printf("%d\n",count);

  return 0;
}

int binarySearch(int key)
{
  int left, right, mid;
  left = 0;
  right = n;
  while(left<right){
    mid = (left+right)/2;
    if(s[mid]==key) return mid;
    else if(key<s[mid]) right = mid;
    else left = mid +1;
  }
  return -1;
}
