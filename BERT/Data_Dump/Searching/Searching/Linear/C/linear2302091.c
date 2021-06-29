#include<stdio.h>

int linearSearch(int);

int s[10001], t[500], n;

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
    if(linearSearch(t[i])>=0) count++;
  printf("%d\n",count);

  return 0;
}

int linearSearch(int key)
{
  int i=0;
  s[n]=key;
  while(s[i]!=key){
    i++;
    if(i==n) return -1;
  }
  return i;
}
