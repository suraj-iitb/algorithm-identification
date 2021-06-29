#include <stdio.h>
#define NOT_FOUND 0

int binarysearch(int);
int data[100000], n;

int main()
{
  int a, i, q, key, cnt=0;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&data[i]);
  }
  scanf("%d",&q);
  for(i=0; i<q; i++){
    scanf("%d",&key);
    a=binarysearch(key);
    if(a!=n && a!=NOT_FOUND) cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}

int binarysearch(int key){
  int left, mid, right;
  left=0;
  right=n;
  while(left<right){
    mid=(left+right)/2;
    if(data[mid]==key) return mid;
    if(key<data[mid]) right=mid;
    else if(key>data[mid]) left=mid+1;
  }
  return NOT_FOUND;
}
