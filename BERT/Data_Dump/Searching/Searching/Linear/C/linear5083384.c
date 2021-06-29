#include<stdio.h>

int n;
int s[10000];
int search(int);
int main()
{
  int q,i,cnt = 0;
  int t[500];
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
    if(search(t[i]) == 1)cnt++;
  }
  printf("%d\n",cnt);
  return 0;
}

int search(int key)
{
  int i;
  for(i = 0;i < n;i++)
  {
    if(key == s[i])return 1;
  }
  return 0;
}

