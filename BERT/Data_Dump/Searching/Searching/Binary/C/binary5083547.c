#include<stdio.h>

int n;
int s[100000];
int binary(int);
int main()
{
  int q,i,cnt = 0;
  int t[50000];
  scanf("%d",&n);
  for(i = 0;i < n;i++)
  {
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i = 0;i < q;i++)
  {
    scanf("%d",&t[i]);
  }
  for(i = 0; i < q;i++)
  {
    if(binary(t[i]) == 1)cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}

int binary(int key)
{
  int mid;
  int left = 0;
  int right = n;
  while(left < right)
  {
    mid = (left + right) / 2;
    if (s[mid] == key)return 1;
    else if(key < s[mid])right = mid;
    else left = mid + 1;
  }
  return 0;
}

