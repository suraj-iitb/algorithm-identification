#include <stdio.h>
int binarySearch(int);
int n1,S[100000];
int main()
{
  int i,cnt=0,n2,key;
  scanf("%d",&n1);
  for(i=0;i<n1;i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&n2);
  for(i=0;i<n2;i++)
    {
      scanf("%d",&key);
      if(binarySearch(key))
	cnt++;
    }
  printf("%d\n",cnt);
}
binarySearch(int key)
{
  int left=0,right=n1,mid;
  while(left < right)
    {
      mid = (left + right) / 2;
      if(S[mid] == key)
	return 1;
      if(key > S[mid])
	left = mid + 1;
      else if(key < S[mid])
	right = mid;
    }
  return 0;
}

